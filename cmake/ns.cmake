##==================================================================================================
##                               Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

include(ExternalProject)

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

## Global get
## -------------------------------------------------------------------------------------------------
macro (NS_get_global name out)
  get_property(${out} GLOBAL PROPERTY ${name})
endmacro()

## Global set
## -------------------------------------------------------------------------------------------------
macro (NS_set_global name value)
  set_property(GLOBAL PROPERTY ${name} ${value})
endmacro()

## Guard helper
## -------------------------------------------------------------------------------------------------
macro (NS_guard name)
  NS_get_global(${name} IS_INCLUDED)
  if (${IS_INCLUDED})
    return()
  else()
    NS_set_global(${name} TRUE)
  endif()
endmacro()

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

NS_guard(NS_CMAKE_INCLUDED)

set(NS_QUIET)
#set(NS_QUIET OUTPUT_QUIET)

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

## Display all parameters
## -------------------------------------------------------------------------------------------------
function (NS_message kind)
  string(REPLACE ";" " " WHAT "${ARGN}")
  message(${kind} "[${NS_PROJECT_NAME}]: ${WHAT}")
endfunction()

## Display all parameters
## -------------------------------------------------------------------------------------------------
function (NS_say)
  NS_message(STATUS ${ARGN})
endfunction()

## Display all parameters
## -------------------------------------------------------------------------------------------------
function (NS_warn)
  NS_message(WARNING ${ARGN})
endfunction()

## Same as `NS_say` but will exit after outputting the message
## -------------------------------------------------------------------------------------------------
function (NS_error)
  NS_message(FATAL_ERROR ${ARGN})
endfunction()

## Macro to easily show `A = ${A}` where `A` is a variable
## -------------------------------------------------------------------------------------------------
macro (NS_show var)
  message(STATUS "[${NS_PROJECT_NAME}]: ${var} = ${${var}}")
endmacro()

## Enable DEBUG informations
## -------------------------------------------------------------------------------------------------
#set(NS_DEBUG false)

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

## NS_map: Helpers to manipulate associative table
## -------------------------------------------------------------------------------------------------
function (NS_map_has map key yes_or_no)
  list(FIND map ${key} INDEX)
  if ("${INDEX}" STREQUAL "-1")
    set(${yes_or_no} FALSE PARENT_SCOPE)
  else()
    set(${yes_or_no} TRUE PARENT_SCOPE)
  endif()
endfunction()

## -------------------------------------------------------------------------------------------------
function (NS_map_must_have map key)
  list(FIND map ${key} INDEX)
  if ("${INDEX}" STREQUAL "-1")
    NS_error("${map} MUST CONTAINS the following key: ${key}")
  endif()
endfunction()

## -------------------------------------------------------------------------------------------------
function (NS_map_at map key out)
  NS_map_must_have("${map}" ${key})
  list(FIND map ${key} INDEX)
  math(EXPR INDEX "${INDEX} + 1")
  list(GET map ${INDEX} OUT)
  set(${out} ${OUT} PARENT_SCOPE)
endfunction()

## -------------------------------------------------------------------------------------------------
function (NS_map_remove map key out)
  NS_map_must_have("${map}" ${key})
  list(FIND map ${key} INDEX)
  math(EXPR INDEX2 "${INDEX} + 1")
  list(REMOVE_AT map ${INDEX} ${INDEX2})
  set(${out} "${map}" PARENT_SCOPE)
endfunction()

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

## Clone a Git repository during CMake generation. Which mean that you can clone
## a repo and include it while CMake is generating everything
## -------------------------------------------------------------------------------------------------
if(GIT_EXECUTABLE AND NOT EXISTS GIT_EXECUTABLE)
  unset(GIT_EXECUTABLE CACHE)
endif()
find_package(Git QUIET)

macro (NS_set name value)
    set(${name} ${value})
    set(${name} ${value} PARENT_SCOPE)
endmacro()

