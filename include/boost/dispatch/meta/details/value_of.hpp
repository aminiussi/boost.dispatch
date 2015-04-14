//==================================================================================================
/*!
  @file

  Defines the value_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_DETAILS_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_DETAILS_VALUE_OF_HPP_INCLUDED

#include <boost/dispatch/details/type_traits.hpp>

namespace boost { namespace dispatch
{
  // Forward declaration
  namespace meta { template<class T> struct value_of; }

  namespace ext
  {
    template<class T, class Enable = void>
    struct value_of
    {
      typedef T type;
    };

    template<class T, class Enable = void>
    struct value_of_cv;

    template<class T, class Enable>
    struct value_of_cv<T const, Enable>
         : std::add_const<typename meta::value_of<T>::type>
    {};

    template<class T, class Enable>
    struct value_of_cv<T&, Enable>
         : std::add_lvalue_reference<typename meta::value_of<T>::type>
    {};

    template<class T, class Enable>
    struct value_of_cv<T&&, Enable>
         : std::add_rvalue_reference<typename meta::value_of<T>::type>
    {};
  }
} }

#endif
