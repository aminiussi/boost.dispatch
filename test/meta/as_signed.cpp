//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/as_signed.hpp>
#include <cstdint>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE_TPL ( "Generate signed from signed types"
                , (float)(double)(bool)(std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                )
{
  STF_TYPE_IS( (as_signed_t<T>)       , T );
  STF_TYPE_IS( (as_signed_t<T&>)      , T );
  STF_TYPE_IS( (as_signed_t<T&&>)     , T );
  STF_TYPE_IS( (as_signed_t<T const>) , T );
  STF_TYPE_IS( (as_signed_t<T const&>), T );
}

template<typename T> using signed_t = typename std::make_signed<T>::type;

STF_CASE_TPL ( "Generate signed from unsigned types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                )
{
  STF_TYPE_IS( (as_signed_t<T>)        ,(signed_t<T>) );
  STF_TYPE_IS( (as_signed_t<T&>)       ,(signed_t<T>) );
  STF_TYPE_IS( (as_signed_t<T&&>)      ,(signed_t<T>) );
  STF_TYPE_IS( (as_signed_t<T const>)  ,(signed_t<T>) );
  STF_TYPE_IS( (as_signed_t<T const&&>),(signed_t<T>) );
}
