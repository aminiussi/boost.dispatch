//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/property_of.hpp>
#include <cstdint>
#include <cstddef>

#include <stf.hpp>

struct foo {};
template<typename T> struct wrap {};

using namespace boost::dispatch;

STF_CASE( "property_of for random unspecified types" )
{
  STF_TYPE_IS( property_of_t<foo>, unspecified_<foo> );
  STF_TYPE_IS( property_of_t<wrap<foo>>, unspecified_<wrap<foo>> );
  STF_TYPE_IS( property_of_t<wrap<wrap<foo>>>, unspecified_<wrap<wrap<foo>>> );
}

STF_CASE( "property_of for void" )
{

  STF_TYPE_IS( property_of_t<void>, void_<void> );
  STF_TYPE_IS( property_of_t<wrap<void>>, void_<wrap<void>> );
  STF_TYPE_IS( property_of_t<wrap<wrap<void>>>, void_<wrap<wrap<void>>> );
}

STF_CASE( "property_of for bool" )
{
  STF_TYPE_IS( property_of_t<bool>, bool_<bool> );
  STF_TYPE_IS( property_of_t<wrap<bool>>, bool_<wrap<bool>> );
  STF_TYPE_IS( property_of_t<wrap<wrap<bool>>>, bool_<wrap<wrap<bool>>> );
}

STF_CASE( "property_of for IEEE types" )
{
  STF_TYPE_IS( property_of_t<float>, single_<float> );
  STF_TYPE_IS( property_of_t<wrap<float>>, single_<wrap<float>> );
  STF_TYPE_IS( property_of_t<wrap<wrap<float>>>, single_<wrap<wrap<float>>> );

  STF_TYPE_IS( property_of_t<double>, double_<double> );
  STF_TYPE_IS( property_of_t<wrap<double>>, double_<wrap<double>> );
  STF_TYPE_IS( property_of_t<wrap<wrap<double>>>, double_<wrap<wrap<double>>> );

  STF_TYPE_IS( property_of_t<long double>, long_double_<long double> );
  STF_TYPE_IS( property_of_t<wrap<long double>>, long_double_<wrap<long double>> );
  STF_TYPE_IS( property_of_t<wrap<wrap<long double>>>, long_double_<wrap<wrap<long double>>> );
}

STF_CASE_TPL ( "property_of for integral types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)
                  (unsigned char)(unsigned short)(unsigned int)(unsigned long)(unsigned long long)
                  (char)(short)(int)(long)(long long)
                )
{
  STF_TYPE_IS( property_of_t<T>, (integral_<T,CHAR_BIT*sizeof(T),sign_of_t<T>>) );
  STF_TYPE_IS( property_of_t<wrap<T>>, (integral_<wrap<T>,CHAR_BIT*sizeof(T),sign_of_t<wrap<T>>>) );
  STF_TYPE_IS( property_of_t<wrap<wrap<T>>>
                , (integral_<wrap<wrap<T>>,CHAR_BIT*sizeof(T),sign_of_t<wrap<wrap<T>>>>)
                );
}
