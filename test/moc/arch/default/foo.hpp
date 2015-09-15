//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef ARCH_DEFAULT_FOO_INCLUDED
#define ARCH_DEFAULT_FOO_INCLUDED

#include <boost/dispatch/hierarchy/formal.hpp>

namespace boost { namespace dispatch { namespace meta
{
  struct dub
  {
    template<typename T> T operator()(T const& x) { return x/10; }
  };

  struct dub2
  {
    template<typename T> T operator()(T const& x) { return x*10; }
  };

  template<typename T>
  dub dispatching ( meta::adl_helper const& , tutu::titi::tag::foo_ const&
                                      , cpu_ const&
                                      , type_<T> const&
                  )
  {
    return {};
  }

  template<typename T>
  dub2 dispatching ( meta::adl_helper const& , tutu::titi::tag::foo_ const&
                                      , wazoo const&
                                      , type_<T> const&
                  )
  {
    return {};
  }
} } }

#endif
