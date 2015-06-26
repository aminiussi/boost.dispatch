//==================================================================================================
/*!
  @file
  @ingroup group-adapted

  Adapt boost::array to be hierarchizable

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_BOOST_ARRAY_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_BOOST_ARRAY_HPP_INCLUDED

#include <boost/array.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T, std::size_t N> struct model_of<boost::array<T,N>>
    {
      template<typename X> using make = boost::array<X,N>;
    };

    template<typename T, std::size_t N> struct value_of<boost::array<T,N>>
    {
      using type = T;
    };
  }
} }

#endif
