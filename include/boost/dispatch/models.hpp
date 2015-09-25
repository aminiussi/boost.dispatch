//==================================================================================================
/*!
  @file

  Defines the models metafunction

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_MODELS_HPP_INCLUDED
#define BOOST_DISPATCH_MODELS_HPP_INCLUDED

#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename T, typename Hierarchy> struct models
    {
      template<typename U> using hierarchy_t  = brigand::apply<Hierarchy,U>;

      template<typename U> static std::true_type  test( hierarchy_t<U> );
      template<typename  > static std::false_type test( ... );

      using type = typename std::is_same< decltype(test<T>( boost::dispatch::hierarchy_of_t<T>{} ) )
                                        , std::true_type
                                        >::type;
    };
  }

  /*!
    @ingroup group-meta
    @brief Checks if a Type models a Hierarchy

    A type @c T models a @c Hierarchy if and only if @c Hierarchy<T> is present in
    @c T hierarchy inheritance tree.

    @tparam T         Type to check for
    @tparam Hierarchy Hierarchy @c T must model
  **/
  template<typename T, typename Hierarchy>
  struct models : detail::models<T,Hierarchy>
  {};

  /// Eager short-cut for models
  template<typename T, typename Hierarchy>
  using models_t = typename models<T,Hierarchy>::type;
} }

#endif