function (NS_git_clone)
  if(NOT GIT_EXECUTABLE)
    NS_error("Unable to find `git` executable! Cannot use `NS_git_clone`!")
  endif()
  # --
  NS_map_must_have("${ARGN}" GIT_REPOSITORY)
  NS_map_at("${ARGN}" GIT_REPOSITORY OUT)
  set(GIT_REPOSITORY ${OUT})
  # --
  NS_map_must_have("${ARGN}" DESTINATION)
  NS_map_at("${ARGN}" DESTINATION OUT)
  set(DESTINATION ${OUT})
  # --
  NS_map_has("${ARGN}" OVERWRITE YES)
  if (${YES})
    NS_say("## Removing ${DESTINATION}")
    # --
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E remove_directory ${DESTINATION}
      ${NS_QUIET}
    )
  endif()
  # --
  if (NOT EXISTS ${DESTINATION})
    NS_say("## Cloning ${GIT_REPOSITORY}")
    # --
    set(GIT_CMD ${GIT_EXECUTABLE} clone ${GIT_OPTS} ${GIT_REPOSITORY} ${DESTINATION})
    if (DEFINED NS_DEBUG)
      NS_say(${GIT_CMD})
    endif()
    execute_process(
      COMMAND ${GIT_CMD}
      ${NS_QUIET}
    )
  endif()
  # --
  NS_map_has("${ARGN}" GIT_TAG YES)
  if (${YES})
    NS_map_at("${ARGN}" GIT_TAG OUT)
    set(GIT_TAG ${OUT})
  else()
    # Assume we are always on master by default
    set(GIT_TAG master)
  endif()
  execute_process(
    COMMAND ${GIT_EXECUTABLE} -C ${DESTINATION} checkout ${GIT_TAG}
    ${NS_QUIET}
  )
  # --
  NS_map_has("${ARGN}" UPDATE YES)
  if (${YES})
    execute_process(
      COMMAND ${GIT_EXECUTABLE} -C ${DESTINATION} pull origin ${GIT_TAG}
      ${NS_QUIET}
    )
  endif()
endfunction()

macro (_NS_add_project_vars name)
  NS_map_must_have("${ARGN}" DESTINATION)
  NS_map_at("${ARGN}" DESTINATION OUT)
  NS_map_remove("${ARGN}" DESTINATION ARGN)
  set(DESTINATION ${OUT})
  # --
  set(_PROJECT_NAME          ${name})
  set(_PROJECT_DIR           ${DESTINATION})
  set(_PROJECT_WORKSPACE_DIR ${CMAKE_BINARY_DIR}/_${name})
  set(_PROJECT_SOURCE_DIR    ${_PROJECT_WORKSPACE_DIR}/${name})
  set(_PROJECT_BUILD_DIR     ${_PROJECT_WORKSPACE_DIR}/_build)
  # --
  NS_set(${name}_NAME        ${_PROJECT_NAME} PARENT_SCOPE)
  NS_set(${name}_DIR         ${_PROJECT_DIR} PARENT_SCOPE)
  NS_set(${name}_SOURCE_DIR  ${_PROJECT_SOURCE_DIR} PARENT_SCOPE)
  NS_set(${name}_BUILD_DIR   ${_PROJECT_BUILD_DIR} PARENT_SCOPE)
  # --
  NS_say("## Adding external project: ${_PROJECT_NAME}")
  # --
  NS_say("## Exporting those variables to the PARENT_SCOPE:")
  NS_show(${name}_NAME)
  NS_show(${name}_DIR)
  NS_show(${name}_SOURCE_DIR)
  NS_show(${name}_BUILD_DIR)
endmacro()

## Add an external cmake project.
## @name: The project name
## @dir:  Where the project's build will be located
## -------------------------------------------------------------------------------------------------
function (NS_add_cmake_project name)
  _NS_add_project_vars(${name} ${ARGN})
  # --
  NS_git_clone(${ARGN} DESTINATION ${_PROJECT_SOURCE_DIR})
  # --
  NS_map_has("${ARGN}" EXCLUDE_FROM_ALL YES)
  if (${YES})
    add_custom_target(${name})
  else()
    add_custom_target(${name} ALL)
  endif()
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E make_directory ${_PROJECT_BUILD_DIR}
    ${NS_QUIET}
  )
  execute_process(
    COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=${_PROJECT_DIR} ${_PROJECT_SOURCE_DIR}
    WORKING_DIRECTORY ${_PROJECT_BUILD_DIR}
    ${NS_QUIET}
  )
  execute_process(
    COMMAND ${CMAKE_COMMAND} --build . --target install
    WORKING_DIRECTORY ${_PROJECT_BUILD_DIR}
    ${NS_QUIET}
    )
  return()
