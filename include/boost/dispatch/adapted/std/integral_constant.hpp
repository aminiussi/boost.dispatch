//==================================================================================================
/*!
  @file
  @ingroup group-adapted

  Adapt std::integral_constant to be hierarchizable

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_STD_INTEGRAL_CONSTANT_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_STD_INTEGRAL_CONSTANT_HPP_INCLUDED

#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <type_traits>

namespace boost { namespace dispatch
{
  // model/value_of adaptation
  namespace ext
  {
    template<typename T, T N> struct model_of<std::integral_constant<T,N>>
    {
      template<typename X> using apply = std::integral_constant<X,X(N)>;
    };

    template<typename T, T N> struct value_of<std::integral_constant<T,N>>
    {
      using type = T;
    };
  }

  /*!
    @ingroup group-hierarchy
    @brief integral constant type hierarchy tag

    Types are classified as constant_ if they are type embedding a integral constant.

    @note When reaching @c constant_<unspecified_<T>> , the hierarchy turns into
    @c scalar_<integral_<T>> and evolves accordingly.

    @tparam T Base hierarchy
  **/
  template<typename T> struct constant_ : constant_<typename T::parent>
  {
    using parent = constant_<typename T::parent>;
  };

  template<typename T>
  struct  constant_< unspecified_<T> > : hierarchy_of< typename T::value_type >
  {
    using parent = hierarchy_of< typename T::value_type, T >;
  };

  namespace ext
  {
    // integral_constant<T,N> hierarchies as constant_< (u)int{8,16,32,64}<Origin> >
    template<typename T, T N, typename Origin>
    struct hierarchy_of<std::integral_constant<T,N>,Origin>
    {
      using type = constant_< boost::dispatch::property_of<T,Origin> >;
    };
  }

} }

#endif
