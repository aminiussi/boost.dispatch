//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/integral_constant.hpp>
#include <boost/dispatch/meta/introspection.hpp>
#include <type_traits>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "factory_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  NSTEST_TYPE_IS( (boost::dispatch::factory_of<base>::apply<int>)
                , (std::integral_constant<int,69>)
                );
}

NSTEST_CASE( "model_of of std::integral_constant<T,N> is std::integral_constant<_,N>")
{
  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69>>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69>&>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69>&&>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69> const>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69> const&>::apply<int>)
                , (std::integral_constant<int,69>)
                );
}

NSTEST_CASE( "value_of of std::integral_constant<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69>>)
                , int
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69> const>)
                , int const
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69>&>)
                , int&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69> const&>)
                , int const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69>&&>)
                , int&&
                );
}

NSTEST_CASE( "primitive_of of std::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69>>)
                , int
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69>&>)
                , int&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69>&&>)
                , int&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69> const>)
                , int const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69> const&>)
                , int const&
                );
}
