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

STF_CASE( "property_of for random unspecified types" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( property_of<foo>, unspecified_<foo> );
  STF_TYPE_IS( property_of<wrap<foo>>, unspecified_<wrap<foo>> );
  STF_TYPE_IS( property_of<wrap<wrap<foo>>>, unspecified_<wrap<wrap<foo>>> );
}

STF_CASE( "property_of for void" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( property_of<void>, void_<void> );
  STF_TYPE_IS( property_of<wrap<void>>, void_<wrap<void>> );
  STF_TYPE_IS( property_of<wrap<wrap<void>>>, void_<wrap<wrap<void>>> );
}

STF_CASE( "property_of for bool" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( property_of<bool>, bool_<bool> );
  STF_TYPE_IS( property_of<wrap<bool>>, bool_<wrap<bool>> );
  STF_TYPE_IS( property_of<wrap<wrap<bool>>>, bool_<wrap<wrap<bool>>> );
}

STF_CASE( "property_of for IEEE types" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( property_of<float>, single_<float> );
  STF_TYPE_IS( property_of<wrap<float>>, single_<wrap<float>> );
  STF_TYPE_IS( property_of<wrap<wrap<float>>>, single_<wrap<wrap<float>>> );

  STF_TYPE_IS( property_of<double>, double_<double> );
  STF_TYPE_IS( property_of<wrap<double>>, double_<wrap<double>> );
  STF_TYPE_IS( property_of<wrap<wrap<double>>>, double_<wrap<wrap<double>>> );

  STF_TYPE_IS( property_of<long double>, long_double_<long double> );
  STF_TYPE_IS( property_of<wrap<long double>>, long_double_<wrap<long double>> );
  STF_TYPE_IS( property_of<wrap<wrap<long double>>>, long_double_<wrap<wrap<long double>>> );
}

STF_CASE_TPL ( "property_of for integral types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)
                  (unsigned char)(unsigned short)(unsigned int)(unsigned long)(unsigned long long)
                  (char)(short)(int)(long)(long long)
                )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( property_of<T>, (integral_<T,CHAR_BIT*sizeof(T),sign_of<T>>) );
  STF_TYPE_IS( property_of<wrap<T>>, (integral_<wrap<T>,CHAR_BIT*sizeof(T),sign_of<wrap<T>>>) );
  STF_TYPE_IS( property_of<wrap<wrap<T>>>
                , (integral_<wrap<wrap<T>>,CHAR_BIT*sizeof(T),sign_of<wrap<wrap<T>>>>)
                );
}
