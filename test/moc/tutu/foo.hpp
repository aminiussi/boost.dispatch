//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef TUTU_FOO_INCLUDED
#define TUTU_FOO_INCLUDED

#include <boost/dispatch/function/callable_object.hpp>
#include "moc/tutu.hpp"

namespace boost { namespace dispatch
{
  template<typename T, typename Site = boost::dispatch::default_site<T>>
  struct functor
  {
    template<typename Other> using rebind = functor<T,Other>;

    template<typename OtherSite, typename... Args>
    BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE on(Args&&... args) const
    BOOST_AUTO_DECLTYPE_BODY( T::dispatch_to( OtherSite()
                                            , boost::dispatch::hierarchy_of<Args>()...
                                            )( std::forward<Args>(args)...)
                            )

    template<typename... Args>
    BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE operator()(Args&&... args) const
    BOOST_AUTO_DECLTYPE_BODY( T::dispatch_to( Site()
                                            , boost::dispatch::hierarchy_of<Args>()...
                                            )( std::forward<Args>(args)...)
                            )
  };
} }

namespace tutu { namespace titi
{
  namespace tag
  {
    struct foo_ : boost::dispatch::function_<foo_>
    {
      BOOST_DISPATCH_CALLABLE_OBJECT(foo_,boost::dispatch::function_<foo_>);
    };
  }

  namespace ext
  {
    template<typename T> struct impl_foo;

    template<typename Site, typename... Ts>
    BOOST_FORCEINLINE generic_dispatcher<tag::foo_, Site>
    BOOST_DISPATCH_DISPATCHING_FUNCTION(foo)
    (adl_helper const&, Site const&, boost::dispatch::type_<Ts> const&...)
    {
      return {};
    }
  }

  static const boost::dispatch::functor<tag::foo_> foo = {};
} }

#include "moc/arch/default/foo.hpp"
#include "moc/arch/tutu/foo.hpp"
#include "moc/arch/toto/foo.hpp"

#endif
