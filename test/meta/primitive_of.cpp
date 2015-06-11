//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/primitive_of.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "primitive_of of basic types is type itself")
{
  NSTEST_TYPE_IS( boost::dispatch::primitive_of_t<float>        , float         );
  NSTEST_TYPE_IS( boost::dispatch::primitive_of_t<float&>       , float&        );
  NSTEST_TYPE_IS( boost::dispatch::primitive_of_t<float&&>      , float&&       );
  NSTEST_TYPE_IS( boost::dispatch::primitive_of_t<float const>  , float const   );
  NSTEST_TYPE_IS( boost::dispatch::primitive_of_t<float const&> , float const&  );
}
