//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/primitive_of.hpp>

#include <stf.hpp>

STF_CASE( "primitive_of of basic types is type itself")
{
  STF_TYPE_IS( boost::dispatch::primitive_of<float>        , float         );
  STF_TYPE_IS( boost::dispatch::primitive_of<float&>       , float&        );
  STF_TYPE_IS( boost::dispatch::primitive_of<float&&>      , float&&       );
  STF_TYPE_IS( boost::dispatch::primitive_of<float const>  , float const   );
  STF_TYPE_IS( boost::dispatch::primitive_of<float const&> , float const&  );
}
