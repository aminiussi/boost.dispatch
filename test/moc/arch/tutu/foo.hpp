//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef ARCH_TUTU_FOO_INCLUDED
#define ARCH_TUTU_FOO_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace tutu { namespace titi { namespace ext
{
  BOOST_DISPATCH_OVERLOAD ( foo_
                          , (typename T)
                          , boost::dispatch::cpu_
                          , boost::dispatch::scalar_<boost::dispatch::int8_<T>>
                          )
  {
    char operator()( T const& ) const BOOST_NOEXCEPT{ return '#'; }
  };

  BOOST_DISPATCH_OVERLOAD ( foo_
                          , (typename T)
                          , wazoo
                          , boost::dispatch::scalar_<boost::dispatch::int8_<T>>
                          )
  {
    char operator()(T) const { return 'Z'; }
  };

  BOOST_DISPATCH_OVERLOAD ( foo_
                          , (typename T,typename U)
                          , wazoo
                          , boost::dispatch::scalar_<boost::dispatch::int8_<T>>
                          , boost::dispatch::scalar_<boost::dispatch::int_<U>>
                          )
  {
    char operator()(T a, U b) const { return a+char(b); }
  };
} } }

#endif
