//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/make_integer.hpp>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "Generate raw integer types")
{
  STF_TYPE_IS( (make_integer_t<1>)          , std::uint8_t    );
  STF_TYPE_IS( (make_integer_t<2>)          , std::uint16_t   );
  STF_TYPE_IS( (make_integer_t<4>)          , std::uint32_t   );
  STF_TYPE_IS( (make_integer_t<8>)          , std::uint64_t   );
  STF_TYPE_IS( (make_integer_t<1,unsigned>) , std::uint8_t    );
  STF_TYPE_IS( (make_integer_t<2,unsigned>) , std::uint16_t   );
  STF_TYPE_IS( (make_integer_t<4,unsigned>) , std::uint32_t   );
  STF_TYPE_IS( (make_integer_t<8,unsigned>) , std::uint64_t   );
  STF_TYPE_IS( (make_integer_t<1,signed>)   , std::int8_t     );
  STF_TYPE_IS( (make_integer_t<2,signed>)   , std::int16_t    );
  STF_TYPE_IS( (make_integer_t<4,signed>)   , std::int32_t    );
  STF_TYPE_IS( (make_integer_t<8,signed>)   , std::int64_t    );
}

using ptr_t = std::add_pointer<brigand::_1>;

STF_CASE( "Generate transformed integer types")
{
  STF_TYPE_IS( (make_integer_t<1,unsigned ,ptr_t>), std::uint8_t*   );
  STF_TYPE_IS( (make_integer_t<2,unsigned ,ptr_t>), std::uint16_t*  );
  STF_TYPE_IS( (make_integer_t<4,unsigned ,ptr_t>), std::uint32_t*  );
  STF_TYPE_IS( (make_integer_t<8,unsigned ,ptr_t>), std::uint64_t*  );
  STF_TYPE_IS( (make_integer_t<1,signed   ,ptr_t>), std::int8_t*    );
  STF_TYPE_IS( (make_integer_t<2,signed   ,ptr_t>), std::int16_t*   );
  STF_TYPE_IS( (make_integer_t<4,signed   ,ptr_t>), std::int32_t*   );
  STF_TYPE_IS( (make_integer_t<8,signed   ,ptr_t>), std::int64_t*   );
}
