##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      boost_array.cpp
      boost_fusion.cpp
      iterator.cpp
      parent.cpp
      pointer.cpp
      std_array.cpp
      std_integral_constant.cpp
      std_tuple.cpp
    )

make_unit( "adapted" ${SOURCES})
make_coverage("adapted" ${SOURCES})
