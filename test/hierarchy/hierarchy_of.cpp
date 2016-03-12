//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <cstdint>
#include <cstddef>
#include <dispatch_test.hpp>

// This mimics one way to generate a special architecture hierarchy
#include <boost/dispatch/hierarchy/cpu.hpp>

struct wazoo : boost::dispatch::cpu_
{
  using parent = boost::dispatch::cpu_;
};

// This mimics one way to dispatch to different function object
#include "moc/tutu/foo.hpp"

using namespace boost::dispatch;
struct foo {};

STF_CASE( "hierarchy_of for hierarchies" )
{
  STF_TYPE_IS( hierarchy_of_t<type_<void>>    , type_<void>     );
  STF_TYPE_IS( hierarchy_of_t<function_<void>>, function_<void> );
  STF_TYPE_IS( hierarchy_of_t<cpu_>           , cpu_            );
}

STF_CASE( "hierarchy_of for random unspecified types")
{
  STF_TYPE_IS( hierarchy_of_t<foo>         , scalar_<unspecified_<foo>> );
  STF_TYPE_IS( hierarchy_of_t<foo&>        , scalar_<unspecified_<foo>> );
  STF_TYPE_IS( hierarchy_of_t<foo const>   , scalar_<unspecified_<foo>> );
  STF_TYPE_IS( hierarchy_of_t<foo const&>  , scalar_<unspecified_<foo>> );
  STF_TYPE_IS( hierarchy_of_t<foo&&>       , scalar_<unspecified_<foo>> );
}

STF_CASE( "hierarchy_of for void" )
{
  STF_TYPE_IS( hierarchy_of_t<void>, scalar_<void_<void>> );
}

STF_CASE( "hierarchy_of for bool" )
{
  STF_TYPE_IS( hierarchy_of_t<bool>, scalar_<bool_<bool>> );
}

STF_CASE( "hierarchy_of for IEEE types" )
{
  STF_TYPE_IS( hierarchy_of_t<float>, scalar_<single_<float>> );
  STF_TYPE_IS( hierarchy_of_t<double>, scalar_<double_<double>> );
  STF_TYPE_IS( hierarchy_of_t<long double>, scalar_<long_double_<long double>> );
}

STF_CASE_TPL( "hierarchy_of for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)
              (unsigned char)(unsigned short)(unsigned int)(unsigned long)(unsigned long long)
              (char)(short)(int)(long)(long long)
            )
{
  STF_TYPE_IS ( hierarchy_of_t<T>
              , (scalar_<integral_<T,CHAR_BIT*sizeof(T),sign_of_t<T>>>)
              );
}

STF_CASE( "hierarchy_of for functor" )
{
  STF_TYPE_IS( hierarchy_of_t<functor<tutu::titi::tag::foo_>>         , tutu::titi::tag::foo_ );
  STF_TYPE_IS( hierarchy_of_t<functor<tutu::titi::tag::foo_>>::parent , elementwise_<tutu::titi::tag::foo_> );
}
