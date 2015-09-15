//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/value_of.hpp>

#include <stf.hpp>

STF_CASE( "value_of of basic types is type itself")
{
  STF_TYPE_IS( boost::dispatch::value_of<float>        , float       );
  STF_TYPE_IS( boost::dispatch::value_of<float&>       , float&      );
  STF_TYPE_IS( boost::dispatch::value_of<float&&>      , float&&     );
  STF_TYPE_IS( boost::dispatch::value_of<float const>  , float const );
  STF_TYPE_IS( boost::dispatch::value_of<float const&> , float const&);
}

template<typename T> struct foo {};

STF_CASE_TPL( "value_of of template types is template parameter", (int)(float)(char))
{
  STF_TYPE_IS( boost::dispatch::value_of<foo<T>>       , T );
  STF_TYPE_IS( boost::dispatch::value_of<foo<T>&>      , T& );
  STF_TYPE_IS( boost::dispatch::value_of<foo<T>&&>     , T&& );
  STF_TYPE_IS( boost::dispatch::value_of<foo<T> const> , T const);
  STF_TYPE_IS( boost::dispatch::value_of<foo<T> const&>, T const&);
}
