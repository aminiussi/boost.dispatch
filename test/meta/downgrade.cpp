//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/generation/downgrade.hpp>
#include <boost/dispatch/meta/introspection/sign_of.hpp>
#include <type_traits>
#include <cstdint>

#include <nstest/unit.hpp>
#include <nstest/unit/tests/basic.hpp>
#include <nstest/unit/tests/types.hpp>

NSTEST_CASE_TPL ( "Downgradable integral types turn into their prev-of-kind"
                , (std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int16_t)(std::int32_t)(std::int64_t)
                )
{
  using          result_type = boost::dispatch::downgrade<T>;
  using   signed_result_type = boost::dispatch::downgrade<T,signed>;
  using unsigned_result_type = boost::dispatch::downgrade<T,unsigned>;

  NSTEST_TYPE_IS( boost::dispatch::downgrade<T&>      , result_type );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<T&&>     , result_type );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<T const> , result_type );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<T const&>, result_type );

  NSTEST_TYPE_IS( boost::dispatch::sign_of<         result_type>, boost::dispatch::sign_of<T> );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<  signed_result_type>, signed                      );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<unsigned_result_type>, unsigned                    );

  NSTEST_EXPECT( sizeof(result_type)          == sizeof(T)/2);
  NSTEST_EXPECT( sizeof(signed_result_type)   == sizeof(T)/2);
  NSTEST_EXPECT( sizeof(unsigned_result_type) == sizeof(T)/2);
}

NSTEST_CASE_TPL ( "Bottom integral types stay put"
                , (std::int8_t)(std::uint8_t)
                )
{
  using          result_type = boost::dispatch::downgrade<T>;
  using   signed_result_type = boost::dispatch::downgrade<T,signed>;
  using unsigned_result_type = boost::dispatch::downgrade<T,unsigned>;

  NSTEST_TYPE_IS( boost::dispatch::downgrade<T&>      , result_type );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<T&&>     , result_type );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<T const> , result_type );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<T const&>, result_type );

  NSTEST_TYPE_IS( boost::dispatch::sign_of<         result_type>, boost::dispatch::sign_of<T> );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<  signed_result_type>, signed                      );
  NSTEST_TYPE_IS( boost::dispatch::sign_of<unsigned_result_type>, unsigned                    );

  NSTEST_EXPECT( sizeof(result_type)          == sizeof(T));
  NSTEST_EXPECT( sizeof(signed_result_type)   == sizeof(T));
  NSTEST_EXPECT( sizeof(unsigned_result_type) == sizeof(T));
}

NSTEST_CASE("Downgrading bool leads to bool")
{
  NSTEST_TYPE_IS( boost::dispatch::downgrade<bool>           , bool );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<bool&>          , bool );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<bool&&>         , bool );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<bool const>     , bool );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<bool const&>    , bool );
  NSTEST_TYPE_IS( (boost::dispatch::downgrade<bool,signed>)  , bool );
  NSTEST_TYPE_IS( (boost::dispatch::downgrade<bool,unsigned>), bool );
}

NSTEST_CASE("Downgrading float leads to float")
{
  NSTEST_TYPE_IS( boost::dispatch::downgrade<float>           , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<float&>          , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<float&&>         , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<float const>     , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<float const&>    , float );
  NSTEST_TYPE_IS( (boost::dispatch::downgrade<float,signed>)  , float );
  NSTEST_TYPE_IS( (boost::dispatch::downgrade<float,unsigned>), float );
}

NSTEST_CASE("Upgrading double leads to float")
{
  NSTEST_TYPE_IS( boost::dispatch::downgrade<double>           , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<double&>          , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<double&&>         , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<double const>     , float );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<double const&>    , float );
  NSTEST_TYPE_IS( (boost::dispatch::downgrade<double,signed>)  , float );
  NSTEST_TYPE_IS( (boost::dispatch::downgrade<double,unsigned>), float );
}

template<typename T> struct foo {};

NSTEST_CASE_TPL ( "Downgrading sees through template layer"
                , (std::uint16_t)(std::uint32_t)(std::uint64_t)(std::uint64_t)
                  (std::int16_t)(std::int32_t)(std::int64_t)(std::int64_t)
                  (double)
                )
{
  using u_t = boost::dispatch::downgrade<T>;

  NSTEST_TYPE_IS( boost::dispatch::downgrade<foo<T>>          , foo<u_t> );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<foo<foo<T>>>     , foo<foo<u_t>> );
  NSTEST_TYPE_IS( boost::dispatch::downgrade<foo<foo<foo<T>>>>, foo<foo<foo<u_t>>> );
}
