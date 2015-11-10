//==================================================================================================
/*!
  @file

  Defines the pointer_ hierarchy

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_ADAPTED_HIERARCHY_POINTER_HPP_INCLUDED
#define BOOST_DISPATCH_ADAPTED_HIERARCHY_POINTER_HPP_INCLUDED

#include <boost/dispatch/adapted/hierarchy/iterator.hpp>
#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/pointee.hpp>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-tag
    @brief Pointer type hierarchy tag

    Types classified as pointer_ have properties similar to pointer, i.e provides operators
    for dereferencing and pointer arithmetic.

    @tparam T Base hierarchy
  **/
  template<class T> struct pointer_ : pointer_< typename T::parent >
  {
    using parent = pointer_<typename T::parent>;
  };


  template<typename T>
  struct  pointer_<unspecified_<T>>
        : random_access_iterator_<hierarchy_of_t<typename boost::pointee<T>::type,T>>
  {
    using parent = random_access_iterator_<hierarchy_of_t<typename boost::pointee<T>::type,T>>;
  };

  /*
    This breaks the infinite recursive inheritance
    Example:

      with T = float**;

      1. Goes into: pointer_<unspecified_<T>>
      2. Then: hierarchy_of_t<typename boost::pointee<T>::type, T>> == pointer_<...<T>>;
      3. Then: ...<T> will be unspecified<T> after some iterations
      4. This will go into: pointer_<unspecified_<T>> again (and T is still float**)
      5. Because of the point 4., this will goes back to point 1. which will end up into infinite
         meta recursion.

    The class below is here to break that loop. Maybe there is a better way? FIXME
   */

  template<typename T>
  struct pointer_<pointer_<T>>
  {
    using parent = pointer_<T>;
  };
} }

#endif
