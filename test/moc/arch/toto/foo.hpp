//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef ARCH_TOTO_FOO_INCLUDED
#define ARCH_TOTO_FOO_INCLUDED

namespace tutu { namespace titi { namespace ext
{
  template<typename T> struct impl_foo<boost::dispatch::scalar_<boost::dispatch::int_<T>>>
  {
    float operator()( T ) const { return -13.37f; }
  };

  template<typename T>
  impl_foo<boost::dispatch::scalar_<boost::dispatch::int_<T>>>
  dispatching_foo_( adl_helper const&, boost::dispatch::cpu_ const&
                  , boost::dispatch::scalar_<boost::dispatch::int_<T>> const&
                  )
  {
    return {};
  }
} } }

#endif
