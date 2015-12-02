//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/downgrade.hpp>
#include <boost/dispatch/meta/sign_of.hpp>
#include <type_traits>
#include <cstdint>

#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE_TPL( "Downgradable integral types turn into their prev-of-kind"
            , (std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using          result_type = downgrade_t<T>;
  using   signed_result_type = downgrade_t<T,signed>;
  using unsigned_result_type = downgrade_t<T,unsigned>;

  STF_TYPE_IS( downgrade_t<T&>      , result_type );
  STF_TYPE_IS( downgrade_t<T&&>     , result_type );
  STF_TYPE_IS( downgrade_t<T const> , result_type );
  STF_TYPE_IS( downgrade_t<T const&>, result_type );

  STF_TYPE_IS( sign_of_t<         result_type>, sign_of_t<T>  );
  STF_TYPE_IS( sign_of_t<  signed_result_type>, signed        );
  STF_TYPE_IS( sign_of_t<unsigned_result_type>, unsigned      );

  STF_EXPECT( sizeof(result_type)          == sizeof(T)/2);
  STF_EXPECT( sizeof(signed_result_type)   == sizeof(T)/2);
  STF_EXPECT( sizeof(unsigned_result_type) == sizeof(T)/2);
}

STF_CASE_TPL( "Bottom integral types stay put"
            , (std::int8_t)(std::uint8_t)
            )
{
  using          result_type = downgrade_t<T>;
  using   signed_result_type = downgrade_t<T,signed>;
  using unsigned_result_type = downgrade_t<T,unsigned>;

  STF_TYPE_IS( downgrade_t<T&>      , result_type );
  STF_TYPE_IS( downgrade_t<T&&>     , result_type );
  STF_TYPE_IS( downgrade_t<T const> , result_type );
  STF_TYPE_IS( downgrade_t<T const&>, result_type );

  STF_TYPE_IS( sign_of_t<         result_type>, sign_of_t<T>  );
  STF_TYPE_IS( sign_of_t<  signed_result_type>, signed        );
  STF_TYPE_IS( sign_of_t<unsigned_result_type>, unsigned      );

  STF_EXPECT( sizeof(result_type)          == sizeof(T));
  STF_EXPECT( sizeof(signed_result_type)   == sizeof(T));
  STF_EXPECT( sizeof(unsigned_result_type) == sizeof(T));
}

STF_CASE("Downgrading bool leads to bool")
{
  STF_TYPE_IS( downgrade_t<bool>           , bool );
  STF_TYPE_IS( downgrade_t<bool&>          , bool );
  STF_TYPE_IS( downgrade_t<bool&&>         , bool );
  STF_TYPE_IS( downgrade_t<bool const>     , bool );
  STF_TYPE_IS( downgrade_t<bool const&>    , bool );
  STF_TYPE_IS( (downgrade_t<bool,signed>)  , bool );
  STF_TYPE_IS( (downgrade_t<bool,unsigned>), bool );
}

STF_CASE("Downgrading float leads to float")
{
  STF_TYPE_IS( downgrade_t<float>           , float );
  STF_TYPE_IS( downgrade_t<float&>          , float );
  STF_TYPE_IS( downgrade_t<float&&>         , float );
  STF_TYPE_IS( downgrade_t<float const>     , float );
  STF_TYPE_IS( downgrade_t<float const&>    , float );
  STF_TYPE_IS( (downgrade_t<float,signed>)  , float );
  STF_TYPE_IS( (downgrade_t<float,unsigned>), float );
}

STF_CASE("Upgrading double leads to float")
{
  STF_TYPE_IS( downgrade_t<double>           , float );
  STF_TYPE_IS( downgrade_t<double&>          , float );
  STF_TYPE_IS( downgrade_t<double&&>         , float );
  STF_TYPE_IS( downgrade_t<double const>     , float );
  STF_TYPE_IS( downgrade_t<double const&>    , float );
  STF_TYPE_IS( (downgrade_t<double,signed>)  , float );
  STF_TYPE_IS( (downgrade_t<double,unsigned>), float );
}
