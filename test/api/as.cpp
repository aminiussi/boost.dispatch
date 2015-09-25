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
using namespace boost::dispatch;

STF_CASE( "factory_of over as_<T>")
{
  STF_TYPE_IS ( (factory_of<as_<int>>::apply<float*>::type), (as_<float*>));
  STF_TYPE_IS ( (factory_of<as_<foo<int>>>::apply<float*>::type), (as_<foo<float*>>));
}

STF_CASE( "model_of of as_<T> is as_<_>")
{
  STF_TYPE_IS( (model_of<as_<float>>::apply<int>::type)       , (as_<int>));
  STF_TYPE_IS( (model_of<as_<float>&>::apply<int>::type)      , (as_<int>));
  STF_TYPE_IS( (model_of<as_<float>&&>::apply<int>::type)     , (as_<int>));
  STF_TYPE_IS( (model_of<as_<float> const>::apply<int>::type) , (as_<int>));
  STF_TYPE_IS( (model_of<as_<float> const&>::apply<int>::type), (as_<int>));
}

STF_CASE( "value_of of as_<T,N> is T")
{
  STF_TYPE_IS( (value_of_t<as_<float>>)           , float             );
  STF_TYPE_IS( (value_of_t<as_<float> const>)     , float const       );
  STF_TYPE_IS( (value_of_t<as_<float>&>)          , float&            );
  STF_TYPE_IS( (value_of_t<as_<float> const&>)    , float const&      );
  STF_TYPE_IS( (value_of_t<as_<float>&&>)         , float&&           );
  STF_TYPE_IS( (value_of_t<as_<foo<int>>>)        , (foo<int>)        );
  STF_TYPE_IS( (value_of_t<as_<foo<int>>&>)       , (foo<int>&)       );
  STF_TYPE_IS( (value_of_t<as_<foo<int>> const>)  , (foo<int> const)  );
  STF_TYPE_IS( (value_of_t<as_<foo<int>> const&>) , (foo<int> const&) );
  STF_TYPE_IS( (value_of_t<as_<foo<int>>&&>)      , (foo<int>&&)      );
}

STF_CASE( "primitive_of of as_<T> is T")
{
  STF_TYPE_IS( (primitive_of_t<as_<float>>)             , float         );
  STF_TYPE_IS( (primitive_of_t<as_<float>&>)            , float&        );
  STF_TYPE_IS( (primitive_of_t<as_<float>&&>)           , float&&       );
  STF_TYPE_IS( (primitive_of_t<as_<float> const>)       , float const   );
  STF_TYPE_IS( (primitive_of_t<as_<float> const&>)      , float const&  );
  STF_TYPE_IS( (primitive_of_t<as_<as_<float>>>)        , float         );
  STF_TYPE_IS( (primitive_of_t<as_<as_<float>>&>)       , float&        );
  STF_TYPE_IS( (primitive_of_t<as_<as_<float>>&&>)      , float&&       );
  STF_TYPE_IS( (primitive_of_t<as_<as_<float>> const>)  , float const   );
  STF_TYPE_IS( (primitive_of_t<as_<as_<float>> const&>) , float const&  );
}

STF_CASE( "property_of over as_<T>")
{
  using base = as_<as_<as_<float>>>;
  STF_TYPE_IS( (property_of_t<base>), (single_<base>) );
}

STF_CASE( "hierarchy_of over as_<T>")
{
  STF_TYPE_IS( (hierarchy_of_t<as_<float>>), ( target_<scalar_<single_<as_<float>>>>) );
}

struct bar {};

STF_CASE( "as(x) generates as_<T>")
{
  bar   x;
  bar&  rx = x;
  bar const   y{};
  bar const& ry = y;

  boost::ignore_unused(rx,ry);

  STF_EXPR_IS( as(x)  , as_<bar> );
  STF_EXPR_IS( as(rx) , as_<bar> );
  STF_EXPR_IS( as(y)  , as_<bar> );
  STF_EXPR_IS( as(ry) , as_<bar> );
}
