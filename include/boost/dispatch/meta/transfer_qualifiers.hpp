//==================================================================================================
/*!
  @file

  Defines the meta::transfer_qualifiers meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_TRANSFER_QUALIFIERS_HPP_INCLUDED
#define BOOST_DISPATCH_META_TRANSFER_QUALIFIERS_HPP_INCLUDED

#include <type_traits>

namespace boost { namespace dispatch { namespace meta
{
  template<class T, class U>
  struct transfer_qualifiers
  {
    typedef T type;
  };

  template<class T, class U>
  struct transfer_qualifiers<T, U&&> : std::add_rvalue_reference<T> {};

  template<class T, class U>
  struct transfer_qualifiers<T, U&> : std::add_lvalue_reference<T> {};

  template<class T, class U>
  struct transfer_qualifiers<T, U const> : std::add_const<T> {};

  template<class T, class U>
  struct  transfer_qualifiers<T, U const&>
        : std::add_lvalue_reference<typename std::add_const<T>::type>
  {};
} } }

#endif
