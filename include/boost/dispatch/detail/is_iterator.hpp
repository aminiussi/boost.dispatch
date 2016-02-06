//==================================================================================================
/*!
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_DETAIL_IS_ITERATOR_HPP_INCLUDED
#define BOOST_DISPATCH_META_DETAIL_IS_ITERATOR_HPP_INCLUDED

#include <boost/dispatch/detail/brigand.hpp>
#include <boost/dispatch/detail/is_pointer.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<typename T, typename EnableIf = void > struct is_iterator : std::false_type {};

  template<typename T>
  struct is_iterator<T, typename boost::enable_if_has_type<typename T::iterator_category>::type>
       : std::true_type
  {};
} } }

#endif
