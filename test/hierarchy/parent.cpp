//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/adapted/std/array.hpp>
#include <boost/dispatch/meta/sign_of.hpp>
#include <cstdint>
#include <cstddef>
#include <array>

#include <dispatch_test.hpp>

using namespace boost::dispatch;

STF_CASE( "Parenthood of base hierarchies" )
{
  STF_TYPE_IS( type_<void>::parent    , unknown_<void>  );
  STF_TYPE_IS( cpu_::parent           , formal_         );
}

STF_CASE( "Parenthood of function object hierarchies" )
{
  STF_TYPE_IS( function_<void>::parent, unspecified_<void>  );
  STF_TYPE_IS( elementwise_<void>::parent            , function_<void> );
  STF_TYPE_IS( (reduction_<void,void,void>::parent)  , function_<void> );
  STF_TYPE_IS( (cumulative_<void,void,void>::parent) , function_<void> );
}

STF_CASE( "Parenthood of void hierarchy" )
{
  STF_TYPE_IS( void_<void>::parent        , fundamental_<void> );
  STF_TYPE_IS( fundamental_<void>::parent , unspecified_<void> );
  STF_TYPE_IS( unspecified_<void>::parent , type_<void>        );
}

STF_CASE( "Parenthood of bool hierarchy" )
{
  STF_TYPE_IS( bool_<bool>::parent        , fundamental_<bool> );
  STF_TYPE_IS( fundamental_<bool>::parent , unspecified_<bool> );
  STF_TYPE_IS( unspecified_<bool>::parent , type_<bool>        );
}

STF_CASE( "Parenthood of scalar_ hierarchy" )
{
  STF_TYPE_IS( scalar_<bool_<bool>>::parent         , scalar_<bool_<bool>::parent>        );
  STF_TYPE_IS( scalar_<fundamental_<bool>>::parent  , scalar_<fundamental_<bool>::parent> );
  STF_TYPE_IS( scalar_<unspecified_<bool>>::parent  , generic_<bool_<bool>>               );
  STF_TYPE_IS( generic_<unspecified_<bool>>::parent , unspecified_<bool>                  );
}

STF_CASE( "Parenthood of IEEE types hierarchy" )
{
  STF_TYPE_IS( single_<float>::parent      , type32_<float>      );
  STF_TYPE_IS( type32_<float>::parent      , floating_<float>    );
  STF_TYPE_IS( floating_<float>::parent    , signed_<float>      );
  STF_TYPE_IS( signed_<float>::parent      , arithmetic_<float>  );
  STF_TYPE_IS( arithmetic_<float>::parent  , fundamental_<float> );
  STF_TYPE_IS( fundamental_<float>::parent , unspecified_<float> );
  STF_TYPE_IS( unspecified_<float>::parent , type_<float>        );

  STF_TYPE_IS( double_<double>::parent      , type64_<double>      );
  STF_TYPE_IS( type64_<double>::parent      , floating_<double>    );
  STF_TYPE_IS( floating_<double>::parent    , signed_<double>      );
  STF_TYPE_IS( signed_<double>::parent      , arithmetic_<double>  );
  STF_TYPE_IS( arithmetic_<double>::parent  , fundamental_<double> );
  STF_TYPE_IS( fundamental_<double>::parent , unspecified_<double> );
  STF_TYPE_IS( unspecified_<double>::parent , type_<double>        );
}

STF_CASE_TPL( "Parenthood of integral types hierarchy"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)
              (unsigned char)(unsigned short)(unsigned int)
              (unsigned long)(unsigned long long)
              (char)(short)(int)(long)(long long)
            )
{
  STF_TYPE_IS( (typename integral_<T,8*sizeof(T),sign_of_t<T>>::parent), (ints_<T,8*sizeof(T)>));
  STF_TYPE_IS( (typename ints_<T,8*sizeof(T)>::parent), (sized_type_<T,8*sizeof(T)>));
  STF_TYPE_IS( (typename sized_type_<T,8*sizeof(T)>::parent), (signed_integral_<T,sign_of_t<T>>));
  STF_TYPE_IS( (typename signed_integral_<T,sign_of_t<T>>::parent), (signed_type_<T,sign_of_t<T>>));
  STF_TYPE_IS( (typename signed_type_<T,sign_of_t<T>>::parent), integer_<T> );
  STF_TYPE_IS(  typename integer_<T>::parent     , arithmetic_<T>  );
  STF_TYPE_IS(  typename arithmetic_<T>::parent  , fundamental_<T> );
  STF_TYPE_IS(  typename fundamental_<T>::parent , unspecified_<T> );
  STF_TYPE_IS(  typename unspecified_<T>::parent , type_<T>        );
}
