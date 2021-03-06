//==================================================================================================
/*!
  @file

  Defines the meta::primitive_of meta-function implementation details

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_DETAIL_PRIMITIVE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_DETAIL_PRIMITIVE_OF_HPP_INCLUDED

#include <boost/dispatch/meta/value_of.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<class T, class Origin> struct primitive_of
  {
    using type = typename detail::primitive_of<boost::dispatch::value_of_t<T>, T>::type;
  };

  template<class T> struct primitive_of<T, T>
  {
    using type = T;
  };
} } }

#endif
