//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/hierarchy_of.hpp>
#include <cstdint>
#include <cstddef>

#include <stf.hpp>

struct foo {};
template<typename T> struct wrap {};

STF_CASE_TPL ( "hierarchy_of for random unspecified types"
                , (foo)(wrap<foo>)(wrap<wrap<foo>>)
                )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( hierarchy_of<T>         , scalar_<unspecified_<T>> );
  STF_TYPE_IS( hierarchy_of<T&>        , scalar_<unspecified_<T>> );
  STF_TYPE_IS( hierarchy_of<T const>   , scalar_<unspecified_<T>> );
  STF_TYPE_IS( hierarchy_of<T const&>  , scalar_<unspecified_<T>> );
  STF_TYPE_IS( hierarchy_of<T&&>       , scalar_<unspecified_<T>> );
}

STF_CASE( "hierarchy_of for void" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( hierarchy_of<void>, scalar_<void_<void>> );
  STF_TYPE_IS( hierarchy_of<wrap<void>>, scalar_<void_<wrap<void>>> );
  STF_TYPE_IS( hierarchy_of<wrap<wrap<void>>>, scalar_<void_<wrap<wrap<void>>>> );
}

STF_CASE( "hierarchy_of for bool" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( hierarchy_of<bool>, scalar_<bool_<bool>> );
  STF_TYPE_IS( hierarchy_of<wrap<bool>>, scalar_<bool_<wrap<bool>>> );
  STF_TYPE_IS( hierarchy_of<wrap<wrap<bool>>>, scalar_<bool_<wrap<wrap<bool>>>> );
}

STF_CASE( "hierarchy_of for IEEE types" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( hierarchy_of<float>, scalar_<single_<float>> );
  STF_TYPE_IS( hierarchy_of<wrap<float>>, scalar_<single_<wrap<float>>> );
  STF_TYPE_IS( hierarchy_of<wrap<wrap<float>>>, scalar_<single_<wrap<wrap<float>>>> );

  STF_TYPE_IS( hierarchy_of<double>, scalar_<double_<double>> );
  STF_TYPE_IS( hierarchy_of<wrap<double>>, scalar_<double_<wrap<double>>> );
  STF_TYPE_IS( hierarchy_of<wrap<wrap<double>>>, scalar_<double_<wrap<wrap<double>>>> );

  STF_TYPE_IS( hierarchy_of<long double>, scalar_<long_double_<long double>> );
  STF_TYPE_IS( hierarchy_of<wrap<long double>>, scalar_<long_double_<wrap<long double>>> );
  STF_TYPE_IS( hierarchy_of<wrap<wrap<long double>>>, scalar_<long_double_<wrap<wrap<long double>>>> );
}

STF_CASE_TPL ( "hierarchy_of for integral types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)
                  (unsigned char)(unsigned short)(unsigned int)(unsigned long)(unsigned long long)
                  (char)(short)(int)(long)(long long)
                )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( hierarchy_of<T>
                , (scalar_<integral_<T,CHAR_BIT*sizeof(T),sign_of<T>>>)
                );

  STF_TYPE_IS( hierarchy_of<wrap<T>>
                , (scalar_<integral_<wrap<T>,CHAR_BIT*sizeof(T),sign_of<wrap<T>>>>)
                );

  STF_TYPE_IS( hierarchy_of<wrap<wrap<T>>>
                , (scalar_<integral_<wrap<wrap<T>>,CHAR_BIT*sizeof(T),sign_of<wrap<wrap<T>>>>>)
                );
}
