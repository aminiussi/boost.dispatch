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
#include <boost/preprocessor/tuple/rem.hpp>
#include <boost/config.hpp>

/*!
  @ingroup group-function

  Provides the name of the dispatching function for a given @c TAG

  @param TAG Tag of the function to dispatch
**/
#define BOOST_DISPATCH_DISPATCHING_FUNCTION(TAG) BOOST_PP_CAT(dispatching_, TAG)

/*!
  @ingroup group-function
**/
#define BOOST_DISPATCH_IMPLEMENTS(TAG, ...)                                                         \
BOOST_DISPATCH_DISPATCHING_FUNCTION(TAG)( adl_helper const&, __VA_ARGS__)                           \

/*!
  @ingroup group-function
**/
#define BOOST_DISPATCH_FALLBACK(...) dispatching( adl_helper const&, __VA_ARGS__) BOOST_NOEXCEPT

/*!
  @ingroup group-function
**/
#define BOOST_DISPATCH_OVERLOAD(TAG, TEMPLATES, ... )                                               \
template<BOOST_PP_TUPLE_REM_CTOR(TEMPLATES)>                                                        \
BOOST_PP_CAT(impl_,TAG)<__VA_ARGS__>                                                                \
BOOST_DISPATCH_IMPLEMENTS(TAG,__VA_ARGS__) BOOST_NOEXCEPT { return {}; }                            \
template<BOOST_PP_TUPLE_REM_CTOR(TEMPLATES)> struct BOOST_PP_CAT(impl_,TAG)<__VA_ARGS__>            \
/**/

/*!
  @ingroup group-function
**/
#define BOOST_DISPATCH_OVERLOAD_FALLBACK( TEMPLATES, ... )                                          \
template<typename... Specifications> struct impl_fallback;                                          \
template<BOOST_PP_TUPLE_REM_CTOR(TEMPLATES)>                                                        \
impl_fallback<__VA_ARGS__>                                                                          \
dispatching( adl_helper const&, __VA_ARGS__) BOOST_NOEXCEPT { return {}; }                          \
template<BOOST_PP_TUPLE_REM_CTOR(TEMPLATES)> struct impl_fallback<__VA_ARGS__>                      \
/**/

#endif
