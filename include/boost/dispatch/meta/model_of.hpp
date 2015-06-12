//==================================================================================================
/*!
  @file

  Defines the meta::model_of meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_MODEL_OF_HPP_INCLUDED
#define BOOST_DISPATCH_META_MODEL_OF_HPP_INCLUDED

#include <boost/dispatch/meta/detail/model_of.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace dispatch
{
  namespace meta
  {
    /*!
      @ingroup group-meta
      @brief Model generator meta-function

      Build, for any given type @c T, a @metafunction which can reconstruct a new type @c U similar
      to @c T but by using a different underlying type.

      @par Models:

      @metafunction

      @par Semantic:

      For any type @c T,

      @code
      meta::model_of<T>::type;
      @endcode

      defines a template alias so that:

      @code
      std::is_same<meta::model_of<T>::type<meta::value_of_t<T>>, T>::value
      @endcode

      evaluates to @c true.

      @par Extension Point:

      meta::model_of can be specialized for user-defined types by either:

        - Directly overloading the meta::model_of class for a given type
        - Specialize (eventually through SFINAE) the ext::model_of class

      Specialization for meta::model_of are provided for most of standard and
      Boost types. See the @ref group-adapted page.

      @tparam T Type to turn into a generator @metafunction
    **/
    template<typename T> struct model_of            : ext::model_of<T>  {};
    template<typename T> struct model_of<T&>        : model_of<T>       {};
    template<typename T> struct model_of<T&&>       : model_of<T>       {};
    template<typename T> struct model_of<T const>   : model_of<T>       {};
  }
} }

#endif
