//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/dispatch/hierarchy/cpu.hpp>
struct wazoo : boost::dispatch::cpu_
{
  using parent = boost::dispatch::cpu_;
};

// This mimics one way to dispatch to different function object
#include "moc/tutu/foo.hpp"

#include <stf.hpp>

STF_CASE( "dispatch works correctly")
{
/*  std::cout << tutu::titi::foo('4') << "\n";
  std::cout << tutu::titi::foo.on<boost::dispatch::cpu_>('4') << "\n";
  std::cout << tutu::titi::foo.on<wazoo>('4') << "\n";
  std::cout << tutu::titi::foo(4) << "\n";
  std::cout << tutu::titi::foo(short(4)) << "\n";
  std::cout << tutu::titi::foo(4.) << "\n";
  std::cout << tutu::titi::foo.on<boost::dispatch::cpu_>(4.) << "\n";
  std::cout << tutu::titi::foo.on<wazoo>(4.) << "\n";*/

//  double x = 4.;
//  std::cout << x << "\n";
//  std::cout << tutu::titi::foo(x) << "\n";
//  std::cout << x << "\n";
}
