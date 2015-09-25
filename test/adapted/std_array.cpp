//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/array.hpp>
#include <boost/dispatch/meta/introspection/factory_of.hpp>
#include <boost/dispatch/meta/introspection/model_of.hpp>
#include <boost/dispatch/meta/introspection/value_of.hpp>
#include <boost/dispatch/meta/introspection/primitive_of.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <array>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "factory_of over std::array<T,N>")
{
  using base = std::array<std::array<std::array<float,7>,5>,3>;

  STF_TYPE_IS ( (factory_of<base>::apply<int*>::type)
              , (std::array<std::array<std::array<int*,7>,5>,3>)
              );
}

STF_CASE( "model_of of std::array<T,N> is std::array<_,N>")
{
  STF_TYPE_IS ( (model_of<std::array<float,3>>::apply<int>::type)
                , (std::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<std::array<float,3>&>::apply<int>::type)
              , (std::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<std::array<float,3>&&>::apply<int>::type)
              , (std::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<std::array<float,3> const>::apply<int>::type)
              , (std::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<std::array<float,3> const&>::apply<int>::type)
              , (std::array<int,3>)
              );
}

STF_CASE( "value_of of std::array<T,N> is T")
{
  STF_TYPE_IS( (value_of_t<std::array<float,3>>)        , float );
  STF_TYPE_IS( (value_of_t<std::array<float,3> const>)  , float const );
  STF_TYPE_IS( (value_of_t<std::array<float,3>&>)       , float& );
  STF_TYPE_IS( (value_of_t<std::array<float,3> const&>) , float const& );
  STF_TYPE_IS( (value_of_t<std::array<float,3>&&>)      , float&& );

  STF_TYPE_IS ( (value_of_t<std::array<std::array<int,3>,5>>)
              , (std::array<int,3>)
              );

  STF_TYPE_IS ( (value_of_t<std::array<std::array<int,3>,5>&>)
              , (std::array<int,3>&)
              );

  STF_TYPE_IS ( (value_of_t<std::array<std::array<int,3>,5> const>)
              , (std::array<int,3> const)
              );

  STF_TYPE_IS ( (value_of_t<std::array<std::array<int,3>,5> const&>)
              , (std::array<int,3> const&)
              );

  STF_TYPE_IS ( (value_of_t<std::array<std::array<int,3>,5>&&>)
              , (std::array<int,3>&&)
              );
}

STF_CASE( "primitive_of of std::array<T,N> is T")
{
  STF_TYPE_IS( (primitive_of_t<std::array<float,3>>)        , float       );
  STF_TYPE_IS( (primitive_of_t<std::array<float,3>&>)       , float&      );
  STF_TYPE_IS( (primitive_of_t<std::array<float,3>&&>)      , float&&     );
  STF_TYPE_IS( (primitive_of_t<std::array<float,3> const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<std::array<float,3> const&>) , float const&);

  STF_TYPE_IS ( (primitive_of_t<std::array<std::array<float,5>,3>>)
              , float
              );

  STF_TYPE_IS ( (primitive_of_t<std::array<std::array<float,5>,3>&>)
              , float&
              );

  STF_TYPE_IS ( (primitive_of_t<std::array<std::array<float,5>,3>&&>)
              , float&&
              );

  STF_TYPE_IS ( (primitive_of_t<std::array<std::array<float,5>,3> const>)
              , float const
              );

  STF_TYPE_IS ( (primitive_of_t<std::array<std::array<float,5>,3> const&>)
              , float const&
              );
}

STF_CASE( "property_of over std::array<T,N>")
{
  using base = std::array<std::array<std::array<float,7>,5>,3>;

  STF_TYPE_IS( (property_of_t<base>), (single_<base>));
}

STF_CASE( "hierarchy_of over std::array<T,N>")
{
  using base1 = std::array<float,7>;
  using base2 = std::array<base1,5>;

  STF_TYPE_IS ( (hierarchy_of_t<base1>)
              , (array_ < scalar_<single_<base1>>
                        , std::integral_constant<std::size_t,7>
                        >
                )
              );

  STF_TYPE_IS ( (hierarchy_of_t<base2>)
              , ( array_
                  < array_< scalar_<single_<base2>>
                          , std::integral_constant<std::size_t,7>
                          >
                  , std::integral_constant<std::size_t,5>
                  >
                )
              );
}
