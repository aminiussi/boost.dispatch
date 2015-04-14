//==================================================================================================
/*!
  @file

  Defines the meta::model_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_MODEL_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_MODEL_OF_HPP_INCLUDED

#include <boost/mpl/apply.hpp>
#include <boost/dispatch/meta/details/model_of.hpp>

namespace boost { namespace dispatch
{
  namespace meta
  {
    /*!
      @ingroup group-meta
      @brief Model generator meta-function

      Build, for any given type @c T, a @metafunction which can reconstruct a new type @c U similar
      to @c T but by using a different underlying type.

      @par Models:

      @metafunction

      @par Semantic:

      @par Usage:

      @par Extension Point:

      meta::model_of can be specialized for user-defined types by either:

        - Directly overloading the meta::model_of class for a given type
        - Specialize (eventually through SFINAE) the ext::model_of class

      @tparam T Type to build a Model @metafunction from
    **/
    template<typename T> struct model_of            : ext::model_of<T>  {};
    template<typename T> struct model_of<T&>        : model_of<T>       {};
    template<typename T> struct model_of<T&&>       : model_of<T>       {};
    template<typename T> struct model_of<T const>   : model_of<T>       {};
  }

  /*!
    @ingroup group-meta
    @brief C++14 style short-cut for meta::model_of
  **/
  template<typename T>
  using model_of_t = typename meta::model_of<T>::type;
} }

#endif
