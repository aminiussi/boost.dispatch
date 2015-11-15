//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/primitive_of.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE( "factory_of over T*")
{
  using base = float***;

  STF_TYPE_IS((factory_of<base>::apply<int>::type), int***);
}

STF_CASE( "model_of of T* is _*")
{
  STF_TYPE_IS ( (model_of<float*>::apply<int>::type)        , int* );
  STF_TYPE_IS ( (model_of<float*&>::apply<int>::type)       , int* );
  STF_TYPE_IS ( (model_of<float*&&>::apply<int>::type)      , int* );
  STF_TYPE_IS ( (model_of<float* const>::apply<int>::type)  , int* );
  STF_TYPE_IS ( (model_of<float* const&>::apply<int>::type) , int* );
}

STF_CASE( "value_of of T* is T")
{
  STF_TYPE_IS( (value_of_t<float*>)        , float );
  STF_TYPE_IS( (value_of_t<float* const>)  , float const );
  STF_TYPE_IS( (value_of_t<float*&>)       , float& );
  STF_TYPE_IS( (value_of_t<float* const&>) , float const& );
  STF_TYPE_IS( (value_of_t<float*&&>)      , float&& );

  STF_TYPE_IS ( (value_of_t<int**>), int* );
  STF_TYPE_IS ( (value_of_t<int**&>), int*& );
  STF_TYPE_IS ( (value_of_t<int** const>), int* const);
  STF_TYPE_IS ( (value_of_t<int** const&>), int* const& );
  STF_TYPE_IS ( (value_of_t<int**&&>), int*&& );
}

STF_CASE( "primitive_of of T* is T")
{
  STF_TYPE_IS( (primitive_of_t<float*>)        , float       );
  STF_TYPE_IS( (primitive_of_t<float*&>)       , float&      );
  STF_TYPE_IS( (primitive_of_t<float*&&>)      , float&&     );
  STF_TYPE_IS( (primitive_of_t<float* const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<float* const&>) , float const&);

  STF_TYPE_IS ( (primitive_of_t<float**>)       , float       );
  STF_TYPE_IS ( (primitive_of_t<float**&>)      , float&      );
  STF_TYPE_IS ( (primitive_of_t<float**&&>)     , float&&     );
  STF_TYPE_IS ( (primitive_of_t<float** const>) , float const );
  STF_TYPE_IS ( (primitive_of_t<float** const&>), float const&);
}

STF_CASE( "property_of over T*")
{
  STF_TYPE_IS( (property_of_t<float***>), (single_<float***>));
}

STF_CASE( "hierarchy_of over T{*}")
{
  STF_TYPE_IS (hierarchy_of_t<float*> , (pointer_<scalar_<single_<float* >>, 1>) );
  STF_TYPE_IS (hierarchy_of_t<float**>, (pointer_<scalar_<single_<float**>>, 2>) );
  STF_TYPE_IS (hierarchy_of_t<float*****>, (pointer_<scalar_<single_<float*****>>, 5>) );
}
