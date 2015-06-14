//==================================================================================================
/*!
  @file

  Defines the meta::model_of meta-function extension point

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_DETAIL_MODEL_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_DETAIL_MODEL_OF_HPP_INCLUDED

namespace boost { namespace dispatch { namespace ext
{
  /*!
    @ingroup group-extension
    @brief SFINAE-enabled extension point for meta::model_of

    This extension point allows customization of the meta::model_of @metafunction
    by letting user defined SFINAE-enabled context in which they can specialize
    meta::model_of for family of types

    @par Usage:

    @tparam T       Type to build a Model @metafunction from
    @tparam Enable  SFINAE condition to be specified
  **/
  template<typename T, typename Enable = void>
  struct model_of
  {
    template<typename X> using type = X;
  };

  // Specialize for all Template<Type> like class
  template<template<class> class Template, typename Type>
  struct model_of<Template<Type>>
  {
    template<typename X> using type = Template<X>;
  };
} } }

#endif