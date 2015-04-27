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
    using type = primitive_of<T>::type;
    @endcode

    is defined so that :

    @code
    is_same<type, value_of<type>::type>::value
    @endcode

    evaluates to @c true.
  **/
  template<typename T>
  struct primitive_of : detail::primitive_of<typename value_of<T>::type, T>
  {};

} } }

#endif
