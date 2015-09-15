//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/apply_sign.hpp>
#include <boost/dispatch/meta/generation/as_unsigned.hpp>
#include <boost/dispatch/meta/generation/as_signed.hpp>
#include <cstdint>

#include <stf.hpp>

STF_CASE_TPL ( "Applying signed gives signed types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (float)(double)
                )
{
  STF_TYPE_IS( (boost::dispatch::apply_sign<T,signed>), boost::dispatch::as_signed<T> );
}

STF_CASE_TPL ( "Applying unsigned gives signed types"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (float)(double)
                )
{
  STF_TYPE_IS( (boost::dispatch::apply_sign<T,unsigned>), boost::dispatch::as_unsigned<T> );
}
