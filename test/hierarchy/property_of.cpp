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

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

struct foo {};
template<typename T> struct wrap {};

NSTEST_CASE( "property_of for random unspecified types" )
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( property_of<foo>, unspecified_<foo> );
  NSTEST_TYPE_IS( property_of<wrap<foo>>, unspecified_<wrap<foo>> );
  NSTEST_TYPE_IS( property_of<wrap<wrap<foo>>>, unspecified_<wrap<wrap<foo>>> );
}

NSTEST_CASE( "property_of for void" )
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( property_of<void>, void_<void> );
  NSTEST_TYPE_IS( property_of<wrap<void>>, void_<wrap<void>> );
  NSTEST_TYPE_IS( property_of<wrap<wrap<void>>>, void_<wrap<wrap<void>>> );
}

NSTEST_CASE( "property_of for bool" )
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( property_of<bool>, bool_<bool> );
  NSTEST_TYPE_IS( property_of<wrap<bool>>, bool_<wrap<bool>> );
  NSTEST_TYPE_IS( property_of<wrap<wrap<bool>>>, bool_<wrap<wrap<bool>>> );
}

NSTEST_CASE( "property_of for IEEE types" )
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( property_of<float>, single_<float> );
  NSTEST_TYPE_IS( property_of<wrap<float>>, single_<wrap<float>> );
  NSTEST_TYPE_IS( property_of<wrap<wrap<float>>>, single_<wrap<wrap<float>>> );

  NSTEST_TYPE_IS( property_of<double>, double_<double> );
  NSTEST_TYPE_IS( property_of<wrap<double>>, double_<wrap<double>> );
  NSTEST_TYPE_IS( property_of<wrap<wrap<double>>>, double_<wrap<wrap<double>>> );

  NSTEST_TYPE_IS( property_of<long double>, long_double_<long double> );
  NSTEST_TYPE_IS( property_of<wrap<long double>>, long_double_<wrap<long double>> );
  NSTEST_TYPE_IS( property_of<wrap<wrap<long double>>>, long_double_<wrap<wrap<long double>>> );
}

NSTEST_CASE_TPL ( "property_of for integral types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)
                  (unsigned char)(unsigned short)(unsigned int)(unsigned long)(unsigned long long)
                  (char)(short)(int)(long)(long long)
                )
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( property_of<T>, (integral_<T,CHAR_BIT*sizeof(T),sign_of<T>>) );
  NSTEST_TYPE_IS( property_of<wrap<T>>, (integral_<wrap<T>,CHAR_BIT*sizeof(T),sign_of<wrap<T>>>) );
  NSTEST_TYPE_IS( property_of<wrap<wrap<T>>>
                , (integral_<wrap<wrap<T>>,CHAR_BIT*sizeof(T),sign_of<wrap<wrap<T>>>>)
                );
}
