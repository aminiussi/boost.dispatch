//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <stf.hpp>

// This mimics one way to generate a special architecture hierarchy
#include <boost/dispatch/hierarchy/cpu.hpp>

struct wazoo : boost::dispatch::cpu_
{
  using parent = boost::dispatch::cpu_;
};

// This mimics one way to dispatch to different function object
#include "moc/tutu/foo.hpp"

STF_CASE( "dispatch works correctly")
{
  STF_EQUAL(tutu::titi::foo('4')  , '#'     );
  STF_EQUAL(tutu::titi::foo(4)    , -13.37f );
  STF_EQUAL(tutu::titi::foo(4ULL) , 44ULL   );
  STF_EQUAL(tutu::titi::foo(4.)   , 0.4     );

  STF_EQUAL(tutu::titi::foo_alias('4')  , '#'     );
  STF_EQUAL(tutu::titi::foo_alias(4)    , -13.37f );
  STF_EQUAL(tutu::titi::foo_alias(4ULL) , 44ULL   );
  STF_EQUAL(tutu::titi::foo_alias(4.)   , 0.4     );
}

STF_CASE( "dispatch works correctly using .on<cpu_>")
{
  // Same as above
  STF_EQUAL(tutu::titi::foo.on<boost::dispatch::cpu_>('4')  , '#'     );
  STF_EQUAL(tutu::titi::foo.on<boost::dispatch::cpu_>(4)    , -13.37f );
  STF_EQUAL(tutu::titi::foo.on<boost::dispatch::cpu_>(4ULL) , 44ULL   );
  STF_EQUAL(tutu::titi::foo.on<boost::dispatch::cpu_>(4.)   , 0.4     );
}

STF_CASE( "dispatch works correctly using .on<Site>")
{
  // Different behavior on different arch
  STF_EQUAL(tutu::titi::foo.on<wazoo>('4')  , 'Z'     );
  STF_EQUAL(tutu::titi::foo.on<wazoo>('A',3), 'D'     );
  STF_EQUAL(tutu::titi::foo.on<wazoo>(4)    , -13.37f );
  STF_EQUAL(tutu::titi::foo.on<wazoo>(4ULL) , 44ULL   );
  STF_EQUAL(tutu::titi::foo.on<wazoo>(4.)   , 0.4     );
}

template<typename F> auto some_call(F f) -> decltype(f('x'))
{
  return f('x');
}

STF_CASE( "dispatch works correctly when functor are passed as parameters")
{
  using functor_type = decltype(tutu::titi::foo);

  STF_EQUAL(some_call(tutu::titi::foo), '#');
  STF_EQUAL(some_call(tutu::titi::foo.rebind<wazoo>()), 'Z');
  STF_EQUAL(some_call(functor_type::rebind<wazoo>()),'Z');;
}
