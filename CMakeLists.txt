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
set(DEPS_DIR        ${CMAKE_BINARY_DIR}/_deps)
set(PROJECT_DOC_DIR ${PROJECT_SOURCE_DIR}/doc)

## ns.cmake
## -------------------------------------------------------------------------------------------------
set(NS_CMAKE     ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ns.cmake)
set(NS_CMAKE_URL https://raw.githubusercontent.com/NumScale/ns.scripts/master/cmake/ns.cmake)

if (NOT EXISTS ${NS_CMAKE})
  file(DOWNLOAD  ${NS_CMAKE_URL} ${NS_CMAKE})
endif()
include(${NS_CMAKE})

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

##
NS_add_cmake_path(${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## External projects
## -------------------------------------------------------------------------------------------------
NS_add_project(NS_SCRIPTS
  GIT_REPOSITORY https://github.com/NumScale/ns.scripts.git
  GIT_TAG        master
  DESTINATION    ${DEPS_DIR}

  STEP_TARGETS   install
  EXCLUDE_FROM_ALL
)

NS_add_project(STF
  GIT_REPOSITORY https://github.com/jfalcou/stf.git
  GIT_TAG        master
  DESTINATION    ${DEPS_DIR}

  STEP_TARGETS   configure
  EXCLUDE_FROM_ALL
)

NS_add_project(BRIGAND
  GIT_REPOSITORY https://github.com/edouarda/brigand.git
  GIT_TAG        master
  DESTINATION    ${DEPS_DIR}

  STEP_TARGETS   configure
  EXCLUDE_FROM_ALL
)

## Custom external project's targets
## -------------------------------------------------------------------------------------------------

set(STF_STANDALONE     ${PROJECT_SOURCE_DIR}/test/stf.hpp)
set(BRIGAND_STANDALONE ${PROJECT_SOURCE_DIR}/include/boost/dispatch/detail/brigand.hpp)
set(NS_SCRIPTS_CMAKE   ${PROJECT_SOURCE_DIR}/cmake)

set(EXTERNAL_PROJECTS_SOURCES
  ${STF_STANDALONE}
  ${BRIGAND_STANDALONE}
  ${NS_SCRIPTS_CMAKE}
)

## -------------------------------------------------------------------------------------------------

add_custom_target(update.ns.scripts
  DEPENDS ${NS_SCRIPTS_INSTALL_TARGET}
)
add_custom_command(
  TARGET  update.ns.scripts
  COMMENT "Updating ns.scripts"
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${DEPS_DIR}/cmake
    ${PROJECT_SOURCE_DIR}/cmake
)

## -------------------------------------------------------------------------------------------------

add_custom_target(update.stf
  DEPENDS ${STF_CONFIGURE_TARGET}
)
add_custom_command(
  TARGET  update.stf
  COMMAND ${CMAKE_COMMAND} --build . --target standalone
  WORKING_DIRECTORY ${STF_BUILD_DIR}
)
add_custom_command(
  TARGET  update.stf
  COMMENT "Updating STF"
  COMMAND ${CMAKE_COMMAND} -E copy
    ${STF_SOURCE_DIR}/standalone/stf.hpp
    ${STF_STANDALONE}
)

## -------------------------------------------------------------------------------------------------

add_custom_target(update.brigand
  DEPENDS ${BRIGAND_CONFIGURE_TARGET}
)
add_custom_command(
  TARGET  update.brigand
  COMMAND ${CMAKE_COMMAND} --build . --target standalone
  WORKING_DIRECTORY ${BRIGAND_BUILD_DIR}
)
add_custom_command(
  TARGET  update.brigand
  COMMENT "Updating brigand"
  COMMAND ${CMAKE_COMMAND} -E copy
    ${BRIGAND_SOURCE_DIR}/standalone/brigand.hpp
    ${BRIGAND_STANDALONE}
)

## -------------------------------------------------------------------------------------------------

## Master target to update everything
add_custom_target(update
  DEPENDS
    update.check
    ## ---------
    update.brigand
    update.ns.scripts
    update.stf
)
add_custom_command(
  TARGET update
  COMMAND
    ${CMAKE_COMMAND} -E compare_files ${DEPS_DIR}/null ${DEPS_DIR}/update.diff
    ||
    \( ${GIT_EXECUTABLE} reset
    && ${GIT_EXECUTABLE} add ${EXTERNAL_PROJECTS_SOURCES}
    && ${GIT_EXECUTABLE} commit -m "auto: Update external projects" --no-verify
    \)
)

file(WRITE ${DEPS_DIR}/null "")
## Master target to check update for all projects
add_custom_target(update.check)
add_custom_command(
  TARGET  update.check
  COMMENT "Checking updates: Creating diff"
  COMMAND
       ${GIT_EXECUTABLE} reset
    && ${GIT_EXECUTABLE} -C ${PROJECT_SOURCE_DIR} --no-pager diff ${EXTERNAL_PROJECTS_SOURCES}
    >  ${DEPS_DIR}/update.diff
)
add_custom_command(
  TARGET  update.check
  COMMENT "Checking updates: Check if anything have changed"
  COMMAND
    ${CMAKE_COMMAND} -E compare_files ${DEPS_DIR}/null ${DEPS_DIR}/update.diff
    && ${CMAKE_COMMAND} -E echo "-- External projects: ARE UP TO DATE!"
    || ${CMAKE_COMMAND} -E echo "-- External projects: NEED UPDATES!"
)

## -------------------------------------------------------------------------------------------------

## Now first init the cmake if external projects are needed at cmake time!
## -------------------------------------------------------------------------------------------------
if (DEFINED CMAKE_INIT)
  add_custom_target(init DEPENDS update)
  return()
endif()

## Compute version string and mode + Documentation
## -------------------------------------------------------------------------------------------------
if (NOT DEFINED IS_TRAVIS_CI)
  include(parse_revision)
  include(doc)
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
  include(coverage)
  enable_coverage(boost.dispatch)
endif()
