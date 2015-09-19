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
  template<typename T> struct impl_foo_<boost::dispatch::scalar_<boost::dispatch::int_<T>>>
  {
    float operator()( T ) const { return -13.37f; }
  };

  struct dub
  {
    template<typename T> T operator()(T const& x) { return x*11; }
  };


  template<typename F, typename T>
  dub dispatching ( adl_helper const& , boost::dispatch::elementwise_<F> const&
                                      , boost::dispatch::cpu_ const&
                                      , boost::dispatch::scalar_<boost::dispatch::integer_<T>> const&
                  )
  {
    return {};
  }

  template<typename T>
  impl_foo_<boost::dispatch::scalar_<boost::dispatch::int_<T>>>
  dispatching_foo_( adl_helper const&, boost::dispatch::cpu_ const&
                  , boost::dispatch::scalar_<boost::dispatch::int_<T>> const&
                  )
  {
    return {};
  }

} } }

#endif
