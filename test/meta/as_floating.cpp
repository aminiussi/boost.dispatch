//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/dispatch/meta/make_floating.hpp>
#include <cstdint>

#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE_TPL( "Generate floating from floating types", STF_IEEE_TYPES )
{
  STF_TYPE_IS( (as_floating_t<T>)       , T );
  STF_TYPE_IS( (as_floating_t<T&>)      , T );
  STF_TYPE_IS( (as_floating_t<T&&>)     , T );
  STF_TYPE_IS( (as_floating_t<T const>) , T );
  STF_TYPE_IS( (as_floating_t<T const&>), T );
}

STF_CASE_TPL( "Generate floating from integral types", STF_INTEGRAL_TYPES )
{
  STF_TYPE_IS( (as_floating_t<T>)        ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T&>)       ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T&&>)      ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T const>)  ,(make_floating_t<sizeof(T)>) );
  STF_TYPE_IS( (as_floating_t<T const&&>),(make_floating_t<sizeof(T)>) );
}
