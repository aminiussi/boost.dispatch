//==================================================================================================
/*!
  @file
  @ingroup group-adapted

  Adapt std::array to be hierarchizable

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_STD_ARRAY_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_STD_ARRAY_HPP_INCLUDED

#include <array>

namespace boost { namespace dispatch { namespace meta
{
  template<typename T> struct model_of;
  template<typename T> struct value_of;

  template<typename T, std::size_t N> struct model_of<std::array<T,N>>
  {
    template<typename X> using type = std::array<X,N>;
  };

  template<typename T, std::size_t N> struct value_of<std::array<T,N>>
  {
    using type = T;
  };
} } }

#endif
