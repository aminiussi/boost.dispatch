//==================================================================================================
/*!
  @file

  Defines the meta::model_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_MODEL_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_MODEL_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/detail/model_of.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-meta
    @brief Model generator meta-function

    Build, for any given type @c T, a @metafunction which can reconstruct a new type @c U similar
    to @c T but by using a different underlying type.

    @par Models:

    @metafunction

    @par Semantic:

    For any type @c T,

    @code
    model_of<T>::make;
    @endcode

    defines a template alias so that:

    @code
    std::is_same<model_of<T>::make<value_of<T>>, T>::value
    @endcode

    evaluates to @c true.

    @par Extension Point:

    meta::model_of can be specialized for user-defined types by either overloading or by
    specializing (eventually through SFINAE) the ext::model_of class

    Specialization for model_of are provided for most of standard and
    Boost types. See the @ref group-adapted page.

    @tparam T Type to turn into a generator @metafunction
  **/
  template<typename T> struct model_of            : ext::model_of<T>  {};
  template<typename T> struct model_of<T&>        : model_of<T>       {};
  template<typename T> struct model_of<T&&>       : model_of<T>       {};
  template<typename T> struct model_of<T const>   : model_of<T>       {};
} }

#endif
