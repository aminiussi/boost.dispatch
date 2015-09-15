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

STF_CASE( "scalar_of of basic types is the type itself" )
{
  STF_TYPE_IS( boost::dispatch::scalar_of<int>       , int         );
  STF_TYPE_IS( boost::dispatch::scalar_of<char&>      , char&        );
  STF_TYPE_IS( boost::dispatch::scalar_of<float&&>     , float&&       );
  STF_TYPE_IS( boost::dispatch::scalar_of<long const> , long const   );
  STF_TYPE_IS( boost::dispatch::scalar_of<double const&>, double const&  );
}

template<typename T> struct foo {};

STF_CASE( "scalar_of of template types is the template parameter" )
{
  STF_TYPE_IS( boost::dispatch::scalar_of<foo<int>>       , int         );
  STF_TYPE_IS( boost::dispatch::scalar_of<foo<foo<int>>>  , int         );
  STF_TYPE_IS( boost::dispatch::scalar_of<foo<int>&>      , int&        );
  STF_TYPE_IS( boost::dispatch::scalar_of<foo<int>&&>     , int&&       );
  STF_TYPE_IS( boost::dispatch::scalar_of<foo<int> const> , int const   );
  STF_TYPE_IS( boost::dispatch::scalar_of<foo<int> const&>, int const&  );
}
