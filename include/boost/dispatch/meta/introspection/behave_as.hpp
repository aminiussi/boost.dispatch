//==================================================================================================
/*!
  @file

  Defines the meta::behave_as meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_INTROSPECTION_BEHAVE_AS_HPP_INCLUDED
#define BOOST_DISPATCH_META_INTROSPECTION_BEHAVE_AS_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/primitive_of.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-meta
    @brief Apply meta-function to a type's Primitive type

    Apply a meta-function to the Primitive type of its input.

    @tparam T         Type to manipulate
    @tparam Function  Meta-function to apply
  **/
  template<typename T, template<class> class Function>
  using behave_as = Function<boost::dispatch::primitive_of<T>>;
} }

#endif
