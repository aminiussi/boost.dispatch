##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      as.cpp
      dispatch.cpp
    )

make_unit( "api" ${SOURCES})
make_coverage("api" ${SOURCES})
