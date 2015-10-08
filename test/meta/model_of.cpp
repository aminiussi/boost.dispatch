//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/model_of.hpp>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "model_of of basic types is meta-identity")
{
  STF_TYPE_IS( model_of<float>::apply<int>::type       , int );
  STF_TYPE_IS( model_of<float&>::apply<int>::type      , int );
  STF_TYPE_IS( model_of<float&&>::apply<int>::type     , int );
  STF_TYPE_IS( model_of<float const>::apply<int>::type , int );
  STF_TYPE_IS( model_of<float const&>::apply<int>::type, int );
}
