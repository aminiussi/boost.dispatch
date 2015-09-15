//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/integral_constant.hpp>
#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <type_traits>

#include <stf.hpp>

STF_CASE( "factory_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  STF_TYPE_IS( (boost::dispatch::factory_of<base>::apply<int>)
                , (std::integral_constant<int,69>)
                );
}

STF_CASE( "model_of of std::integral_constant<T,N> is std::integral_constant<_,N>")
{
  STF_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69>>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69>&>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69>&&>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69> const>::apply<int>)
                , (std::integral_constant<int,69>)
                );

  STF_TYPE_IS( (boost::dispatch::model_of<std::integral_constant<char,69> const&>::apply<int>)
                , (std::integral_constant<int,69>)
                );
}

STF_CASE( "value_of of std::integral_constant<T,N> is T")
{
  STF_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69>>)
                , int
                );

  STF_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69> const>)
                , int const
                );

  STF_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69>&>)
                , int&
                );

  STF_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69> const&>)
                , int const&
                );

  STF_TYPE_IS( (boost::dispatch::value_of<std::integral_constant<int,69>&&>)
                , int&&
                );
}

STF_CASE( "primitive_of of std::array<T,N> is T")
{
  STF_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69>>)
                , int
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69>&>)
                , int&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69>&&>)
                , int&&
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69> const>)
                , int const
                );

  STF_TYPE_IS( (boost::dispatch::primitive_of<std::integral_constant<int,69> const&>)
                , int const&
                );
}

STF_CASE( "property_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  STF_TYPE_IS( (boost::dispatch::property_of<base>)
                , (boost::dispatch::int8_<base>)
                );
}

STF_CASE( "hierarchy_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  STF_TYPE_IS( (boost::dispatch::hierarchy_of<base>)
                , (boost::dispatch::constant_<boost::dispatch::int8_<base>>)
                );

  STF_TYPE_IS( (boost::dispatch::constant_<boost::dispatch::int8_<base>>::parent)
                , (boost::dispatch::constant_<boost::dispatch::ints8_<base>>)
                );

  STF_TYPE_IS( (boost::dispatch::constant_<boost::dispatch::unspecified_<base>>::parent)
                , (boost::dispatch::scalar_<boost::dispatch::int8_<base>>)
                );
}
