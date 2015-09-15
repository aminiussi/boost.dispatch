//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/make_integer.hpp>

#include <stf.hpp>

STF_CASE( "Generate raw integer types")
{
  STF_TYPE_IS( (boost::dispatch::make_integer<1>)          , std::uint8_t    );
  STF_TYPE_IS( (boost::dispatch::make_integer<2>)          , std::uint16_t   );
  STF_TYPE_IS( (boost::dispatch::make_integer<4>)          , std::uint32_t   );
  STF_TYPE_IS( (boost::dispatch::make_integer<8>)          , std::uint64_t   );
  STF_TYPE_IS( (boost::dispatch::make_integer<1,unsigned>) , std::uint8_t    );
  STF_TYPE_IS( (boost::dispatch::make_integer<2,unsigned>) , std::uint16_t   );
  STF_TYPE_IS( (boost::dispatch::make_integer<4,unsigned>) , std::uint32_t   );
  STF_TYPE_IS( (boost::dispatch::make_integer<8,unsigned>) , std::uint64_t   );
  STF_TYPE_IS( (boost::dispatch::make_integer<1,signed>)   , std::int8_t     );
  STF_TYPE_IS( (boost::dispatch::make_integer<2,signed>)   , std::int16_t    );
  STF_TYPE_IS( (boost::dispatch::make_integer<4,signed>)   , std::int32_t    );
  STF_TYPE_IS( (boost::dispatch::make_integer<8,signed>)   , std::int64_t    );
}

template<typename T> using ptr_t  =T*;

STF_CASE( "Generate transformed integer types")
{
  STF_TYPE_IS( (boost::dispatch::make_integer<1,unsigned ,ptr_t>), std::uint8_t*   );
  STF_TYPE_IS( (boost::dispatch::make_integer<2,unsigned ,ptr_t>), std::uint16_t*  );
  STF_TYPE_IS( (boost::dispatch::make_integer<4,unsigned ,ptr_t>), std::uint32_t*  );
  STF_TYPE_IS( (boost::dispatch::make_integer<8,unsigned ,ptr_t>), std::uint64_t*  );
  STF_TYPE_IS( (boost::dispatch::make_integer<1,signed   ,ptr_t>), std::int8_t*    );
  STF_TYPE_IS( (boost::dispatch::make_integer<2,signed   ,ptr_t>), std::int16_t*   );
  STF_TYPE_IS( (boost::dispatch::make_integer<4,signed   ,ptr_t>), std::int32_t*   );
  STF_TYPE_IS( (boost::dispatch::make_integer<8,signed   ,ptr_t>), std::int64_t*   );
}
