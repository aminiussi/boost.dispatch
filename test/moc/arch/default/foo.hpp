//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef ARCH_DEFAULT_FOO_INCLUDED
#define ARCH_DEFAULT_FOO_INCLUDED

#include <boost/dispatch/hierarchy/cpu.hpp>
#include <boost/dispatch/hierarchy/base.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_OVERLOAD_FALLBACK( (typename F, typename A, typename T)
                                  , function_<F> const&
                                  , unspecified_<A> const&
                                  , scalar_<unspecified_<T>> const&
                                  )
  {
    T operator()(T const& x) { return x/10; }
  };
} } }

#endif
