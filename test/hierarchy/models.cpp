//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/hierarchy/scalar.hpp>
#include <boost/dispatch/hierarchy/void.hpp>
#include <boost/dispatch/hierarchy/bool.hpp>
#include <boost/dispatch/hierarchy/base.hpp>
#include <boost/dispatch/models.hpp>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/types.hpp>

template<typename T> using sv = boost::dispatch::scalar_<boost::dispatch::void_<T>>;
template<typename T> using sb = boost::dispatch::scalar_<boost::dispatch::bool_<T>>;

NSTEST_CASE( "Check for correct hierarchy modeling" )
{
  using namespace boost::dispatch;

  NSTEST_TYPE_IS( (models<void,sv>)           , std::true_type );
  NSTEST_TYPE_IS( (models<void,sb>)           , std::false_type );
  NSTEST_TYPE_IS( (models<void,unspecified_>) , std::true_type );
  NSTEST_TYPE_IS( (models<void,type_>)        , std::true_type );

  NSTEST_TYPE_IS( (models<bool,sv>)           , std::false_type );
  NSTEST_TYPE_IS( (models<bool,sb>)           , std::true_type );
  NSTEST_TYPE_IS( (models<bool,unspecified_>) , std::true_type );
  NSTEST_TYPE_IS( (models<bool,type_>)        , std::true_type );
}
