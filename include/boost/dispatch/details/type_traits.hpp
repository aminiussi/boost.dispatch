//==================================================================================================
/*!
  @file

  Define replacement for type_traits on non-conforming compilers

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_DETAILS_TYPE_TRAITS_HPP_INCLUDED
#define BOOST_DISPATCH_DETAILS_TYPE_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>

// Provide replacement for non-conformant compilers
#if defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
#include <boost/type_traits.hpp>

namespace std
{
  using boost::integral_constant;
  using boost::true_type;
  using boost::false_type;
  using boost::is_void;
  using boost::is_integral;
  using boost::is_floating_point;
  using boost::is_array;
  using boost::is_pointer;
  using boost::is_lvalue_reference;
  using boost::is_rvalue_reference;
  using boost::is_member_object_pointer;
  using boost::is_member_function_pointer;
  using boost::is_enum;
  using boost::is_union;
  using boost::is_class;
  using boost::is_function;
  using boost::is_reference;
  using boost::is_arithmetic;
  using boost::is_fundamental;
  using boost::is_object;
  using boost::is_scalar;
  using boost::is_compound;
  using boost::is_member_pointer;
  using boost::is_const;
  using boost::is_volatile;
  using boost::is_trivial;
  using boost::is_trivially_copyable;
  using boost::is_standard_layout;
  using boost::is_pod;
  using boost::is_literal_type;
  using boost::is_empty;
  using boost::is_polymorphic;
  using boost::is_abstract;
  using boost::is_constructible;
  using boost::is_nothrow_constructible;
  using boost::is_default_constructible;
  using boost::is_copy_constructible;
  using boost::is_copy_assignable;
  using boost::is_move_constructible;
  using boost::is_move_assignable;
  using boost::is_destructible;
  using boost::is_trivially_default_constructible;
  using boost::is_trivially_copy_constructible;
  using boost::is_trivially_move_constructible;
  using boost::is_trivially_copy_assignable;
  using boost::is_trivially_move_assignable;
  using boost::is_trivially_destructible;
  using boost::is_nothrow_default_constructible;
  using boost::is_nothrow_copy_constructible;
  using boost::is_nothrow_move_constructible;
  using boost::is_nothrow_copy_assignable;
  using boost::is_nothrow_move_assignable;
  using boost::has_virtual_destructor;
  using boost::is_signed;
  using boost::is_unsigned;
  using boost::alignment_of;
  using boost::rank;
  using boost::extent;
  using boost::is_same;
  using boost::is_base_of;
  using boost::is_convertible;
  using boost::remove_const;
  using boost::remove_volatile;
  using boost::remove_cv;
  using boost::add_const;
  using boost::add_volatile;
  using boost::add_cv;
  using boost::remove_reference;
  using boost::add_lvalue_reference;
  using boost::add_rvalue_reference;
  using boost::make_signed;
  using boost::make_unsigned;
  using boost::remove_extent;
  using boost::remove_all_extents;
  using boost::remove_pointer;
  using boost::add_pointer;
  using boost::aligned_storage;
  using boost::aligned_union;
  using boost::decay;
  using boost::enable_if;
  using boost::conditional;
  using boost::common_type;
  using boost::underlying_type;
}
#else

#include <type_traits>

#endif

#endif
