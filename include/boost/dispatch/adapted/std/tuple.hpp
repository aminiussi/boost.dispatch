//==================================================================================================
/*!
  @file
  @ingroup group-adapted

  Adapt std::tuple to be hierarchizable

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_STD_TUPLE_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_STD_TUPLE_HPP_INCLUDED

#include <tuple>
#include <boost/dispatch/adapted/hierarchy/tuple.hpp>
#include <boost/dispatch/meta/introspection/is_homogeneous.hpp>
#include <boost/fusion/include/std_tuple.hpp>
#include <boost/dispatch/hierarchy_of.hpp>

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T, typename... Ts, typename Origin>
    struct hierarchy_of < std::tuple<T,Ts...>,Origin
                        , typename std::enable_if<is_homogeneous<std::tuple<T,Ts...>>::value>::type
                        >
    {
      using type = bag_ < boost::dispatch::property_of<T,Origin>
                        , std::integral_constant<std::size_t, 1u+sizeof...(Ts)>
                        >;
    };

    template<typename T, typename... Ts, typename Origin>
    struct hierarchy_of < std::tuple<T,Ts...>,Origin
                        , typename std::enable_if<!is_homogeneous<std::tuple<T,Ts...>>::value>::type
                        >
    {
      using type = tuple_<Origin, std::integral_constant<std::size_t, 1u+sizeof...(Ts)>>;
    };

    template<typename Origin>
    struct hierarchy_of<std::tuple<>,Origin>
    {
      using type = tuple_<Origin, std::integral_constant<std::size_t,0u>>;
    };
  }
} }

#endif
