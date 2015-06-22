//==================================================================================================
/*!
  @file

  Defines the meta::make_floating meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_MAKE_FLOATING_HPP_INCLUDED
#define BOOST_DISPATCH_META_MAKE_FLOATING_HPP_INCLUDED

#include <boost/dispatch/detail/brigand/functions/identity.hpp>
#include <cstddef>

namespace boost { namespace dispatch
{
  namespace meta
  {
    /*!
      @ingroup group-meta
      @brief Generate a floating point type of a given size

      For any given Size corresponding to a valid floating point type, return said type optionally
      transformed by a user-defined unary meta-function.

      @tparam Size      Size in bytes of the requested type
      @tparam Transform Optional unary meta-function to apply to the generated type
    **/
    template< std::size_t Size
            , template<class> class Transform = brigand::identity
            >
    struct  make_floating
    {
      static_assert ( Size == sizeof(float) || Size == sizeof(double)
                    , "boost::dispatch::meta:make_floating: can't generate type of given Size"
                    );
    };

    template<template<class> class Transform>
    struct make_floating<sizeof(double),Transform>
    {
      using type = Transform<double>;
    };

    template<template<class> class Transform>
    struct make_floating<sizeof(float),Transform>
    {
      using type = Transform<float>;
    };
  }

  /*!
    @ingroup group-meta
    @brief C++14 style short-cut for meta::make_floating
  **/
  template<std::size_t Size, template<class> class Transform = brigand::identity>
  using make_floating_t = typename meta::make_floating<Size,Transform>::type;
} }

#endif
