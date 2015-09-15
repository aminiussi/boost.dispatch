//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/make_floating.hpp>

#include <stf.hpp>

STF_CASE( "Generate raw floating point types")
{
  STF_TYPE_IS( (boost::dispatch::make_floating<8>) , double );
  STF_TYPE_IS( (boost::dispatch::make_floating<4>) , float  );
}

template<typename T> using ptr_t  =T*;

STF_CASE( "Generate transformed floating point types")
{
  STF_TYPE_IS( (boost::dispatch::make_floating<8,ptr_t>) , double* );
  STF_TYPE_IS( (boost::dispatch::make_floating<4,ptr_t>) , float*  );
}
