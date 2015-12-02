//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/transfer_qualifiers.hpp>
#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "Check if nothing get transfered")
{
  STF_TYPE_IS( (transfer_qualifiers_t<int, float>)        , int       );
  STF_TYPE_IS( (transfer_qualifiers_t<int&, float>)       , int&      );
  STF_TYPE_IS( (transfer_qualifiers_t<int&&, float>)      , int&&     );
  STF_TYPE_IS( (transfer_qualifiers_t<int const, float>)  , int const );
  STF_TYPE_IS( (transfer_qualifiers_t<int const&, float>) , int const&);
}

STF_CASE( "Check if 'const' get transfered")
{
  STF_TYPE_IS( (transfer_qualifiers_t<int, float const>)        , int const   );
  STF_TYPE_IS( (transfer_qualifiers_t<int&, float const>)       , int&        );
  STF_TYPE_IS( (transfer_qualifiers_t<int&&, float const>)      , int&&       );
  STF_TYPE_IS( (transfer_qualifiers_t<int const, float const>)  , int const   );
  STF_TYPE_IS( (transfer_qualifiers_t<int const&, float const>) , int const&  );
}

STF_CASE( "Check if 'const&' get transfered")
{
  STF_TYPE_IS( (transfer_qualifiers_t<int, float const&>)       , int const&  );
  STF_TYPE_IS( (transfer_qualifiers_t<int&, float const&>)      , int&        );
  STF_TYPE_IS( (transfer_qualifiers_t<int&&, float const&>)     , int&        );
  STF_TYPE_IS( (transfer_qualifiers_t<int const, float const&>) , int const&  );
  STF_TYPE_IS( (transfer_qualifiers_t<int const&, float const&>), int const&  );
}

STF_CASE( "Check if '&' get transfered")
{
  STF_TYPE_IS( (transfer_qualifiers_t<int, float&>)       , int&      );
  STF_TYPE_IS( (transfer_qualifiers_t<int&, float&>)      , int&      );
  STF_TYPE_IS( (transfer_qualifiers_t<int&&, float&>)     , int&      );
  STF_TYPE_IS( (transfer_qualifiers_t<int const, float&>) , int const&);
  STF_TYPE_IS( (transfer_qualifiers_t<int const&, float&>), int const&);
}

STF_CASE( "Check if '&&' get transfered")
{
  STF_TYPE_IS( (transfer_qualifiers_t<int, float &&>)       , int &&      );
  STF_TYPE_IS( (transfer_qualifiers_t<int&, float &&>)      , int&        );
  STF_TYPE_IS( (transfer_qualifiers_t<int&&, float &&>)     , int&&       );
  STF_TYPE_IS( (transfer_qualifiers_t<int const, float &&>) , int const&& );
  STF_TYPE_IS( (transfer_qualifiers_t<int const&, float &&>), int const&  );
}
