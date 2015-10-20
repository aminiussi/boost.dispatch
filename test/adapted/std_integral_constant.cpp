//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/integral_constant.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/primitive_of.hpp>
#include <type_traits>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "factory_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  STF_TYPE_IS( (factory_of<base>::apply<int>::type), (std::integral_constant<int,69>) );
}

STF_CASE( "model_of of std::integral_constant<T,N> is std::integral_constant<_,N>")
{
  STF_TYPE_IS ( (model_of<std::integral_constant<char,69>>::apply<int>::type)
              , (std::integral_constant<int,69>)
              );

  STF_TYPE_IS ( (model_of<std::integral_constant<char,69>&>::apply<int>::type)
              , (std::integral_constant<int,69>)
              );

  STF_TYPE_IS ( (model_of<std::integral_constant<char,69>&&>::apply<int>::type)
              , (std::integral_constant<int,69>)
              );

  STF_TYPE_IS ( (model_of<std::integral_constant<char,69> const>::apply<int>::type)
              , (std::integral_constant<int,69>)
              );

  STF_TYPE_IS ( (model_of<std::integral_constant<char,69> const&>::apply<int>::type)
              , (std::integral_constant<int,69>)
              );
}

STF_CASE( "value_of of std::integral_constant<T,N> is T")
{
  STF_TYPE_IS( (value_of_t<std::integral_constant<int,69>>)       , int         );
  STF_TYPE_IS( (value_of_t<std::integral_constant<int,69> const>) , int const   );
  STF_TYPE_IS( (value_of_t<std::integral_constant<int,69>&>)      , int&        );
  STF_TYPE_IS( (value_of_t<std::integral_constant<int,69> const&>), int const&  );
  STF_TYPE_IS( (value_of_t<std::integral_constant<int,69>&&>)     , int&&       );
}

STF_CASE( "primitive_of of std::integral_constant<T,N> is T")
{
  STF_TYPE_IS( (primitive_of_t<std::integral_constant<int,69>>)       , int         );
  STF_TYPE_IS( (primitive_of_t<std::integral_constant<int,69>&>)      , int&        );
  STF_TYPE_IS( (primitive_of_t<std::integral_constant<int,69>&&>)     , int&&       );
  STF_TYPE_IS( (primitive_of_t<std::integral_constant<int,69> const>) , int const   );
  STF_TYPE_IS( (primitive_of_t<std::integral_constant<int,69> const&>), int const&  );
}

STF_CASE( "property_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  STF_TYPE_IS( (property_of_t<base>), (int8_<base>) );
}

STF_CASE( "hierarchy_of over std::integral_constant<T,N>")
{
  using base = std::integral_constant<char,69>;

  STF_TYPE_IS( (hierarchy_of_t<base>)                   , (constant_<int8_<base>>)  );
  STF_TYPE_IS( (constant_<int8_<base>>::parent)       , (constant_<ints8_<base>>) );
  STF_TYPE_IS( (constant_<unspecified_<base>>::parent), (scalar_<int8_<base>>)    );
}
