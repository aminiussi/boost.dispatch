//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/factory_of.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "factory_of of basic types is meta-identity")
{
  NSTEST_TYPE_IS( boost::dispatch::meta::factory_of<float>::type<int>       , int );
  NSTEST_TYPE_IS( boost::dispatch::meta::factory_of<float&>::type<int>      , int );
  NSTEST_TYPE_IS( boost::dispatch::meta::factory_of<float&&>::type<int>     , int );
  NSTEST_TYPE_IS( boost::dispatch::meta::factory_of<float const>::type<int> , int );
  NSTEST_TYPE_IS( boost::dispatch::meta::factory_of<float const&>::type<int>, int );
}
