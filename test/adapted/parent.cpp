//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/adapted/std/array.hpp>
#include <boost/dispatch/adapted/hierarchy/tuple.hpp>
#include <boost/dispatch/adapted/hierarchy/pointer.hpp>
#include <cstdint>
#include <cstddef>
#include <array>

#include <dispatch_test.hpp>

STF_CASE ( "Parenthood of pointer and iterator hierarchies" )
{
  using namespace boost::dispatch;

  STF_TYPE_IS ( typename pointer_<unspecified_<float*>>::parent
              , random_access_iterator_<scalar_<single_<float*>>>
              );

  STF_TYPE_IS ( typename random_access_iterator_<unspecified_<float*>>::parent
              , bidirectional_iterator_<scalar_<single_<float*>>>
              );

  STF_TYPE_IS ( typename bidirectional_iterator_<unspecified_<float*>>::parent
              , forward_iterator_<scalar_<single_<float*>>>
              );

  STF_TYPE_IS ( typename forward_iterator_<unspecified_<float*>>::parent
              , input_iterator_<scalar_<single_<float*>>>
              );
}

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
                , (bag_ < property_of_t<std::array<char,3>>
                        , std::integral_constant<std::size_t,3>
                        >
                  )
                );

  using B = std::array<std::array<char,3>,3>;

  STF_TYPE_IS( ( typename array_ < array_<unspecified_<B>,std::integral_constant<std::size_t,3>>
                                    , std::integral_constant<std::size_t,3>
                                    >::parent)
                , (array_ < bag_<property_of_t<B>,std::integral_constant<std::size_t,3>>
                          , std::integral_constant<std::size_t,3>
                          >
                  )
                );
}
