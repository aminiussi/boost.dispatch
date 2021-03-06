//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/behave_as.hpp>
#include <boost/dispatch/detail/brigand.hpp>
#include <type_traits>
#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "behave_as of basic types is same as direct meta-function call")
{
  STF_TYPE_IS( (behave_as_t<float ,std::is_floating_point<brigand::_1>>), std::true_type  );
  STF_TYPE_IS( (behave_as_t<double,std::is_floating_point<brigand::_1>>), std::true_type  );
  STF_TYPE_IS( (behave_as_t<char  ,std::is_floating_point<brigand::_1>>), std::false_type );
  STF_TYPE_IS( (behave_as_t<void* ,std::is_floating_point<brigand::_1>>), std::false_type );
}
