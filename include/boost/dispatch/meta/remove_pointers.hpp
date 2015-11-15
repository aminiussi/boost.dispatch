//==================================================================================================
/*!
  @file

  Defines the remove_pointers meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_REMOVE_POINTERS_HPP_INCLUDED
#define BOOST_DISPATCH_META_REMOVE_POINTERS_HPP_INCLUDED

namespace boost { namespace dispatch
{
  template<typename T> struct remove_pointers                               { using type = T; };
  template<typename T> struct remove_pointers<T*>     : remove_pointers<T>  {};
  template<typename T> struct remove_pointers<T**>    : remove_pointers<T>  {};
  template<typename T> struct remove_pointers<T***>   : remove_pointers<T>  {};
  template<typename T> struct remove_pointers<T****>  : remove_pointers<T>  {};
  template<typename T> struct remove_pointers<T*****> : remove_pointers<T>  {};
} }

#endif
