##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      hierarchy_of.cpp
      models.cpp
      parent.cpp
      property_of.cpp
    )

make_unit( "hierarchy" ${SOURCES})
make_coverage("hierarchy" ${SOURCES})
