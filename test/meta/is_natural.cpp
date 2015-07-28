//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/is_natural.hpp>
#include <cstdint>
#include <cstddef>

#include <nstest.hpp>

NSTEST_CASE_TPL ( "integral types are natural"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)(std::size_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)(std::ptrdiff_t)
                )
{
  NSTEST_EXPECT( boost::dispatch::is_natural<T>::value == true );
}

struct foo {};

NSTEST_CASE_TPL ( "other types are not natural"
                , (float)(double)(bool)(foo)
                )
{
  NSTEST_EXPECT( boost::dispatch::is_natural<T>::value == false );
}