endfunction()

## Add an external project. This function accepts same arguments as `ExternalProject_Add`.
## @name: The project name
## @dir:  Where the project's build will be located
## -------------------------------------------------------------------------------------------------
function (NS_add_project name)
  _NS_add_project_vars(${name} ${ARGN})
  # --
  NS_set(${name}_TARGET           ${name} PARENT_SCOPE)
  NS_set(${name}_TEST_TARGET      ${name}-test PARENT_SCOPE)
  NS_set(${name}_BUILD_TARGET     ${name}-build PARENT_SCOPE)
  NS_set(${name}_INSTALL_TARGET   ${name}-install PARENT_SCOPE)
  NS_set(${name}_DOWNLOAD_TARGET  ${name}-download PARENT_SCOPE)
  NS_set(${name}_CONFIGURE_TARGET ${name}-configure PARENT_SCOPE)
  # --
  NS_say("## Exporting those targets to the PARENT_SCOPE:")
  NS_show(${name}_TARGET)
  NS_show(${name}_TEST_TARGET)
  NS_show(${name}_BUILD_TARGET)
  NS_show(${name}_INSTALL_TARGET)
  # --
  ExternalProject_Add(
    # The project name
    ${_PROJECT_NAME}

    # Where all the temporary stuffs will be located
    PREFIX       ${_PROJECT_WORKSPACE_DIR}
    SOURCE_DIR   ${_PROJECT_SOURCE_DIR}
    BINARY_DIR   ${_PROJECT_BUILD_DIR}
    DOWNLOAD_DIR ${_PROJECT_BUILD_DIR}/_dl
    TMP_DIR      ${_PROJECT_BUILD_DIR}/_tmp
    STAMP_DIR    ${_PROJECT_BUILD_DIR}/_stamp

    # Install (we DO need to add the CMAKE_INSTALL_PREFIX...)
    INSTALL_DIR ${_PROJECT_DIR}
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${_PROJECT_DIR}"

    # The optional arguments
    ${ARGN}
  )
  # --
  NS_map_has("${ARGN}" EXCLUDE_FROM_ALL YES)
  if (${YES})
    set_target_properties(${name} PROPERTIES EXCLUDE_FROM_ALL TRUE)
  endif()
endfunction()

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

## Add path to include module path of cmake
## -------------------------------------------------------------------------------------------------
function (NS_add_cmake_path path)
  list(APPEND CMAKE_MODULE_PATH ${path})
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} PARENT_SCOPE)
endfunction()

## Add path to include module path of cmake
## -------------------------------------------------------------------------------------------------
function (NS_prevent_in_source_build)
  if (NOT DEFINED PROJECT_SOURCE_DIR)
    NS_error("Calling `NS_prevent_in_source_build` requires cmake project!")
  endif()
  if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    NS_error("Building in-source, not recommended! Build in a separate directory.")
  endif()
endfunction()

## Add path to include module path of cmake
## -------------------------------------------------------------------------------------------------
macro (NS_find_package name)
  find_package(${name} ${ARGN})
  NS_map_has("${ARGN}" REQUIRED YES)
  if (${YES} AND NOT ${name}_FOUND)
    NS_error("'${name}' package is required but has not been found!")
  endif()
endmacro()

## Ignore expression to prevent some cmake warnings
## -------------------------------------------------------------------------------------------------
macro(NS_ignore)
  ## Nothing to do here!
endmacro()

## -------------------------------------------------------------------------------------------------
## -------------------------------------------------------------------------------------------------

## Defaults:
if (DEFINED PROJECT_NAME)
  set(NS_PROJECT_NAME ${PROJECT_NAME})
else()
  set(NS_PROJECT_NAME ns.cmake)
endif()
