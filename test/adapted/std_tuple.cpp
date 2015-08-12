//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/tuple.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <tuple>

#include <nstest.hpp>

NSTEST_CASE( "hierarchy_of over std::tuple<T...>")
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( hierarchy_of<std::tuple<>>
                , ( tuple_< std::tuple<>
                          , std::integral_constant<std::size_t,0u>
                          >
                  )
                );

  NSTEST_TYPE_IS( (hierarchy_of<std::tuple<int,void*,char,std::size_t*,float[4]>>)
                , ( tuple_< std::tuple<int,void*,char,std::size_t*,float[4]>
                          , std::integral_constant<std::size_t, 5u>
                          >
                  )
                );

  NSTEST_TYPE_IS( hierarchy_of<std::tuple<int>>
                , ( bag_< int32_<std::tuple<int>>
                        , std::integral_constant<std::size_t, 1u>
                        >
                  )
                );

  NSTEST_TYPE_IS( (hierarchy_of<std::tuple<int,int,int,int,int>>)
                , ( bag_< int32_<std::tuple<int,int,int,int,int>>
                        , std::integral_constant<std::size_t, 5u>
                        >
                  )
                );
}
