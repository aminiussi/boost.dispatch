//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/adapted/std/array.hpp>
#include <cstdint>
#include <cstddef>
#include <array>

#include <stf.hpp>

STF_CASE ( "Parenthood of tuple types hierarchy" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( ( typename tuple_ < std::tuple<int,char,short>
                                    , std::integral_constant<std::size_t,3>
                                    >::parent
                  )
                , (unspecified_<std::tuple<int,char,short>>)
                );
}

STF_CASE ( "Parenthood of array types hierarchy" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS( ( typename array_ < int8_<std::array<char,3>>
                                    , std::integral_constant<std::size_t,3>
                                    >::parent
                  )
                , (array_ < ints8_<std::array<char,3>>
                          , std::integral_constant<std::size_t,3>
                          >)
                );

  STF_TYPE_IS( ( typename array_ < unspecified_<std::array<char,3>>
                                    , std::integral_constant<std::size_t,3>
                                    >::parent)
                , (bag_ < property_of<std::array<char,3>>
                        , std::integral_constant<std::size_t,3>
                        >
                  )
                );

  using B = std::array<std::array<char,3>,3>;

  STF_TYPE_IS( ( typename array_ < array_<unspecified_<B>,std::integral_constant<std::size_t,3>>
                                    , std::integral_constant<std::size_t,3>
                                    >::parent)
                , (array_ < bag_<property_of<B>,std::integral_constant<std::size_t,3>>
                          , std::integral_constant<std::size_t,3>
                          >
                  )
                );
}
