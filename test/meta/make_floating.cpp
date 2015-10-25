//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/make_floating.hpp>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "Generate raw floating point types")
{
  STF_TYPE_IS( (make_floating_t<8>) , double );
  STF_TYPE_IS( (make_floating_t<4>) , float  );
  STF_TYPE_IS( (make_floating_t<2>) , float  );
  STF_TYPE_IS( (make_floating_t<1>) , float  );
}

using ptr_t = std::add_pointer<brigand::_1>;

STF_CASE( "Generate transformed floating point types")
{
  STF_TYPE_IS( (make_floating_t<8,ptr_t>) , double* );
  STF_TYPE_IS( (make_floating_t<4,ptr_t>) , float*  );
  STF_TYPE_IS( (make_floating_t<2,ptr_t>) , float*  );
  STF_TYPE_IS( (make_floating_t<1,ptr_t>) , float*  );
}
