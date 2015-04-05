##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

##===================================================================================================
## Macro to add a new external dependency
##===================================================================================================
include(ExternalProject)

set( dep_path "${CMAKE_CURRENT_BINARY_DIR}/_deps")

FUNCTION(register_dependency name root)
  ExternalProject_Add (  ${name}
                        GIT_REPOSITORY "${root}"
                        PREFIX "${dep_path}"
                        INSTALL_DIR "${dep_path}"
                        CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${dep_path}"
                      )
ENDFUNCTION()
