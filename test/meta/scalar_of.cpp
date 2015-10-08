//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/scalar_of.hpp>
#include <cstdint>
#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "scalar_of of basic types is the type itself" )
{
  STF_TYPE_IS( scalar_of_t<int>           , int           );
  STF_TYPE_IS( scalar_of_t<char&>         , char&         );
  STF_TYPE_IS( scalar_of_t<float&&>       , float&&       );
  STF_TYPE_IS( scalar_of_t<long const>    , long const    );
  STF_TYPE_IS( scalar_of_t<double const&> , double const& );
}
