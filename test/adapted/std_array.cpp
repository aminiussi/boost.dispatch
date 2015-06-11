//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/array.hpp>
#include <boost/dispatch/meta/primitive_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <array>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "model_of of std::array<T,N> is std::array<_,N>")
{
  NSTEST_TYPE_IS( (boost::dispatch::meta::model_of<std::array<float,3>>::type<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::model_of<std::array<float,3>&>::type<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::model_of<std::array<float,3>&&>::type<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::model_of<std::array<float,3> const>::type<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::model_of<std::array<float,3> const&>::type<int>)
                , (std::array<int,3>)
                );
}

NSTEST_CASE( "value_of of std::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<float,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<float,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<float,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<float,3> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<float,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<std::array<int,3>,5>>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<std::array<int,3>,5>&>)
                , (std::array<int,3>&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<std::array<int,3>,5> const>)
                , (std::array<int,3> const)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<std::array<int,3>,5> const&>)
                , (std::array<int,3> const&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of_t<std::array<std::array<int,3>,5>&&>)
                , (std::array<int,3>&&)
                );
}

NSTEST_CASE( "primitive_of of std::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<float,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<float,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<float,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<float,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<float,3> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<std::array<float,5>,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<std::array<float,5>,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<std::array<float,5>,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<std::array<float,5>,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of_t<std::array<std::array<float,5>,3> const&>)
                , float const&
                );
}
