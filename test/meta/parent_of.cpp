//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/parent_of.hpp>

#include <stf.hpp>

STF_CASE( "parent_of of basic types is identity")
{
  STF_TYPE_IS( boost::dispatch::parent_of_t<float>, void );
}

struct foo {};
struct bar { using parent = foo; };
struct chu { using parent = bar; };

STF_CASE( "parent_of of types try to access ::parent")
{
  STF_TYPE_IS( boost::dispatch::parent_of_t<foo>, void );
  STF_TYPE_IS( boost::dispatch::parent_of_t<bar>, foo );
  STF_TYPE_IS( boost::dispatch::parent_of_t<chu>, bar );
}
