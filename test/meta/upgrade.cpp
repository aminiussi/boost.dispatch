//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/dispatch/meta/sign_of.hpp>
#include <type_traits>
#include <cstdint>

#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE_TPL( "Upgradable integral types turn into their next-of-kind"
            , (bool)
              (std::uint8_t)(std::uint16_t)(std::uint32_t)
              (std::int8_t)(std::int16_t)(std::int32_t)
            )
{
  using          result_type = upgrade_t<T>;
  using   signed_result_type = upgrade_t<T,signed>;
  using unsigned_result_type = upgrade_t<T,unsigned>;

  STF_TYPE_IS( upgrade_t<T&>      , result_type );
  STF_TYPE_IS( upgrade_t<T&&>     , result_type );
  STF_TYPE_IS( upgrade_t<T const> , result_type );
  STF_TYPE_IS( upgrade_t<T const&>, result_type );

  STF_TYPE_IS( sign_of_t<         result_type>, sign_of_t<T>  );
  STF_TYPE_IS( sign_of_t<  signed_result_type>, signed        );
  STF_TYPE_IS( sign_of_t<unsigned_result_type>, unsigned      );

  STF_EXPECT( sizeof(result_type)          == 2*sizeof(T));
  STF_EXPECT( sizeof(signed_result_type)   == 2*sizeof(T));
  STF_EXPECT( sizeof(unsigned_result_type) == 2*sizeof(T));

  STF_EXPECT( is_upgradable<T>::value );
}

STF_CASE_TPL( "Top integral types stay put", (std::int64_t)(std::uint64_t) )
{
  using          result_type = upgrade_t<T>;
  using   signed_result_type = upgrade_t<T,signed>;
  using unsigned_result_type = upgrade_t<T,unsigned>;

  STF_TYPE_IS( upgrade_t<T&>      , result_type );
  STF_TYPE_IS( upgrade_t<T&&>     , result_type );
  STF_TYPE_IS( upgrade_t<T const> , result_type );
  STF_TYPE_IS( upgrade_t<T const&>, result_type );

  STF_TYPE_IS( sign_of_t<         result_type>, sign_of_t<T>  );
  STF_TYPE_IS( sign_of_t<  signed_result_type>, signed        );
  STF_TYPE_IS( sign_of_t<unsigned_result_type>, unsigned      );

  STF_EXPECT( sizeof(result_type)          == sizeof(T));
  STF_EXPECT( sizeof(signed_result_type)   == sizeof(T));
  STF_EXPECT( sizeof(unsigned_result_type) == sizeof(T));

  STF_EXPECT_NOT( is_upgradable<T>::value );
}

STF_CASE("Upgrading float leads to double")
{
  STF_TYPE_IS( upgrade_t<float>           , double );
  STF_TYPE_IS( upgrade_t<float&>          , double );
  STF_TYPE_IS( upgrade_t<float&&>         , double );
  STF_TYPE_IS( upgrade_t<float const>     , double );
  STF_TYPE_IS( upgrade_t<float const&>    , double );
  STF_TYPE_IS( (upgrade_t<float,signed>)  , double );
  STF_TYPE_IS( (upgrade_t<float,unsigned>), double );

  STF_EXPECT( is_upgradable<float>::value );
}

STF_CASE("Upgrading double leads to double")
{
  STF_TYPE_IS( upgrade_t<double>           , double );
  STF_TYPE_IS( upgrade_t<double&>          , double );
  STF_TYPE_IS( upgrade_t<double&&>         , double );
  STF_TYPE_IS( upgrade_t<double const>     , double );
  STF_TYPE_IS( upgrade_t<double const&>    , double );
  STF_TYPE_IS( (upgrade_t<double,signed>)  , double );
  STF_TYPE_IS( (upgrade_t<double,unsigned>), double );

  STF_EXPECT_NOT( is_upgradable<double>::value );
}
