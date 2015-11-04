//==================================================================================================
/*!
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_DETAIL_IS_POINTER_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_DETAIL_IS_POINTER_HPP_INCLUDED

#include <type_traits>
#include <boost/dispatch/detail/brigand.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<typename T>
  struct  is_pointer
        : brigand::bool_<   std::is_pointer<T>::value
                        && !std::is_function<typename std::remove_pointer<T>::type>::value
                        >
  {};
} } }

#endif