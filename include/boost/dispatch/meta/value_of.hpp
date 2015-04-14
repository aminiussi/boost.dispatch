//==================================================================================================
/*!
  @file

  Defines the value_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED

#include <boost/dispatch/config.hpp>
#include <boost/dispatch/meta/details/value_of.hpp>

namespace boost { namespace dispatch { namespace meta
{
  /*!
   **/
  template<class T> struct  value_of          : ext::value_of<T> {};
  template<class T> struct  value_of<T&>      : ext::value_of_cv<T&>  {};
  template<class T> struct  value_of<T const> : ext::value_of_cv<T const> {};

#ifndef BOOST_NO_RESTRICT_REFERENCES
  template<class T> struct  value_of<T& BOOST_RESTRICT> : ext::value_of_cv<T&> {};
#endif
} } }

# endif
