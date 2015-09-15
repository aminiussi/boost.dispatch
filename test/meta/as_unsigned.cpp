//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/as_unsigned.hpp>
#include <cstdint>

#include <stf.hpp>

STF_CASE_TPL ( "Generate unsigned from non-signed types"
                , (float)(double)(bool)(std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                )
{
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T>)       , T );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T&>)      , T );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T&&>)     , T );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T const>) , T );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T const&>), T );
}

template<typename T> using unsigned_t = typename std::make_unsigned<T>::type;

STF_CASE_TPL ( "Generate unsigned from signed types"
                , (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                )
{
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T>)        ,(unsigned_t<T>) );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T&>)       ,(unsigned_t<T>) );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T&&>)      ,(unsigned_t<T>) );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T const>)  ,(unsigned_t<T>) );
  STF_TYPE_IS( (boost::dispatch::as_unsigned<T const&&>),(unsigned_t<T>) );
}

template<typename T> struct foo {};

STF_CASE_TPL ( "Generate unsigned from custom template types"
                , (float)(double)(bool)
                  (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                )
{
  STF_TYPE_IS( (boost::dispatch::as_unsigned<foo<foo<T>>>)        , foo<foo<boost::dispatch::as_unsigned<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_unsigned<foo<foo<T>>&>)       , foo<foo<boost::dispatch::as_unsigned<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_unsigned<foo<foo<T>>&&>)      , foo<foo<boost::dispatch::as_unsigned<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_unsigned<foo<foo<T>> const>)  , foo<foo<boost::dispatch::as_unsigned<T>>>);
  STF_TYPE_IS( (boost::dispatch::as_unsigned<foo<foo<T>> const&&>), foo<foo<boost::dispatch::as_unsigned<T>>>);
}
