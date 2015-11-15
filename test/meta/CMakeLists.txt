##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

add_definitions(-DBOOST_ENABLE_ASSERT_HANDLER)

set ( SOURCES
      apply_sign.cpp
      as_floating.cpp
      as_integer.cpp
      as_signed.cpp
      as_unsigned.cpp
      behave_as.cpp
      downgrade.cpp
      factory_of.cpp
      is_homogeneous.cpp
      is_natural.cpp
      make_floating.cpp
      make_integer.cpp
      model_of.cpp
      parent_of.cpp
      pointer_rank.cpp
      primitive_of.cpp
      scalar_of.cpp
      sign_of.cpp
      transfer_qualifiers.cpp
      upgrade.cpp
      value_of.cpp
    )

make_unit( "boost.dispatch.meta" ${SOURCES})
make_coverage("boost.dispatch.meta" ${SOURCES})
