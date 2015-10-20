//==================================================================================================
/*!
  @file

  Defines the downgrade meta-function

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_DISPATCH_META_DETAIL_UPDOWNGRADE_HPP_INCLUDED
#define BOOST_DISPATCH_META_DETAIL_UPDOWNGRADE_HPP_INCLUDED

#include <boost/dispatch/meta/primitive_of.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/dispatch/meta/sign_of.hpp>
#include <boost/dispatch/meta/make_integer.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/meta/apply_sign.hpp>
#include <boost/dispatch/detail/brigand.hpp>

namespace boost { namespace dispatch { namespace detail
{
  template<typename T,typename Sign,typename Map> struct updowngrade
  {
    // Decompose in factory/primitive
    using f_t = boost::dispatch::factory_of<T>;
    using p_t = boost::dispatch::primitive_of_t<T>;

    // Use the unsigned the primitive to limit the map's size
    using b_t  = boost::dispatch::as_unsigned_t<p_t>;
    using db_t = brigand::at<Map,b_t>;

    // Reapply sign and reconstruct
    using d_t  = boost::dispatch::apply_sign_t<db_t,Sign>;
    using type = typename f_t::template apply<d_t>::type;
  };
} } }

#endif
