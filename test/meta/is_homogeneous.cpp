//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/is_homogeneous.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/vector.hpp>
#include <stf.hpp>
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

STF_CASE( "check for homogeneity on adapted FusionSequence" )
{
  STF_EXPECT_NOT( boost::dispatch::is_homogeneous<bar::foo>::value );
  STF_EXPECT( boost::dispatch::is_homogeneous<bar::foo2>::value );
}

STF_CASE( "check for homogeneity for actual FusionSequence" )
{
  STF_EXPECT_NOT((boost::dispatch::is_homogeneous<boost::fusion::vector<>>::value));
  STF_EXPECT_NOT((boost::dispatch::is_homogeneous<boost::fusion::vector<char,void*,int>>::value));
  STF_EXPECT((boost::dispatch::is_homogeneous<boost::fusion::vector<int,int,int>>::value));
  STF_EXPECT((boost::dispatch::is_homogeneous<boost::fusion::vector<double>>::value));
}

STF_CASE( "check for homogeneity on std::tuple" )
{
  STF_EXPECT_NOT((boost::dispatch::is_homogeneous<std::tuple<>>::value));
  STF_EXPECT_NOT((boost::dispatch::is_homogeneous<std::tuple<char,void*,int>>::value));
  STF_EXPECT((boost::dispatch::is_homogeneous<std::tuple<int,int,int>>::value));
  STF_EXPECT((boost::dispatch::is_homogeneous<std::tuple<float>>::value));
}
