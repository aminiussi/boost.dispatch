//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/array.hpp>
#include <boost/dispatch/meta/introspection.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <array>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "factory_of over std::array<T,N>")
{
  using base = std::array<std::array<std::array<float,7>,5>,3>;

  NSTEST_TYPE_IS( (boost::dispatch::factory_of<base>::apply<int*>)
                , (std::array<std::array<std::array<int*,7>,5>,3>)
                );
}

NSTEST_CASE( "model_of of std::array<T,N> is std::array<_,N>")
{
  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::array<float,3>>::apply<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::array<float,3>&>::apply<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::array<float,3>&&>::apply<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::array<float,3> const>::apply<int>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::model_of<std::array<float,3> const&>::apply<int>)
                , (std::array<int,3>)
                );
}

NSTEST_CASE( "value_of of std::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<float,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<float,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<float,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<float,3> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<float,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<std::array<int,3>,5>>)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<std::array<int,3>,5>&>)
                , (std::array<int,3>&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<std::array<int,3>,5> const>)
                , (std::array<int,3> const)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<std::array<int,3>,5> const&>)
                , (std::array<int,3> const&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::value_of<std::array<std::array<int,3>,5>&&>)
                , (std::array<int,3>&&)
                );
}

NSTEST_CASE( "primitive_of of std::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<float,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<float,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<float,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<float,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<float,3> const&>)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<std::array<float,5>,3>>)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<std::array<float,5>,3>&>)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<std::array<float,5>,3>&&>)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<std::array<float,5>,3> const>)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::primitive_of<std::array<std::array<float,5>,3> const&>)
                , float const&
                );
}

NSTEST_CASE( "property_of over std::array<T,N>")
{
  using base = std::array<std::array<std::array<float,7>,5>,3>;

  NSTEST_TYPE_IS( (boost::dispatch::property_of<base>)
                , (boost::dispatch::single_<base>)
                );
}

NSTEST_CASE( "hierarchy_of over std::array<T,N>")
{
  using base1 = std::array<float,7>;
  using base2 = std::array<base1,5>;

  NSTEST_TYPE_IS( (boost::dispatch::hierarchy_of<base1>)
                , (boost::dispatch::array_< boost::dispatch::scalar_<boost::dispatch::single_<base1>>
                                          , std::integral_constant<std::size_t,7>
                                          >
                  )
                );

  NSTEST_TYPE_IS( (boost::dispatch::hierarchy_of<base2>)
                , ( boost::dispatch::array_
                    < boost::dispatch::array_ < boost::dispatch::scalar_<boost::dispatch::single_<base2>>
                                              , std::integral_constant<std::size_t,7>
                                              >
                    , std::integral_constant<std::size_t,5>
                    >
                  )
                );
}
