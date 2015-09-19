//==================================================================================================
/*!
  @file

  Provides the macro performing namespace registration

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//=================================================deaut=================================================
#ifndef BOOST_DISPATCH_FUNCTION_REGISTER_NAMESPACE_HPP_INCLUDED
#define BOOST_DISPATCH_FUNCTION_REGISTER_NAMESPACE_HPP_INCLUDED

#include <boost/dispatch/hierarchy/default_site.hpp>
#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/hierarchy/base.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/utility/result_of.hpp>
#include <boost/config.hpp>
#include <utility>

namespace boost { namespace dispatch
{
  namespace meta { struct adl_helper {}; }

  /*!
    @ingroup group-api
    @brief Error reporting utility dispatcher.

    Whenver a dispatchable function ends up with no suitable overloads, this dispatcher will cause
    a compilation error by producing an incomplete type which type contains the function tag used,
    the architecture hierarchy and the list of types passed as parameters.

    @par Usage:

  **/
  template<typename Tag, typename Site> struct error_
  {
    /// Error inducing information carrier
    template<typename... Call> struct no_such_overload;

    template<typename... Ts>
    BOOST_FORCEINLINE no_such_overload<Tag(Site,Ts...)> operator()(Ts&& ...) const { return {}; }
  };

  namespace meta
  {
    // The 'no luck Sherlock' case returns an incomplete type to emit an informative message
    template<typename F, typename A>
    inline error_<F,A> dispatching(adl_helper const&,function_<F> const&,unspecified_<A> const&,...)
    {
      return {};
    }
  }

  namespace detail
  {
    template<typename Discriminant,typename Tag> struct generic_dispatcher
    {
      // While ICC supports decltype-SFINAE, it causes infinite compilation times in some cases
      #if defined(BOOST_NO_SFINAE_EXPR) || defined(__INTEL_COMPILER)
      template<typename Sig> struct result;
      template<typename This, typename... Args>
      struct result<This(Args...)>
           : boost::result_of
                    < decltype( dispatching ( Discriminant{}, Tag{}, default_site<Tag>{}
                                            , ::boost::dispatch::hierarchy_of<Args&&>()...
                                            )
                              )(Args...)
                    >
      {};

      template<typename... Args>
      BOOST_FORCEINLINE typename result<generic_dispatcher(Args&&...)>::type
      operator()(Args&&... args) const
      {
        return dispatching( Discriminant{}, Tag{}, default_site<Tag>{}
                          , ::boost::dispatch::hierarchy_of<Args&&>()...
                          )
                          ( std::forward<Args>(args)... );
      }
      #else
      template<typename... Args>
      BOOST_FORCEINLINE auto operator()(Args&&... args) const
      BOOST_AUTO_DECLTYPE_BODY_SFINAE
      (
        dispatching ( Discriminant{}, Tag{}, default_site<Tag>{}
                    , ::boost::dispatch::hierarchy_of<Args&&>()...
                    )( std::forward<Args>(args)... )
      );
      #endif
    };
  }

  /// Root generic_dispatcher instance
  template<typename Tag>
  using generic_dispatcher = detail::generic_dispatcher<meta::adl_helper,Tag>;
} }

/*!
  @ingroup group-api

  Make a @c NAMESPACE able to house dispatchable function overloads and to use a @c FALLBAKC
  namespace if the current one fails to provide any viable overload.

  @param NAMESPACE  Namespace name to be registered
  @param FALLBACK   Namespace to use in fallback situations
**/
#define BOOST_DISPATCH_REGISTER_NAMESPACE(NAMESPACE, FALLBACK)                                      \
namespace NAMESPACE                                                                                 \
{                                                                                                   \
  struct adl_helper {};                                                                             \
                                                                                                    \
  template<typename Tag, typename Site>                                                             \
  inline FALLBACK::generic_dispatcher<Tag>                                                          \
  dispatching ( adl_helper const&, ::boost::dispatch::function_<Tag> const&                         \
              , ::boost::dispatch::unspecified_<Site> const&, ...                                   \
              )                                                                                     \
  {                                                                                                 \
    return {};                                                                                      \
  }                                                                                                 \
}                                                                                                   \
template<typename Tag>                                                                              \
using generic_dispatcher = ::boost::dispatch::detail::generic_dispatcher<NAMESPACE::adl_helper,Tag> \
/**/

#endif
