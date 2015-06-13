//==================================================================================================
/*!
  @file

  Defines various macro for compiler-dependent attributes

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_CONFIG_HPP_INCLUDED
#define BOOST_CONFIG_HPP_INCLUDED

#include <boost/config.hpp>

#if defined(__GNUC__)
#define BOOST_RESTRICT __restrict__
#elif defined(_MSC_VER)
#define BOOST_RESTRICT __restrict
#else
/*!
  @ingroup group-detail
  @brief Mark a pointer or reference as restricted

  This macro expands to a potential compiler specific parameters attribute
  indicating that a given pointer or reference is not aliasing any other pointer
  or reference.

  @par Usage:

  @code
  void* BOOST_RESTRICT ptr = malloc(1337);
  @endcode

  @see BOOST_NO_RESTRICT_REFERENCES
**/
#define BOOST_RESTRICT

/*!
  @ingroup group-detail
  @brief Notify of compiler's inability to provide restrict keyword
**/
#define BOOST_NO_RESTRICT
#endif

#if defined(BOOST_NO_RESTRICT) || defined(_MSC_VER) || defined(DOXYGEN_ONLY)
/*!
  @ingroup group-detail
  @brief Notify of compiler's inability to support restrict keyword for reference

  @see BOOST_RESTRICT
**/
#define BOOST_NO_RESTRICT_REFERENCES
#endif

#endif
