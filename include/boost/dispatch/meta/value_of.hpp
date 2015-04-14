//==================================================================================================
/*!
  @file

  Defines the value_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_VALUE_OF_HPP_INCLUDED

#include <boost/dispatch/config.hpp>
#include <boost/dispatch/meta/details/value_of.hpp>

namespace boost { namespace dispatch { namespace meta
{
  /*!
    @ingroup group-meta
    @brief Underlying type evaluation

    Evaluates, for any given type @c T, the underlying type of @c T.

    @par Models:

    @metafunction

    @par Semantic:

    For any type @c T,

    @code
    using result_t = meta::value_of<T>::type;
    @endcode

    is defined so that

    @code
    std::is_same<T, mpl::apply<meta::model_of<T>::type,result_t>::type>::type
    @endcode

    evaluates to @true_ .

    @tparam T Type to analyze
   **/
  template<class T> struct  value_of          : ext::value_of<T>          {};
  template<class T> struct  value_of<T&>      : ext::value_of_cv<T&>      {};
  template<class T> struct  value_of<T const> : ext::value_of_cv<T const> {};

#ifndef BOOST_NO_RESTRICT_REFERENCES
  template<class T> struct  value_of<T& BOOST_RESTRICT> : ext::value_of_cv<T&> {};
#endif
} } }

# endif
