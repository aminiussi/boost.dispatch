//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/pointer_rank.hpp>
#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "pointer_rank on non-pointer is 0")
{
  STF_EQUAL( pointer_rank<float>::value        , 0u );
  STF_EQUAL( pointer_rank<float&>::value       , 0u );
  STF_EQUAL( pointer_rank<float&&>::value      , 0u );
  STF_EQUAL( pointer_rank<float const>::value  , 0u );
  STF_EQUAL( pointer_rank<float const&>::value , 0u );

  STF_EQUAL( pointer_rank<float*&>::value       , 0u );
  STF_EQUAL( pointer_rank<float*&&>::value      , 0u );
  STF_EQUAL( pointer_rank<float* const&>::value , 0u );
  STF_EQUAL( pointer_rank<float* const>::value  , 0u );
}

STF_CASE( "pointer_rank on T{*}^n is n")
{
  STF_EQUAL( pointer_rank<float*>::value       , 1u );
  STF_EQUAL( pointer_rank<float const*>::value , 1u );

  STF_EQUAL( pointer_rank<float**         >::value , 2u );
  STF_EQUAL( pointer_rank<float   const** >::value , 2u );
}
