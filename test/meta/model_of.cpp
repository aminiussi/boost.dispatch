//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/model_of.hpp>

#include <stf.hpp>

STF_CASE( "model_of of basic types is meta-identity")
{
  STF_TYPE_IS( boost::dispatch::model_of<float>::apply<int>       , int );
  STF_TYPE_IS( boost::dispatch::model_of<float&>::apply<int>      , int );
  STF_TYPE_IS( boost::dispatch::model_of<float&&>::apply<int>     , int );
  STF_TYPE_IS( boost::dispatch::model_of<float const>::apply<int> , int );
  STF_TYPE_IS( boost::dispatch::model_of<float const&>::apply<int>, int );
}

template<typename T> struct foo {};

STF_CASE( "model_of of template types is template<_>")
{
  STF_TYPE_IS( boost::dispatch::model_of<foo<float>>::apply<int>       , foo<int> );
  STF_TYPE_IS( boost::dispatch::model_of<foo<float>&>::apply<int>      , foo<int> );
  STF_TYPE_IS( boost::dispatch::model_of<foo<float>&&>::apply<int>     , foo<int> );
  STF_TYPE_IS( boost::dispatch::model_of<foo<float> const>::apply<int> , foo<int> );
  STF_TYPE_IS( boost::dispatch::model_of<foo<float> const&>::apply<int>, foo<int> );
}
