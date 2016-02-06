//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/factory_of.hpp>

#include <dispatch_test.hpp>

STF_CASE( "factory_of of basic types is meta-identity")
{
  STF_TYPE_IS( boost::dispatch::factory_of<float>::apply<int>::type       , int );
  STF_TYPE_IS( boost::dispatch::factory_of<float&>::apply<int>::type      , int );
  STF_TYPE_IS( boost::dispatch::factory_of<float&&>::apply<int>::type     , int );
  STF_TYPE_IS( boost::dispatch::factory_of<float const>::apply<int>::type , int );
  STF_TYPE_IS( boost::dispatch::factory_of<float const&>::apply<int>::type, int );
}
