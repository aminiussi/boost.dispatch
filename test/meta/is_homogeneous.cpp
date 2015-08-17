//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/introspection/is_homogeneous.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/vector.hpp>
#include <nstest.hpp>
#include <tuple>

namespace bar
{
  struct foo
  {
    int i;
    double j;
    char k;
  };

  struct foo2
  {
    double i,j,k;
  };
}

BOOST_FUSION_ADAPT_STRUCT(bar::foo,i,j,k);
BOOST_FUSION_ADAPT_STRUCT(bar::foo2,i,j,k);

NSTEST_CASE( "check for homogeneity on adapted FusionSequence" )
{
  NSTEST_EXPECT_NOT( boost::dispatch::is_homogeneous<bar::foo>::value );
  NSTEST_EXPECT( boost::dispatch::is_homogeneous<bar::foo2>::value );
}

NSTEST_CASE( "check for homogeneity for actual FusionSequence" )
{
  NSTEST_EXPECT_NOT((boost::dispatch::is_homogeneous<boost::fusion::vector<>>::value));
  NSTEST_EXPECT_NOT((boost::dispatch::is_homogeneous<boost::fusion::vector<char,void*,int>>::value));
  NSTEST_EXPECT((boost::dispatch::is_homogeneous<boost::fusion::vector<int,int,int>>::value));
  NSTEST_EXPECT((boost::dispatch::is_homogeneous<boost::fusion::vector<double>>::value));
}

NSTEST_CASE( "check for homogeneity on std::tuple" )
{
  NSTEST_EXPECT_NOT((boost::dispatch::is_homogeneous<std::tuple<>>::value));
  NSTEST_EXPECT_NOT((boost::dispatch::is_homogeneous<std::tuple<char,void*,int>>::value));
  NSTEST_EXPECT((boost::dispatch::is_homogeneous<std::tuple<int,int,int>>::value));
  NSTEST_EXPECT((boost::dispatch::is_homogeneous<std::tuple<float>>::value));
}
