//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/upgrade.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <type_traits>
#include <cstdint>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/basic.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE_TPL ( "Upgradable integral types turn into their next-of-kind"
                , (bool)
                  (std::uint8_t)(std::uint16_t)(std::uint32_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)
                )
{
  using          result_type = boost::dispatch::upgrade<T>;
  using   signed_result_type = boost::dispatch::upgrade<T,signed>;
  using unsigned_result_type = boost::dispatch::upgrade<T,unsigned>;

  NSTEST_TYPE_IS( boost::dispatch::upgrade<T&>      , result_type );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<T&&>     , result_type );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<T const> , result_type );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<T const&>, result_type );

  NSTEST_TYPE_IS( boost::dispatch::sign_of<         result_type>, boost::dispatch::sign_of<T> );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<  signed_result_type>, signed                      );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<unsigned_result_type>, unsigned                    );

  NSTEST_EXPECT( sizeof(result_type)          == 2*sizeof(T));
  NSTEST_EXPECT( sizeof(signed_result_type)   == 2*sizeof(T));
  NSTEST_EXPECT( sizeof(unsigned_result_type) == 2*sizeof(T));
}

NSTEST_CASE_TPL ( "Top integral types stay put"
                , (std::int64_t)(std::uint64_t)
                )
{
  using          result_type = boost::dispatch::upgrade<T>;
  using   signed_result_type = boost::dispatch::upgrade<T,signed>;
  using unsigned_result_type = boost::dispatch::upgrade<T,unsigned>;

  NSTEST_TYPE_IS( boost::dispatch::upgrade<T&>      , result_type );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<T&&>     , result_type );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<T const> , result_type );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<T const&>, result_type );

  NSTEST_TYPE_IS( boost::dispatch::sign_of<         result_type>, boost::dispatch::sign_of<T> );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<  signed_result_type>, signed                      );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<unsigned_result_type>, unsigned                    );

  NSTEST_EXPECT( sizeof(result_type)          == sizeof(T));
  NSTEST_EXPECT( sizeof(signed_result_type)   == sizeof(T));
  NSTEST_EXPECT( sizeof(unsigned_result_type) == sizeof(T));
}

NSTEST_CASE("Upgrading float leads to double")
{
  NSTEST_TYPE_IS( boost::dispatch::upgrade<float>           , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<float&>          , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<float&&>         , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<float const>     , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<float const&>    , double );
  NSTEST_TYPE_IS( (boost::dispatch::upgrade<float,signed>)  , double );
  NSTEST_TYPE_IS( (boost::dispatch::upgrade<float,unsigned>), double );
}

NSTEST_CASE("Upgrading double leads to double")
{
  NSTEST_TYPE_IS( boost::dispatch::upgrade<double>           , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<double&>          , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<double&&>         , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<double const>     , double );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<double const&>    , double );
  NSTEST_TYPE_IS( (boost::dispatch::upgrade<double,signed>)  , double );
  NSTEST_TYPE_IS( (boost::dispatch::upgrade<double,unsigned>), double );
}

template<typename T> struct foo {};

NSTEST_CASE_TPL ( "Upgrading sees through template layer"
                , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
                  (float)(double)
                )
{
  using u_t = boost::dispatch::upgrade<T>;

  NSTEST_TYPE_IS( boost::dispatch::upgrade<foo<T>>          , foo<u_t> );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<foo<foo<T>>>     , foo<foo<u_t>> );
  NSTEST_TYPE_IS( boost::dispatch::upgrade<foo<foo<foo<T>>>>, foo<foo<foo<u_t>>> );
}
