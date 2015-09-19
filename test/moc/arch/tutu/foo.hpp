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
  template<typename T> struct impl_foo_<boost::dispatch::scalar_<boost::dispatch::int8_<T>>>
  {
    char operator()( T ) const { return '#'; }
  };

  struct bob
  {
    template<typename T> char operator()(T) const { return 'Z'; }
  };

  template<typename T>
  impl_foo_<boost::dispatch::scalar_<boost::dispatch::int8_<T>>>
  dispatching_foo_( adl_helper const&, boost::dispatch::cpu_ const&
                  , boost::dispatch::scalar_<boost::dispatch::int8_<T>> const&
                  )
  {
    return {};
  }

  template<typename T>
  bob
  dispatching_foo_( adl_helper const&, wazoo const&
                  , boost::dispatch::scalar_<boost::dispatch::int8_<T>> const&
                  )
  {
    return {};
  }
} } }

#endif
