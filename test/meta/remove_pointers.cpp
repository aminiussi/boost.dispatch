//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/remove_pointers.hpp>
#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "remove_pointers on non-pointer is identity")
{
  STF_TYPE_IS( remove_pointers<float>::type        , float        );
  STF_TYPE_IS( remove_pointers<float&>::type       , float&       );
  STF_TYPE_IS( remove_pointers<float&&>::type      , float&&      );
  STF_TYPE_IS( remove_pointers<float const>::type  , float const  );
  STF_TYPE_IS( remove_pointers<float const&>::type , float const& );
}

STF_CASE( "remove_pointers handles const/volatile")
{
  STF_TYPE_IS( remove_pointers<float        *       >::type , float       );
  STF_TYPE_IS( remove_pointers<float const  *       >::type , float const );
  STF_TYPE_IS( remove_pointers<float        * const >::type , float );
  STF_TYPE_IS( remove_pointers<float  const * const >::type , float const);

  STF_TYPE_IS( remove_pointers<volatile float*          >::type , volatile float  );
  STF_TYPE_IS( remove_pointers<volatile float*  const   >::type , volatile float  );
  STF_TYPE_IS( remove_pointers<         float*  volatile>::type , float           );
  STF_TYPE_IS( remove_pointers<volatile float*  volatile>::type , volatile float  );
  STF_TYPE_IS( remove_pointers<const    float*  volatile>::type , const    float  );
  STF_TYPE_IS( remove_pointers<volatile const float* volatile const>::type , const volatile float  );

  STF_TYPE_IS( remove_pointers<float**      >::type , float       );
  STF_TYPE_IS( remove_pointers<float const**>::type , float const );
  STF_TYPE_IS( remove_pointers<float const* const>::type , float const );

  STF_TYPE_IS( remove_pointers<float*       >::type     , float           );
  STF_TYPE_IS( remove_pointers<volatile float* >::type  , float volatile  );
  STF_TYPE_IS( remove_pointers<float**      >::type     , float           );
  STF_TYPE_IS( remove_pointers<float volatile**>::type  , float volatile  );
}

STF_CASE( "scary cases for remove_pointers")
{
  STF_TYPE_IS( remove_pointers<float****************>::type , float );
  STF_TYPE_IS( remove_pointers<float const*const*volatile const*const***volatile**>::type , float const);
}
