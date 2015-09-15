//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/as.hpp>
#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>

#include <stf.hpp>

template<typename T> struct foo {};

STF_CASE( "factory_of over as_<T>")
{
  STF_TYPE_IS( (boost::dispatch::factory_of<boost::dispatch::as_<int>>::apply<float*>)
                , (boost::dispatch::as_<float*>)
                );

  STF_TYPE_IS( (boost::dispatch::factory_of<boost::dispatch::as_<foo<int>>>::apply<float*>)
                , (boost::dispatch::as_<foo<float*>>)
                );
}

STF_CASE( "model_of of as_<T> is as_<_>")
{
  STF_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float>>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float>&>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float>&&>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float> const>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float> const&>::apply<int>)
                , (boost::dispatch::as_<int>)
                );
}

STF_CASE( "value_of of boost::dispatch::as_<T,N> is T")
{
  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float>>)
                , float
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float> const>)
                , float const
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float>&>)
                , float&
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float> const&>)
                , float const&
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float>&&>)
                , float&&
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>>>)
                , (foo<int>)
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>>&>)
                , (foo<int>&)
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>> const>)
                , (foo<int> const)
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>> const&>)
                , (foo<int> const&)
                );

  STF_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>>&&>)
                , (foo<int>&&)
                );
}

STF_CASE( "primitive_of of boost::dispatch::as_<T> is T")
{
  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float>>)
                , float
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float>&>)
                , float&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float>&&>)
                , float&&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float> const>)
                , float const
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float> const&>)
                , float const&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>>>)
                , float
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>>&>)
                , float&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>>&&>)
                , float&&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>> const>)
                , float const
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>> const&>)
                , float const&
                );
}

STF_CASE( "property_of over boost::dispatch::as_<T>")
{
  using base = boost::dispatch::as_<boost::dispatch::as_<boost::dispatch::as_<float>>>;
  STF_TYPE_IS( (boost::dispatch::property_of<base>), (boost::dispatch::single_<base>) );
}

STF_CASE( "hierarchy_of over boost::dispatch::as_<T>")
{
  STF_TYPE_IS( (boost::dispatch::hierarchy_of<boost::dispatch::as_<float>>)
                , ( boost::dispatch::target_
                    <
                      boost::dispatch::scalar_<boost::dispatch::single_<boost::dispatch::as_<float>>>
                    >
                  )
                );
}

struct bar {};

STF_CASE( "as(x) generates boost::dispatch::as_<T>")
{
  bar   x;
  bar&  rx = x;
  bar const   y{};
  bar const& ry = y;

  boost::ignore_unused(rx,ry);

  STF_EXPR_IS( boost::dispatch::as(x)  , boost::dispatch::as_<bar> );
  STF_EXPR_IS( boost::dispatch::as(rx) , boost::dispatch::as_<bar> );
  STF_EXPR_IS( boost::dispatch::as(y)  , boost::dispatch::as_<bar> );
  STF_EXPR_IS( boost::dispatch::as(ry) , boost::dispatch::as_<bar> );
}
