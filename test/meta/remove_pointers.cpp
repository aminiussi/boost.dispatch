//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/remove_pointers.hpp>
#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "remove_pointers always return raw type")
{
  STF_TYPE_IS( remove_pointers<float>::type        , float        );
  STF_TYPE_IS( remove_pointers<float&>::type       , float&       );
  STF_TYPE_IS( remove_pointers<float&&>::type      , float&&      );
  STF_TYPE_IS( remove_pointers<float const>::type  , float const  );
  STF_TYPE_IS( remove_pointers<float const&>::type , float const& );

  STF_TYPE_IS( remove_pointers<float*       >::type , float       );
  STF_TYPE_IS( remove_pointers<float const* >::type , float const );
  STF_TYPE_IS( remove_pointers<float**      >::type , float       );
  STF_TYPE_IS( remove_pointers<float const**>::type , float const );

  STF_TYPE_IS( remove_pointers<float****************>::type , float );
}
