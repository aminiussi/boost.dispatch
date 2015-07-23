//==================================================================================================
/*!
  @file

  Defines the scalar_ hierarchy

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_HIERARCHY_SCALAR_HPP_INCLUDED
#define BOOST_DISPATCH_META_HIERARCHY_SCALAR_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Scalar types hierarchy tag

    The scalar_ hierarchy represents types which values are stored in one or multiple general
    purpose registers.

    @tparam Hierarchy Type hierarchy
  **/
  template<typename Hierarchy>
  struct scalar_ : scalar_<typename Hierarchy::parent>
  {
    using parent = scalar_<typename Hierarchy::parent>;
  };

  // When hitting unspecified_, behaves as a generic_ type
  template<typename Type>
  struct scalar_< unspecified_<Type> > : unspecified_<Type>
  {
    using parent = unspecified_<Type>;
  };
} }

#endif
