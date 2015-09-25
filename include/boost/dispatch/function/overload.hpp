//==================================================================================================
/*!
  @file

  Provides macros for function overload definition and declaration

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_FUNCTION_OVERLOAD_HPP_INCLUDED
#define BOOST_DISPATCH_FUNCTION_OVERLOAD_HPP_INCLUDED

#include <boost/preprocessor/cat.hpp>

/*!
  @ingroup group-api

  Provides the name of the dispatching function for a given @c TAG

  @param TAG Tag of the function to dispatch
**/
#define BOOST_DISPATCH_DISPATCHING_FUNCTION(TAG) BOOST_PP_CAT(dispatching_, TAG)

/*!

**/
#define BOOST_DISPATCH_IMPLEMENTS(TAG, ...)                                                         \
BOOST_DISPATCH_DISPATCHING_FUNCTION(TAG)( adl_helper const&, __VA_ARGS__)                           \

/*!

**/
#define BOOST_DISPATCH_FALLBACK(...) dispatching( adl_helper const&, __VA_ARGS__)

#endif
