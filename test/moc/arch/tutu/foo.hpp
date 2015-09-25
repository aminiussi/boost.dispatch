//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef ARCH_TUTU_FOO_INCLUDED
#define ARCH_TUTU_FOO_INCLUDED

namespace tutu { namespace titi { namespace ext
{
  struct int8_foo
  {
    template<typename T> char operator()( T ) const { return '#'; }
  };

  template<typename T>
  int8_foo BOOST_DISPATCH_IMPLEMENTS( foo_
                                    , boost::dispatch::cpu_ const&
                                    , boost::dispatch::scalar_<boost::dispatch::int8_<T>> const&
                                    )
  {
    return {};
  }

  struct bob
  {
    template<typename T> char operator()(T) const { return 'Z'; }
  };

  template<typename T>
  bob BOOST_DISPATCH_IMPLEMENTS ( foo_
                                , wazoo const&
                                , boost::dispatch::scalar_<boost::dispatch::int8_<T>> const&
                                )
  {
    return {};
  }
} } }

#endif
