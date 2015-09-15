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

#include <stf.hpp>

STF_CASE_TPL ( "Downgradable integral types turn into their prev-of-kind"
                , (std::uint16_t)(std::uint32_t)(std::uint64_t)
                  (std::int16_t)(std::int32_t)(std::int64_t)
                )
{
  using          result_type = boost::dispatch::downgrade<T>;
  using   signed_result_type = boost::dispatch::downgrade<T,signed>;
  using unsigned_result_type = boost::dispatch::downgrade<T,unsigned>;

  STF_TYPE_IS( boost::dispatch::downgrade<T&>      , result_type );
  STF_TYPE_IS( boost::dispatch::downgrade<T&&>     , result_type );
  STF_TYPE_IS( boost::dispatch::downgrade<T const> , result_type );
  STF_TYPE_IS( boost::dispatch::downgrade<T const&>, result_type );

  STF_TYPE_IS( boost::dispatch::sign_of<         result_type>, boost::dispatch::sign_of<T> );
  STF_TYPE_IS( boost::dispatch::sign_of<  signed_result_type>, signed                      );
  STF_TYPE_IS( boost::dispatch::sign_of<unsigned_result_type>, unsigned                    );

  STF_EXPECT( sizeof(result_type)          == sizeof(T)/2);
  STF_EXPECT( sizeof(signed_result_type)   == sizeof(T)/2);
  STF_EXPECT( sizeof(unsigned_result_type) == sizeof(T)/2);
}

STF_CASE_TPL ( "Bottom integral types stay put"
                , (std::int8_t)(std::uint8_t)
                )
{
  using          result_type = boost::dispatch::downgrade<T>;
  using   signed_result_type = boost::dispatch::downgrade<T,signed>;
  using unsigned_result_type = boost::dispatch::downgrade<T,unsigned>;

  STF_TYPE_IS( boost::dispatch::downgrade<T&>      , result_type );
  STF_TYPE_IS( boost::dispatch::downgrade<T&&>     , result_type );
  STF_TYPE_IS( boost::dispatch::downgrade<T const> , result_type );
  STF_TYPE_IS( boost::dispatch::downgrade<T const&>, result_type );

  STF_TYPE_IS( boost::dispatch::sign_of<         result_type>, boost::dispatch::sign_of<T> );
  STF_TYPE_IS( boost::dispatch::sign_of<  signed_result_type>, signed                      );
  STF_TYPE_IS( boost::dispatch::sign_of<unsigned_result_type>, unsigned                    );

  STF_EXPECT( sizeof(result_type)          == sizeof(T));
  STF_EXPECT( sizeof(signed_result_type)   == sizeof(T));
  STF_EXPECT( sizeof(unsigned_result_type) == sizeof(T));
}

STF_CASE("Downgrading bool leads to bool")
{
  STF_TYPE_IS( boost::dispatch::downgrade<bool>           , bool );
  STF_TYPE_IS( boost::dispatch::downgrade<bool&>          , bool );
  STF_TYPE_IS( boost::dispatch::downgrade<bool&&>         , bool );
  STF_TYPE_IS( boost::dispatch::downgrade<bool const>     , bool );
  STF_TYPE_IS( boost::dispatch::downgrade<bool const&>    , bool );
  STF_TYPE_IS( (boost::dispatch::downgrade<bool,signed>)  , bool );
  STF_TYPE_IS( (boost::dispatch::downgrade<bool,unsigned>), bool );
}

STF_CASE("Downgrading float leads to float")
{
  STF_TYPE_IS( boost::dispatch::downgrade<float>           , float );
  STF_TYPE_IS( boost::dispatch::downgrade<float&>          , float );
  STF_TYPE_IS( boost::dispatch::downgrade<float&&>         , float );
  STF_TYPE_IS( boost::dispatch::downgrade<float const>     , float );
  STF_TYPE_IS( boost::dispatch::downgrade<float const&>    , float );
  STF_TYPE_IS( (boost::dispatch::downgrade<float,signed>)  , float );
  STF_TYPE_IS( (boost::dispatch::downgrade<float,unsigned>), float );
}

STF_CASE("Upgrading double leads to float")
{
  STF_TYPE_IS( boost::dispatch::downgrade<double>           , float );
  STF_TYPE_IS( boost::dispatch::downgrade<double&>          , float );
  STF_TYPE_IS( boost::dispatch::downgrade<double&&>         , float );
  STF_TYPE_IS( boost::dispatch::downgrade<double const>     , float );
  STF_TYPE_IS( boost::dispatch::downgrade<double const&>    , float );
  STF_TYPE_IS( (boost::dispatch::downgrade<double,signed>)  , float );
  STF_TYPE_IS( (boost::dispatch::downgrade<double,unsigned>), float );
}

template<typename T> struct foo {};

STF_CASE_TPL ( "Downgrading sees through template layer"
                , (std::uint16_t)(std::uint32_t)(std::uint64_t)(std::uint64_t)
                  (std::int16_t)(std::int32_t)(std::int64_t)(std::int64_t)
                  (double)
                )
{
  using u_t = boost::dispatch::downgrade<T>;

  STF_TYPE_IS( boost::dispatch::downgrade<foo<T>>          , foo<u_t> );
  STF_TYPE_IS( boost::dispatch::downgrade<foo<foo<T>>>     , foo<foo<u_t>> );
  STF_TYPE_IS( boost::dispatch::downgrade<foo<foo<foo<T>>>>, foo<foo<foo<u_t>>> );
}
