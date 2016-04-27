//==================================================================================================
/*!
  @file

  Defines the exactly_ matcher

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_EXACTLY_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_EXACTLY_HPP_INCLUDED

#include <boost/dispatch/hierarchy_of.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-tag
    @brief Exact type hierarchy matcher

    Generate the hierarchy matching any type @c T exactly.

    @tparam T Type to match
  **/
  template<typename T> using exactly_ = ::boost::dispatch::hierarchy_of_t<T>;
} }

#endif
