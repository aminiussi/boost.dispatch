//==================================================================================================
/*!
  @file

  Defines the property_of metafunction

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_PROPERTY_OF_HPP_INCLUDED
#define BOOST_DISPATCH_PROPERTY_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/scalar_of.hpp>
#include <boost/dispatch/detail/property_of.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-meta
    @brief Retrieve the fundamental hierarchy of a Type

    For any type @c T, returns the hierarchy describing the fundamental properties of any given
    types. This Fundamental Hierarchy is computed by computing the hierarchy of the innermost
    embedded scalar type of @c T.

    @tparam T     Type to categorize
    @tparam ORigin

    @par Models:

    @metafunction

    @par Semantic:

  **/
  template<typename T, typename Origin = T>
  using property_of = typename ext::property_of < scalar_of<T>
                                                , typename std::remove_reference<Origin>::type
                                                >::type;
} }

#endif
