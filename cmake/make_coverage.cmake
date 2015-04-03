##==================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================
include(compilers)

##==================================================================================================
## Process a list of source files to generate corresponding coverage target
##==================================================================================================
function(make_coverage root)

  if(DEFINED COVERAGE_SUPPORTED)

    foreach(file ${ARGN})

      string(REPLACE ".cpp" ".coverage" base ${file})
      set(test "${root}.${base}")

      add_executable(${test} ${file})

      set_property(TARGET ${test} PROPERTY COMPILE_FLAGS  ${CMAKE_CXX_FLAGS_COVERAGE}       )
      set_property(TARGET ${test} PROPERTY LINK_FLAGS     ${CMAKE_EXE_LINKER_FLAGS_COVERAGE})

      add_test(${test} ${test})
      add_dependencies(coverage ${test})

    endforeach()

  endif()

endfunction()
