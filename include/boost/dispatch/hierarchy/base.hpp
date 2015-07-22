//==================================================================================================
/*!
  @file

  Defines the basic hierarchies

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_HIERARCHY_BASE_HPP_INCLUDED
#define BOOST_DISPATCH_HIERARCHY_BASE_HPP_INCLUDED

namespace boost { namespace dispatch
{
  // Tag used to detect if a type is a hierarchy
  namespace detail { struct hierarchy_tag {}; }

  /*!
    @ingroup group-hierarchy
    @brief Root type hierarchy tag

    The type_ hierarchy classify type related informations.
  **/
  template<typename T> struct type_
  {
    using type          =  T;
    using parent        =  type_;
    using hierarchy_tag =  detail::hierarchy_tag;
  };

  /*!
    @ingroup group-hierarchy
    @brief Root hardware hierarchy tag

    The architecture_ hierarchy classify hardware related informations.
  **/
  template<typename T> struct architecture_
  {
    using type          =  T;
    using parent        =  architecture_;
    using hierarchy_tag =  detail::hierarchy_tag;
  };
} }

#endif
