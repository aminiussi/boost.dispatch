//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/array.hpp>
#include <array>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE( "model_of of std::array<T,N> is std::array<_,N>")
{
  NSTEST_TYPE_IS( (boost::mpl::apply< boost::dispatch::meta::model_of<std::array<float,3>>::type
                                    , int
                                    >::type
                  )
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::mpl::apply< boost::dispatch::meta::model_of<std::array<float,3>&>::type
                                    , int
                                    >::type
                  )
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::mpl::apply< boost::dispatch::meta::model_of<std::array<float,3>&&>::type
                                    , int
                                    >::type
                  )
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::mpl::apply< boost::dispatch::meta::model_of<std::array<float,3> const>::type
                                    , int
                                    >::type
                  )
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::mpl::apply< boost::dispatch::meta::model_of<std::array<float,3> const& >::type
                                    , int
                                    >::type
                  )
                , (std::array<int,3>)
                );
}

NSTEST_CASE( "value_of of std::array<T,N> is T")
{
  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<float,3>>::type)
                , float
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<float,3> const>::type)
                , float const
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<float,3>&>::type)
                , float&
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<float,3> const&>::type)
                , float const&
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<float,3>&&>::type)
                , float&&
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<std::array<int,3>,5>>::type)
                , (std::array<int,3>)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<std::array<int,3>,5>&>::type)
                , (std::array<int,3>&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<std::array<int,3>,5> const>::type)
                , (std::array<int,3> const)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<std::array<int,3>,5> const&>::type)
                , (std::array<int,3> const&)
                );

  NSTEST_TYPE_IS( (boost::dispatch::meta::value_of<std::array<std::array<int,3>,5>&&>::type)
                , (std::array<int,3>&&)
                );
}
