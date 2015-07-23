//==================================================================================================
/*!
  @file

  Defines macros for building a custom test driver

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_DRIVER_HPP_INCLUDED
#define NSTEST_COMMON_DRIVER_HPP_INCLUDED

#include <nstest/common/args.hpp>
#include <nstest/common/values.hpp>
#include <algorithm>
#include <random>

namespace nstest
{
  /*!
    @ingroup group-common

    @brief Starts the execution of a group of function object.

    Starts the execution of every functions registered as a test suite of any kind and report
    success or failure with respect to the expectation of said test semantic.

    Usually, the test suite being run is given by nstest::test_suite() but it can
    differs in some use case, hence the need to pass it as a parameter.

    @par Example:
    @snippet example/unit/case.cpp driver

    @param environment  Test environment
    @param tests        Test suite to execute
    @param setup        Additional, test kind specific, parameters

    @return A boolean value indicating if the whole test is considered a success.
  **/
  template<typename Environment, typename Suite, typename... Setup>
  inline bool run(Environment& environment, Suite& tests, Setup const&... setup)
  {
    // retrieve compact status
    auto is_compact = args("compact",false);
    environment.compact(is_compact);

    // randomize test on non-null random seed option
    if(auto seed = args("random",0u))
    {
      std::shuffle( tests.begin(), tests.end(), std::mt19937{seed} );
    }

    for(auto& t : tests )
    {
      scenario_header(environment,t);
      auto count = environment.tests();

      t(environment);

      process_invalid(environment, count);

      environment.stream() << std::endl;
    }

    return ::nstest::report(environment,setup...);
  }
}

#endif
