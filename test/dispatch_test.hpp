//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_DISPATCH_TEST_HPP_INCLUDED
#define BOOST_DISPATCH_TEST_HPP_INCLUDED

#include <boost/dispatch/config.hpp>

#if defined(BOOST_DISPATCH_USE_INCOMPLETE_STD)
#define STF_USE_INCOMPLETE_STD
#endif

#define STF_CUSTOM_DRIVER_FUNCTION dispatch_test
#include <stf.hpp>

int main(int argc, const char** argv)
{
  std::cout << "CTEST_FULL_OUTPUT\n";
  return dispatch_test(argc,argv);
}

#endif
