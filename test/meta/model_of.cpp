//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/model_of.hpp>

#include <nstest.hpp>

NSTEST_CASE( "model_of of basic types is meta-identity")
{
  NSTEST_TYPE_IS( boost::dispatch::model_of<float>::apply<int>       , int );
  NSTEST_TYPE_IS( boost::dispatch::model_of<float&>::apply<int>      , int );
  NSTEST_TYPE_IS( boost::dispatch::model_of<float&&>::apply<int>     , int );
  NSTEST_TYPE_IS( boost::dispatch::model_of<float const>::apply<int> , int );
  NSTEST_TYPE_IS( boost::dispatch::model_of<float const&>::apply<int>, int );
}

template<typename T> struct foo {};

NSTEST_CASE( "model_of of template types is template<_>")
{
  NSTEST_TYPE_IS( boost::dispatch::model_of<foo<float>>::apply<int>       , foo<int> );
  NSTEST_TYPE_IS( boost::dispatch::model_of<foo<float>&>::apply<int>      , foo<int> );
  NSTEST_TYPE_IS( boost::dispatch::model_of<foo<float>&&>::apply<int>     , foo<int> );
  NSTEST_TYPE_IS( boost::dispatch::model_of<foo<float> const>::apply<int> , foo<int> );
  NSTEST_TYPE_IS( boost::dispatch::model_of<foo<float> const&>::apply<int>, foo<int> );
}
