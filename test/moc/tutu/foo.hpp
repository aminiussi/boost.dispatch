//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef TUTU_FOO_INCLUDED
#define TUTU_FOO_INCLUDED

#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include "moc/tutu.hpp"

namespace tutu { namespace titi
{
  namespace tag { BOOST_DISPATCH_MAKE_TAG(foo_,boost::dispatch::elementwise_<foo_>); }
  namespace ext { BOOST_DISPATCH_FUNCTION_DECLARATION(tag,foo_); }

  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::foo_,foo);
} }

#include "moc/arch/default/foo.hpp"
#include "moc/arch/tutu/foo.hpp"
#include "moc/arch/toto/foo.hpp"

#endif
