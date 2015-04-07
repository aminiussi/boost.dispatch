//==================================================================================================
/*!
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================

//! [basic]
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value,int>::type f(T)
{
  return 0;
}

template<typename T>
typename std::enable_if<std::is_signed<T>::value && std::is_integral<T>::value >,int>::type f(T)
{
  return 1;
}

template<typename T>
typename std::enable_if<!std::is_signed<T>::value && std::is_integral<T>::value >,int>::type f(T)
{
  return 2;
}
//! [basic]

//! [tagdispatching]
struct unknown_tag                              {};
struct fundamental_tag                          {};
struct floating_point_tag     : fundamental_tag {};
struct integral_tag           : fundamental_tag {};
struct signed_integral_tag    : integral_tag    {};
struct unsigned_integral_tag  : integral_tag    {};

template<typename T>  struct category_of                { typedef unknown_tag type;           };
template<>            struct category_of<float>         { typedef floating_point_tag type;    };
template<>            struct category_of<double>        { typedef floating_point_tag type;    };
template<>            struct category_of<int>           { typedef signed_integral_tag type;   };
template<>            struct category_of<unsigned int>  { typedef unsigned_integral_tag type; };

/* etc. for all other fundamental types... */

template<typename T> int f(T t)
{
  return f(t, typename category_of<T>::type() );
}

template<typename T> int f(T, floating_point_tag const&)
{
  return 0;
}

template<typename T> int f(T, integral_tag const&)
{
  return 1;
}

template<typename T> int f(T, unsigned_integral_tag const&)
{
  return 2;
}
//! [tagdispatching]

//! [boost]
#include <boost/dispatch/hierarchy_of.hpp>

using namespace boost::dispatch;

template<typename T> int f(T t)
{
  return f(t, hierarchy_of(t) );
}

template<typename T> int f(T, scalar_< floating_<T> > const&)
{
  return 0;
}

template<typename T> int f(T, scalar_< integer_<T> > const&)
{
  return 1;
}

template<typename T> int f(T, scalar_< unsigned_<T> > const&)
{
  return 2;
}
//! [boost]
