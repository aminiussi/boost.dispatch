//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/sign_of.hpp>
#include <cstdint>
#include <cstddef>

#include <stf.hpp>

using namespace boost::dispatch;

struct foo {};

STF_CASE_TPL( "sign_of of signed types is signed"
            , (float)(double)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)(std::ptrdiff_t)
            )
{
  STF_TYPE_IS( sign_of_t<T>        , signed );
  STF_TYPE_IS( sign_of_t<T&>       , signed );
  STF_TYPE_IS( sign_of_t<T&&>      , signed );
  STF_TYPE_IS( sign_of_t<T const>  , signed );
  STF_TYPE_IS( sign_of_t<T const&> , signed );
}

STF_CASE_TPL( "sign_of of unsigned types is unsigned"
            , (foo)(std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)(std::size_t)
            )
{
  STF_TYPE_IS( sign_of_t<T>        , unsigned );
  STF_TYPE_IS( sign_of_t<T&>       , unsigned );
  STF_TYPE_IS( sign_of_t<T&&>      , unsigned );
  STF_TYPE_IS( sign_of_t<T const>  , unsigned );
  STF_TYPE_IS( sign_of_t<T const&> , unsigned );
}
