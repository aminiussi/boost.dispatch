##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(make_unit)
include(make_coverage)

set ( SOURCES
      parent.cpp
    )

make_unit( "boost.dispatch.hierarchy" ${SOURCES})
make_coverage("boost.dispatch.hierarchy" ${SOURCES})
