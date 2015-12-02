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

#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "Check for correct hierarchy modeling" )
{
  STF_TYPE_IS( (models_t<void,scalar_<void_<brigand::_1>> >), std::true_type );
  STF_TYPE_IS( (models_t<void,scalar_<bool_<brigand::_1>> >), std::false_type );
  STF_TYPE_IS( (models_t<void,unspecified_<brigand::_1>>)  , std::true_type );
  STF_TYPE_IS( (models_t<void,type_<brigand::_1>>)         , std::true_type );

  STF_TYPE_IS( (models_t<bool,scalar_<void_<brigand::_1>>>), std::false_type );
  STF_TYPE_IS( (models_t<bool,scalar_<bool_<brigand::_1>>>), std::true_type );
  STF_TYPE_IS( (models_t<bool,unspecified_<brigand::_1>>) , std::true_type );
  STF_TYPE_IS( (models_t<bool,type_<brigand::_1>>)        , std::true_type );
}
