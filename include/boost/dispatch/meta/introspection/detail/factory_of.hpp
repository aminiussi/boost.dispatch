//==================================================================================================
/*!
  @file

  Defines the meta::factory_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_DETAIL_FACTORY_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_DETAIL_FACTORY_OF_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>

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
} } }

#endif
