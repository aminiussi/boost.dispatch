//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/behave_as.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>

#include <stf.hpp>

template<typename T> using is_fp = typename std::is_floating_point<T>::type;

STF_CASE( "behave_as of basic types is same as direct meta-function call")
{
  STF_TYPE_IS( (boost::dispatch::behave_as<float,is_fp>) , brigand::true_  );
  STF_TYPE_IS( (boost::dispatch::behave_as<double,is_fp>), brigand::true_  );
  STF_TYPE_IS( (boost::dispatch::behave_as<char,is_fp>)  , brigand::false_ );
  STF_TYPE_IS( (boost::dispatch::behave_as<void*,is_fp>) , brigand::false_ );
}

template<typename T> struct foo {};
template<typename T> struct bar {};

STF_CASE( "behave_as go through template layers")
{
  STF_TYPE_IS( (boost::dispatch::behave_as<foo<float>,is_fp>)         , brigand::true_  );
  STF_TYPE_IS( (boost::dispatch::behave_as<foo<bar<double>>,is_fp>)   , brigand::true_  );
  STF_TYPE_IS( (boost::dispatch::behave_as<foo<bar<foo<void>>>,is_fp>), brigand::false_ );
}
