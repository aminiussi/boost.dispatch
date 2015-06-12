//==================================================================================================
/*!
  @file

  Defines the meta::factory_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_FACTORY_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_FACTORY_OF_HPP_INCLUDED

#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/primitive_of.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<typename T, typename U> struct factory_of
  {
    using v_t = boost::dispatch::value_of_t<T>;

    template<typename X>
    using f_t = typename detail::factory_of<v_t,U>::template type<X>;

    template<typename X>
    using type = typename dispatch::meta::model_of<T>::template type<f_t<X>>;
  };

  template<typename T> struct factory_of<T, T>
  {
    template<typename X> using type = X;
  };
}

namespace meta
{
  /*!
    @ingroup group-meta

    @brief Recursive meta-model generator

    For any type @c T, returns a @mpllambda able to reconstruct @c T using a different primitive
    type.

    @tparam T     Type to build a type-factory of
    @tparam Limit

    @par Models:

    @metafunction

    @par Semantic:

    For any type @c T:

    @code
    using type = boost::dispatch::meta::factory_of<T>::type;
    @endcode

    return a template alias so that, for any type @c U:

    @code
    using X = type<U>;
    @endcode

    generates a type @c X so that:

    @code
    std::is_same<boost::dispatch::primitive_of_t<X>, U>::value
    @endcode

    and for which the boost::dispatch::meta::model_of template aliases are equivalent.

    Put in another way, boost::dispatch::meta::factory_of is a recursive application of
    boost::dispatch::meta::model_of so that every nested type are traversed during reconstruction.

    @see primitive_of
    @see model_of
  **/
  template< typename T
          , typename Limit = typename meta::primitive_of<T>::type
          >
  struct factory_of : detail::factory_of<T, Limit>
  {};
} } }

#endif
