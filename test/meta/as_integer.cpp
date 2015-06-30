//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/as_integer.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE_TPL ( "Generate integer from integral types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t )(std::int16_t )(std::int32_t )(std::int64_t )
                )
{
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T>)       , T );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T&>)      , T );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T&&>)     , T );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T const>) , T );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T const&>), T );
}

NSTEST_CASE_TPL( "Generate integer from real types", (float)(double) )
{
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T>)        ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T&>)       ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T&&>)      ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T const>)  ,(boost::dispatch::make_integer<sizeof(T),signed>) );
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<T const&&>),(boost::dispatch::make_integer<sizeof(T),signed>) );
}

template<typename T> struct foo {};

NSTEST_CASE_TPL ( "Generate integer from custom template types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t )(std::int16_t )(std::int32_t )(std::int64_t )
                  (float)(double)
                )
{
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>>>)        , foo<foo<boost::dispatch::as_integer<T>>>);
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>>&>)       , foo<foo<boost::dispatch::as_integer<T>>>);
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>>&&>)      , foo<foo<boost::dispatch::as_integer<T>>>);
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>> const>)  , foo<foo<boost::dispatch::as_integer<T>>>);
  NSTEST_TYPE_IS( (boost::dispatch::as_integer<foo<foo<T>> const&&>), foo<foo<boost::dispatch::as_integer<T>>>);
}
