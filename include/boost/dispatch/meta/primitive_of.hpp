//==================================================================================================
/*!
  @file

  Defines the meta::primitive_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_PRIMITIVE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_PRIMITIVE_OF_HPP_INCLUDED

#include <boost/dispatch/meta/details/primitive_of.hpp>

namespace boost { namespace dispatch{  namespace meta
{
  /*!
    @ingroup group-meta
    @brief Primitive type computation

    For any given type @c T, returns the primitive type, i.e the most underlying type of @c T.

    @tparam Type to extract a primitive from.

    @par Models:

    @metafunction

    @par Semantic:
    For a given type T,

    @code
    using type = boost::dispatch::meta::primitive_of<T>::type;
    @endcode

    is defined so that :

    @code
    std::is_same<type, boost::dispatch::meta::value_of<type>::type>::value
    @endcode

    evaluates to @c true.

    Put in another way, meta::primitive_of is a recursive application of meta::value_of so
    that every nested type are traversed to find the most underlying type of @c T.

    @see value_of
    @see model_of
  **/
  template<typename T>
  struct primitive_of : detail::primitive_of<typename value_of<T>::type, T>
  {};

  /*!
    @ingroup group-meta
    @brief C++14 style short-cut for meta::primitive_of
  **/
  template<typename T>
  using primitive_of_t = typename meta::primitive_of<T>::type;
} } }

#endif
