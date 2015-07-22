//==================================================================================================
/*!
  @file
  @ingroup group-adapted

  Adapt std::integral_constant to be hierarchizable

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_STD_INTEGRAL_CONSTANT_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_STD_INTEGRAL_CONSTANT_HPP_INCLUDED

#include <array>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T, T N> struct model_of<std::integral_constant<T,N>>
    {
      template<typename X> using apply = std::integral_constant<X,X(N)>;
    };

    template<typename T, T N> struct value_of<std::integral_constant<T,N>>
    {
      using type = T;
    };
  }
} }

#endif
