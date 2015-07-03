//==================================================================================================
/*!
  @file

  Defines the as_floating meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_GENERATION_AS_FLOATING_HPP_INCLUDED
#define BOOST_DISPATCH_META_GENERATION_AS_FLOATING_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <boost/dispatch/meta/generation/make_floating.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  namespace detail
  {
    template<typename T> struct as_floating
    {
      template<typename X> using f_t = typename boost::dispatch::factory_of<T>::template apply<X>;
      using type  = boost::dispatch::make_floating < sizeof(boost::dispatch::primitive_of<T>)
                                                  , f_t
                                                  >;
    };
  }

  /*!
    @ingroup group-meta
    @brief Turn a type into an equivalent floating point type

    Converts any type which Primitive is Fundamental into a floating point type with a compatible
    size .

    @tparam T     Type to convert.
  **/
  template<typename T>
  using as_floating = typename detail::as_floating<typename std::decay<T>::type>::type;
} }

#endif