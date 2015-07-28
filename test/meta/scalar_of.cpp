//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/scalar_of.hpp>
#include <cstdint>

#include <nstest.hpp>

NSTEST_CASE( "scalar_of of basic types is the type itself" )
{
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<int>       , int         );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<char&>      , char&        );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<float&&>     , float&&       );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<long const> , long const   );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<double const&>, double const&  );
}

template<typename T> struct foo {};

NSTEST_CASE( "scalar_of of template types is the template parameter" )
{
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<foo<int>>       , int         );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<foo<foo<int>>>  , int         );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<foo<int>&>      , int&        );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<foo<int>&&>     , int&&       );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<foo<int> const> , int const   );
  NSTEST_TYPE_IS( boost::dispatch::scalar_of<foo<int> const&>, int const&  );
}
