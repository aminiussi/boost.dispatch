//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/as.hpp>
#include <boost/dispatch/meta/introspection.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>

#include <nstest.hpp>

template<typename T> struct foo {};

NSTEST_CASE( "factory_of over as_<T>")
{
  NSTEST_TYPE_IS( (boost::dispatch::factory_of<boost::dispatch::as_<int>>::apply<float*>)
                , (boost::dispatch::as_<float*>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::factory_of<boost::dispatch::as_<foo<int>>>::apply<float*>)
                , (boost::dispatch::as_<foo<float*>>)
                );
}

NSTEST_CASE( "model_of of as_<T> is as_<_>")
{
  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float>>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float>&>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float>&&>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float> const>::apply<int>)
                , (boost::dispatch::as_<int>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<boost::dispatch::as_<float> const&>::apply<int>)
                , (boost::dispatch::as_<int>)
                );
}

NSTEST_CASE( "value_of of boost::dispatch::as_<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<float>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>>>)
                , (foo<int>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>>&>)
                , (foo<int>&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>> const>)
                , (foo<int> const)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>> const&>)
                , (foo<int> const&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<boost::dispatch::as_<foo<int>>&&>)
                , (foo<int>&&)
                );
}

NSTEST_CASE( "primitive_of of boost::dispatch::as_<T> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<float> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<boost::dispatch::as_<boost::dispatch::as_<float>> const&>)
                , float const&
                );
}

NSTEST_CASE( "property_of over boost::dispatch::as_<T>")
{
  using base = boost::dispatch::as_<boost::dispatch::as_<boost::dispatch::as_<float>>>;
  NSTEST_TYPE_IS( (boost::dispatch::property_of<base>), (boost::dispatch::single_<base>) );
}

NSTEST_CASE( "hierarchy_of over boost::dispatch::as_<T>")
{
  NSTEST_TYPE_IS( (boost::dispatch::hierarchy_of<boost::dispatch::as_<float>>)
                , ( boost::dispatch::target_
                    <
                      boost::dispatch::scalar_<boost::dispatch::single_<boost::dispatch::as_<float>>>
                    >
                  )
                );
}

struct bar {};

NSTEST_CASE( "as(x) generates boost::dispatch::as_<T>")
{
  bar   x;
  bar&  rx = x;
  bar const   y{};
  bar const& ry = y;

  boost::ignore_unused(rx,ry);

  NSTEST_EXPR_IS( boost::dispatch::as(x)  , boost::dispatch::as_<bar> );
  NSTEST_EXPR_IS( boost::dispatch::as(rx) , boost::dispatch::as_<bar> );
  NSTEST_EXPR_IS( boost::dispatch::as(y)  , boost::dispatch::as_<bar> );
  NSTEST_EXPR_IS( boost::dispatch::as(ry) , boost::dispatch::as_<bar> );
}
