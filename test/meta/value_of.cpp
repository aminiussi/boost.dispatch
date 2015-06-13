//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/value_of.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "value_of of basic types is type itself")
{
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<float>        , float       );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<float&>       , float&      );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<float&&>      , float&&     );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<float const>  , float const );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<float const&> , float const&);
}

template<typename T> struct foo {};

NSTEST_CASE_TPL( "value_of of template types is template parameter", (int)(float)(char))
{
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<foo<T>>       , T );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<foo<T>&>      , T& );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<foo<T>&&>     , T&& );
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<foo<T> const> , T const);
  NSTEST_TYPE_IS( boost::dispatch::value_of_t<foo<T> const&>, T const&);
}
