//==================================================================================================
/*!
  @file

  Defines the scalar_ hierarchy

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_HIERARCHY_GENERIC_HPP_INCLUDED
#define BOOST_DISPATCH_META_HIERARCHY_GENERIC_HPP_INCLUDED

#include <boost/dispatch/hierarchy/unspecified.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-hierarchy
    @brief Generic types hierarchy tag

    The generc_ hierarchy represents types which values are stored any kind of registers.
    Its main use is to serve as a fall-back for function having similar code independently of the
    underlying architecture.

    @tparam Hierarchy Type hierarchy
  **/
  template<typename Hierarchy>
  struct generic_ : generic_<typename Hierarchy::parent>
  {
    using parent = generic_<typename Hierarchy::parent>;
  };

  // TODO: When hitting unspecified_, devolves to higher order hierarchy before unspecified
  template<typename Type>
  struct generic_< unspecified_<Type> > : unspecified_<Type>
  {
    using parent = unspecified_<Type>;
  };
} }

#endif
