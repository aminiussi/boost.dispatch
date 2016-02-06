//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/boost/array.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/primitive_of.hpp>
#include <boost/array.hpp>

#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "factory_of over boost::array<T,N>")
{
  using base = boost::array<boost::array<boost::array<float,7>,5>,3>;

  STF_TYPE_IS ( (factory_of<base>::apply<int*>::type)
              , (boost::array<boost::array<boost::array<int*,7>,5>,3>)
              );
}

STF_CASE( "model_of of boost::array<T,N> is boost::array<_,N>")
{
  STF_TYPE_IS ( (model_of<boost::array<float,3>>::apply<int>::type)
                , (boost::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<boost::array<float,3>&>::apply<int>::type)
              , (boost::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<boost::array<float,3>&&>::apply<int>::type)
              , (boost::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<boost::array<float,3> const>::apply<int>::type)
              , (boost::array<int,3>)
              );

  STF_TYPE_IS ( (model_of<boost::array<float,3> const&>::apply<int>::type)
              , (boost::array<int,3>)
              );
}

STF_CASE( "value_of of boost::array<T,N> is T")
{
  STF_TYPE_IS( (value_of_t<boost::array<float,3>>)        , float );
  STF_TYPE_IS( (value_of_t<boost::array<float,3> const>)  , float const );
  STF_TYPE_IS( (value_of_t<boost::array<float,3>&>)       , float& );
  STF_TYPE_IS( (value_of_t<boost::array<float,3> const&>) , float const& );
  STF_TYPE_IS( (value_of_t<boost::array<float,3>&&>)      , float&& );

  STF_TYPE_IS ( (value_of_t<boost::array<boost::array<int,3>,5>>)
              , (boost::array<int,3>)
              );

  STF_TYPE_IS ( (value_of_t<boost::array<boost::array<int,3>,5>&>)
              , (boost::array<int,3>&)
              );

  STF_TYPE_IS ( (value_of_t<boost::array<boost::array<int,3>,5> const>)
              , (boost::array<int,3> const)
              );

  STF_TYPE_IS ( (value_of_t<boost::array<boost::array<int,3>,5> const&>)
              , (boost::array<int,3> const&)
              );

  STF_TYPE_IS ( (value_of_t<boost::array<boost::array<int,3>,5>&&>)
              , (boost::array<int,3>&&)
              );
}

STF_CASE( "primitive_of of boost::array<T,N> is T")
{
  STF_TYPE_IS( (primitive_of_t<boost::array<float,3>>)        , float       );
  STF_TYPE_IS( (primitive_of_t<boost::array<float,3>&>)       , float&      );
  STF_TYPE_IS( (primitive_of_t<boost::array<float,3>&&>)      , float&&     );
  STF_TYPE_IS( (primitive_of_t<boost::array<float,3> const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<boost::array<float,3> const&>) , float const&);

  STF_TYPE_IS ( (primitive_of_t<boost::array<boost::array<float,5>,3>>)
              , float
              );

  STF_TYPE_IS ( (primitive_of_t<boost::array<boost::array<float,5>,3>&>)
              , float&
              );

  STF_TYPE_IS ( (primitive_of_t<boost::array<boost::array<float,5>,3>&&>)
              , float&&
              );

  STF_TYPE_IS ( (primitive_of_t<boost::array<boost::array<float,5>,3> const>)
              , float const
              );

  STF_TYPE_IS ( (primitive_of_t<boost::array<boost::array<float,5>,3> const&>)
              , float const&
              );
}

STF_CASE( "property_of over boost::array<T,N>")
{
  using base = boost::array<boost::array<boost::array<float,7>,5>,3>;

  STF_TYPE_IS( (property_of_t<base>), (single_<base>));
}

STF_CASE( "hierarchy_of over boost::array<T,N>")
{
  using base1 = boost::array<float,7>;
  using base2 = boost::array<base1,5>;

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
