//==================================================================================================
/*!
  @file

  Defines the make_integer meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_MAKE_INTEGER_HPP_INCLUDED
#define BOOST_DISPATCH_META_MAKE_INTEGER_HPP_INCLUDED

#include <boost/dispatch/detail/brigand/functions/identity.hpp>
#include <boost/dispatch/detail/brigand/types/no_such_type.hpp>
#include <cstdint>
#include <cstddef>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template< std::size_t Size, typename Sign, template<class> class Transform>
    struct  make_integer
    {
      static_assert ( Size >= sizeof(std::int8_t) && Size <= sizeof(std::int64_t)
                    , "boost::dispatch::make_integer: can't generate type of given Size"
                    );

      using type = brigand::no_such_type_;
    };

    template<template<class> class Transform>
    struct make_integer<1u, unsigned, Transform>
    {
      using type = Transform<std::uint8_t>;
    };

    template<template<class> class Transform>
    struct make_integer<2u, unsigned, Transform>
    {
      using type = Transform<std::uint16_t>;
    };

    template<template<class> class Transform>
    struct make_integer<4u, unsigned, Transform>
    {
      using type = Transform<std::uint32_t>;
    };

    template<template<class> class Transform>
    struct make_integer<8u, unsigned, Transform>
    {
      using type = Transform<std::uint64_t>;
    };

    template<template<class> class Transform>
    struct make_integer<1u, signed, Transform>
    {
      using type = Transform<std::int8_t>;
    };

    template<template<class> class Transform>
    struct make_integer<2u, signed, Transform>
    {
      using type = Transform<std::int16_t>;
    };

    template<template<class> class Transform>
    struct make_integer<4u, signed, Transform>
    {
      using type = Transform<std::int32_t>;
    };

    template<template<class> class Transform>
    struct make_integer<8u, signed, Transform>
    {
      using type = Transform<std::int64_t>;
    };
  }

  /*!
    @ingroup group-meta
    @brief Generate an integer type of a given size and sign

    For any given Size corresponding to a valid integer type and an optional Sign,
    return said type optionally transformed by a user-defined unary meta-function.

    @tparam Size      Size in bytes of the requested type
    @tparam Sign      Optional sign (unsigned by default) of the requested type.
    @tparam Transform Optional unary meta-function to apply to the generated type
  **/
  template< std::size_t Size
          , class Sign                      = unsigned
          , template<class> class Transform = brigand::identity
          >
  using make_integer = typename detail::make_integer<Size,Sign,Transform>::type;
} }

#endif
