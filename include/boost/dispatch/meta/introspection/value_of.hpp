//==================================================================================================
/*!
  @file

  Defines the value_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_VALUE_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_VALUE_OF_HPP_INCLUDED

#include <boost/dispatch/config.hpp>

namespace boost { namespace dispatch
{
  namespace detail { template<typename T> struct  value_of; }

  /*!
    @ingroup group-meta
    @brief Underlying type evaluation

    Evaluates, for any given type @c T, the underlying type of @c T.

    @par Models:

    @metafunction

    @par Semantic:

    For any type @c T,

    @code
    using U = value_of<T>;
    @endcode

    is defined so that

    @code
    std::is_same<T, meta::model_of<T>::type<U>>::type
    @endcode

    evaluates to @true_ .

    @par Extension Point:

    meta::value_of can be specialized for user-defined types by either overloading or specializing
    (eventually through SFINAE) the ext::value_of and/or ext::value_of_cv classes

    Specialization for value_of are provided for most of standard and
    Boost types. See the @ref group-adapted page.

    @tparam T Type to analyze
  **/
  template<typename T>
  using value_of = typename detail::value_of<T>::type;
} }

#include <boost/dispatch/meta/introspection/detail/value_of.hpp>

#endif
