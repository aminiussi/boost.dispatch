## -------------------------------------------------------------------------------------------------
##                              Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.7)

## Setup project
## -------------------------------------------------------------------------------------------------
project(Boost.Dispatch CXX)
set(PROJECT_DOC_DIR ${PROJECT_SOURCE_DIR}/doc)

## Requirements for ns.cmake:
## -------------------------------------------------------------------------------------------------
include(cmake/ns.cmake.install.cmake)
if (NOT NS_CMAKE_INSTALLED)
  return()
endif()
include(cmake/ns.cmake)
## -------------------------------------------------------------------------------------------------

## Potential warnings fixup
## -------------------------------------------------------------------------------------------------
NS_ignore(${IS_TRAVIS_CI})

## Search for packages
## -------------------------------------------------------------------------------------------------
NS_find_package(Boost 1.58 REQUIRED)
if (DEFINED IS_TRAVIS_CI)
  NS_say("You are using TRAVIS-CI, we do define GIT_EXECUTABLE as `git` as a workaround")
  set(GIT_EXECUTABLE git)
else()
  NS_find_package(Git QUIET)
endif()

##
NS_prevent_in_source_build()

## External projects
## -------------------------------------------------------------------------------------------------
set(STF_STANDALONE_DESTINATION     ${PROJECT_SOURCE_DIR}/test)
set(BRIGAND_STANDALONE_DESTINATION ${PROJECT_SOURCE_DIR}/include/boost/dispatch/detail)

#NS_project_global_destination(${PROJECT_SOURCE_DIR}/_deps)
NS_project_include(brigand.standalone)
NS_project_include(stf.standalone)

## Compute version string and mode + Documentation
## -------------------------------------------------------------------------------------------------
if (NOT DEFINED IS_TRAVIS_CI)
  NS_include(ns/parse_revision)
  NS_include(ns/doc/doxygen)
endif()

## Install target
## -------------------------------------------------------------------------------------------------
install( DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION . )

## Add include directories
## -------------------------------------------------------------------------------------------------
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/test
  ${Boost_INCLUDE_DIRS}
)

## Setup Unit & Coverage Test
## -------------------------------------------------------------------------------------------------
include(CTest)
add_custom_target(tests)
add_custom_target(unit)
add_dependencies(tests unit)
add_subdirectory(test)

if (NOT DEFINED IS_TRAVIS_CI)
  NS_include(ns/coverage)
  enable_coverage(boost.dispatch)
endif()
