//==================================================================================================
/*
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/adapted/std/iterator.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/primitive_of.hpp>
#include <boost/dispatch/property_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <forward_list>
#include <vector>
#include <list>

#include <stf.hpp>

using namespace boost::dispatch;

STF_CASE_TPL( "value_of of Container<T>::iterator is T"
            , (std::vector<float>::iterator)
              (std::list<float>::iterator)
              (std::forward_list<float>::iterator)
              (std::istream_iterator<float>)
            )
{
  STF_TYPE_IS( (value_of_t<T>)        , float );
  STF_TYPE_IS( (value_of_t<T const>)  , float const );
  STF_TYPE_IS( (value_of_t<T&>)       , float& );
  STF_TYPE_IS( (value_of_t<T const&>) , float const& );
  STF_TYPE_IS( (value_of_t<T&&>)      , float&& );
}

STF_CASE_TPL( "value_of of Container<T>::const_iterator is T"
            , (std::vector<float>)(std::list<float>)(std::forward_list<float>)
            )
{
  STF_TYPE_IS( (value_of_t<typename T::const_iterator>)        , float );
  STF_TYPE_IS( (value_of_t<typename T::const_iterator const>)  , float const );
  STF_TYPE_IS( (value_of_t<typename T::const_iterator&>)       , float& );
  STF_TYPE_IS( (value_of_t<typename T::const_iterator const&>) , float const& );
  STF_TYPE_IS( (value_of_t<typename T::const_iterator&&>)      , float&& );
}

STF_CASE_TPL( "value_of of Container<T>::reverse_iterator is T"
            , (std::vector<float>)(std::list<float>)
            )
{
  STF_TYPE_IS( (value_of_t<typename T::reverse_iterator>)        , float );
  STF_TYPE_IS( (value_of_t<typename T::reverse_iterator const>)  , float const );
  STF_TYPE_IS( (value_of_t<typename T::reverse_iterator&>)       , float& );
  STF_TYPE_IS( (value_of_t<typename T::reverse_iterator const&>) , float const& );
  STF_TYPE_IS( (value_of_t<typename T::reverse_iterator&&>)      , float&& );
}

STF_CASE_TPL( "value_of of Container<T>::const_reverse_iterator is T"
            , (std::vector<float>)(std::list<float>)
            )
{
  STF_TYPE_IS( (value_of_t<typename T::const_reverse_iterator>)        , float );
  STF_TYPE_IS( (value_of_t<typename T::const_reverse_iterator const>)  , float const );
  STF_TYPE_IS( (value_of_t<typename T::const_reverse_iterator&>)       , float& );
  STF_TYPE_IS( (value_of_t<typename T::const_reverse_iterator const&>) , float const& );
  STF_TYPE_IS( (value_of_t<typename T::const_reverse_iterator&&>)      , float&& );
}

STF_CASE_TPL( "primitive_of of Container<T>::iterator is T"
            , (std::vector<float>::iterator)
              (std::list<float>::iterator)
              (std::forward_list<float>::iterator)
              (std::istream_iterator<float>)
            )
{
  STF_TYPE_IS( (primitive_of_t<T>)        , float );
  STF_TYPE_IS( (primitive_of_t<T const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<T&>)       , float& );
  STF_TYPE_IS( (primitive_of_t<T const&>) , float const& );
  STF_TYPE_IS( (primitive_of_t<T&&>)      , float&& );
}

STF_CASE_TPL( "primitive_of of Container<T>::const_iterator is T"
            , (std::vector<float>)(std::list<float>)(std::forward_list<float>)
            )
{
  STF_TYPE_IS( (primitive_of_t<typename T::const_iterator>)        , float );
  STF_TYPE_IS( (primitive_of_t<typename T::const_iterator const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<typename T::const_iterator&>)       , float& );
  STF_TYPE_IS( (primitive_of_t<typename T::const_iterator const&>) , float const& );
  STF_TYPE_IS( (primitive_of_t<typename T::const_iterator&&>)      , float&& );
}

STF_CASE_TPL( "primitive_of of Container<T>::reverse_iterator is T"
            , (std::vector<float>)(std::list<float>)
            )
{
  STF_TYPE_IS( (primitive_of_t<typename T::reverse_iterator>)        , float );
  STF_TYPE_IS( (primitive_of_t<typename T::reverse_iterator const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<typename T::reverse_iterator&>)       , float& );
  STF_TYPE_IS( (primitive_of_t<typename T::reverse_iterator const&>) , float const& );
  STF_TYPE_IS( (primitive_of_t<typename T::reverse_iterator&&>)      , float&& );
}

STF_CASE_TPL( "primitive_of of Container<T>::const_reverse_iterator is T"
            , (std::vector<float>)(std::list<float>)
            )
{
  STF_TYPE_IS( (primitive_of_t<typename T::const_reverse_iterator>)        , float );
  STF_TYPE_IS( (primitive_of_t<typename T::const_reverse_iterator const>)  , float const );
  STF_TYPE_IS( (primitive_of_t<typename T::const_reverse_iterator&>)       , float& );
  STF_TYPE_IS( (primitive_of_t<typename T::const_reverse_iterator const&>) , float const& );
  STF_TYPE_IS( (primitive_of_t<typename T::const_reverse_iterator&&>)      , float&& );
}

STF_CASE_TPL( "property_of over Container<T>::??_iterator is property_of T"
            , (std::vector<float>::iterator)
              (std::list<float>::iterator)
              (std::forward_list<float>::iterator)
              (std::istream_iterator<float>)
            )
{
  STF_TYPE_IS( (property_of_t<T>), (single_<T>));
}

STF_CASE( "hierarchy_of over Container<T>::??_iterator depends on their category" )
{
  STF_TYPE_IS (hierarchy_of_t<std::vector<float>::iterator>
              , random_access_iterator_<scalar_<single_<std::vector<float>::iterator>>>
              );

  STF_TYPE_IS (hierarchy_of_t<std::list<float>::iterator>
              , bidirectional_iterator_<scalar_<single_<std::list<float>::iterator>>>
              );

  STF_TYPE_IS (hierarchy_of_t<std::forward_list<float>::iterator>
              , forward_iterator_<scalar_<single_<std::forward_list<float>::iterator>>>
              );

  STF_TYPE_IS (hierarchy_of_t<std::istream_iterator<float>>
              , input_iterator_<scalar_<single_<std::istream_iterator<float>>>>
              );

  STF_TYPE_IS (hierarchy_of_t<std::ostream_iterator<float>>
              , output_iterator_<scalar_<void_<std::ostream_iterator<float>>>>
              );
}

