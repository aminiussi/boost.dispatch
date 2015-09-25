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
  struct dub
  {
    template<typename T> T operator()(T const& x) { return x*11; }
  };


  template<typename F, typename T>
  dub BOOST_DISPATCH_FALLBACK ( boost::dispatch::elementwise_<F> const&
                              , boost::dispatch::cpu_ const&
                              , boost::dispatch::scalar_<boost::dispatch::integer_<T>> const&
                              )
  {
    return {};
  }

  struct int_foo
  {
    template<typename T> float operator()( T ) const { return -13.37f; }
  };

  template<typename T>
  int_foo BOOST_DISPATCH_IMPLEMENTS ( foo_
                                    , boost::dispatch::cpu_ const&
                                    , boost::dispatch::scalar_<boost::dispatch::int_<T>> const&
                                    )
  {
    return {};
  }

} } }

#endif
