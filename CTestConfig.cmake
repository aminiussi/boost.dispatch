################################################################################
#         Copyright 2012 - 2015 NumScale SAS
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
set(CTEST_PROJECT_NAME "Boost.Dispatch")
set(CTEST_NIGHTLY_START_TIME "00:00:00 CEST")
set(CTEST_TEST_TIMEOUT "600")

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "cdash.lri.fr")
set(CTEST_DROP_LOCATION "/submit.php?project=boost.dispatch")
set(CTEST_DROP_SITE_CDASH TRUE)

if(CMAKE_PROJECT_NAME STREQUAL Boost.Dispatch)
  set(SOURCE_DIRECTORY ${PROJECT_SOURCE_DIR})
else()
  get_filename_component(SOURCE_DIRECTORY ${CTEST_SOURCE_DIRECTORY} ABSOLUTE)
endif()

#set(CTEST_MEMORYCHECK_SUPPRESSIONS_FILE ${SOURCE_DIRECTORY}/valgrind.supp)
#list(APPEND CTEST_CUSTOM_WARNING_EXCEPTION "You are using gcc version \".*\"")
#list(APPEND CTEST_CUSTOM_WARNING_EXCEPTION "[0-9]+ shortened to [0-9]+")
#list(APPEND CTEST_CUSTOM_WARNING_EXCEPTION ".*anonymous.* may be used uninitialized in this function")
#list(APPEND CTEST_CUSTOM_WARNING_EXCEPTION "The ABI for passing parameters with [0-9]+-byte alignment has changed")
#list(APPEND CTEST_CUSTOM_WARNING_EXCEPTION "GCC vector passed by reference: non-standard ABI extension with no compatibility guarantee")

# Note: In order to have CTest ignore these limits and not truncate the test
#       output, the string "CTEST_FULL_OUTPUT" has to be output by the test
#       (e.g., as first line of the test output to stdout).
# See:  http://public.kitware.com/pipermail/cdash/2009-November/000589.html
#set(CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE "1048576")
#set(CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE "102400")

# SITE is host name
execute_process(COMMAND hostname OUTPUT_VARIABLE HOST OUTPUT_STRIP_TRAILING_WHITESPACE)
string(REGEX REPLACE "\\.(local|home)$" "" HOST ${HOST})
string(TOLOWER ${HOST} SITE)

# BUILDNAME is generated from OS, architecture, compiler and SIMD level (in-project only)
if(CMAKE_PROJECT_NAME STREQUAL Boost.Dispatch)
  set(OS ${CMAKE_SYSTEM_NAME})

  string(TOLOWER ${CMAKE_CXX_COMPILER_ID} COMPILER)
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+).*" "\\1" VERSION_MAJOR "${CMAKE_CXX_COMPILER_VERSION}")
  string(REGEX REPLACE "([0-9]+)\\.([0-9]+).*" "\\2" VERSION_MINOR "${CMAKE_CXX_COMPILER_VERSION}")

  # Compiler version is that of cl.exe, we convert it to MSVC
  if(MSVC AND VERSION_MAJOR)
    math(EXPR VERSION_MAJOR "${VERSION_MAJOR} - 6")
  endif()

  if(VERSION_MINOR)
    set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR})
  else()
    set(VERSION ${VERSION_MAJOR})
  endif()
  set(COMPILER "${COMPILER}${VERSION}")

  set(BUILDNAME "${OS}-${COMPILER}")
  file(WRITE ${PROJECT_BINARY_DIR}/CTestConfigData.cmake "set(BUILDNAME ${BUILDNAME})\nset(CTEST_USE_LAUNCHERS ${CTEST_USE_LAUNCHERS})")

else()
# outside of project, we load a file
  set(PROJECT_SOURCE_DIR ${CTEST_SOURCE_DIRECTORY})
  set(PROJECT_BINARY_DIR ${CTEST_BINARY_DIRECTORY})
  include(${PROJECT_BINARY_DIR}/CTestConfigData.cmake)
endif()

# We add branch tag if necessary
find_package(Git QUIET)
if(GIT_EXECUTABLE)
  execute_process(COMMAND ${GIT_EXECUTABLE} symbolic-ref HEAD
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                  OUTPUT_VARIABLE BRANCH OUTPUT_STRIP_TRAILING_WHITESPACE
                  RESULT_VARIABLE BRANCH_RESULT ERROR_QUIET
                 )
  if(NOT BRANCH_RESULT)
   string(REGEX REPLACE "^.+/([^/]+)$" "\\1" BRANCH ${BRANCH})
  else()
    set(BRANCH "dirty")
  endif()

  if(NOT BRANCH STREQUAL "master")
    set(BUILDNAME "${BUILDNAME}-${BRANCH}")
  endif()
endif()

set(CTEST_SITE ${SITE})
set(CTEST_BUILD_NAME ${BUILDNAME})
