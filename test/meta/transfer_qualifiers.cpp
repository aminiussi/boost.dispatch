//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/transfer_qualifiers.hpp>

#include <stf.hpp>

STF_CASE( "Check if nothing get transfered")
{
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int, float>)        , int       );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&, float>)       , int&      );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&&, float>)      , int&&     );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const, float>)  , int const );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const&, float>) , int const&);
}

STF_CASE( "Check if 'const' get transfered")
{
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int, float const>)        , int const   );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&, float const>)       , int&        );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&&, float const>)      , int&&       );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const, float const>)  , int const   );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const&, float const>) , int const&  );
}

STF_CASE( "Check if 'const&' get transfered")
{
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int, float const&>)       , int const&  );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&, float const&>)      , int&        );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&&, float const&>)     , int&        );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const, float const&>) , int const&  );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const&, float const&>), int const&  );
}

STF_CASE( "Check if '&' get transfered")
{
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int, float&>)       , int&      );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&, float&>)      , int&      );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&&, float&>)     , int&      );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const, float&>) , int const&);
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const&, float&>), int const&);
}

STF_CASE( "Check if '&&' get transfered")
{
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int, float &&>)       , int &&      );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&, float &&>)      , int&        );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int&&, float &&>)     , int&&       );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const, float &&>) , int const&& );
  STF_TYPE_IS( (boost::dispatch::transfer_qualifiers<int const&, float &&>), int const&  );
}
