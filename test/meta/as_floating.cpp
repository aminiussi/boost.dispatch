//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/as_floating.hpp>
#include <boost/dispatch/meta/generation/make_floating.hpp>
#include <cstdint>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE_TPL( "Generate floating from floating types", (float)(double) )
{
  STF_TYPE_IS( (as_floating_t<T>)       , T );
  STF_TYPE_IS( (as_floating_t<T&>)      , T );
  STF_TYPE_IS( (as_floating_t<T&&>)     , T );
  STF_TYPE_IS( (as_floating_t<T const>) , T );
  STF_TYPE_IS( (as_floating_t<T const&>), T );
}

STF_CASE_TPL( "Generate floating from integral types"
            , (std::int32_t)(std::int64_t)(std::uint32_t)(std::uint64_t)
            )
{
  STF_TYPE_IS( (as_floating_t<T>)        ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T&>)       ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T&&>)      ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T const>)  ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T const&&>),(make_floating_t<sizeof(T)>) );
}
