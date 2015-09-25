//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/value_of.hpp>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "value_of_t of basic types is type itself")
{
  STF_TYPE_IS( value_of_t<float>        , float       );
  STF_TYPE_IS( value_of_t<float&>       , float&      );
  STF_TYPE_IS( value_of_t<float&&>      , float&&     );
  STF_TYPE_IS( value_of_t<float const>  , float const );
  STF_TYPE_IS( value_of_t<float const&> , float const&);
}

template<typename T> struct foo {};

STF_CASE_TPL( "value_of_t of template types is template parameter", (int)(float)(char))
{
  STF_TYPE_IS( value_of_t<foo<T>>       , T );
  STF_TYPE_IS( value_of_t<foo<T>&>      , T& );
  STF_TYPE_IS( value_of_t<foo<T>&&>     , T&& );
  STF_TYPE_IS( value_of_t<foo<T> const> , T const);
  STF_TYPE_IS( value_of_t<foo<T> const&>, T const&);
}
