##===================================================================================================
##                 Copyright 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

##===================================================================================================
## Parse revision number in variables
##===================================================================================================
function(parse_revision version_string prefix)
  set(version_regex_release "^([0-9]+)\\.([0-9]+)\\.([0-9]+)$")
  set(version_regex_prerelease "^([0-9]+)\\.([0-9]+)\\.([0-9]+)-([0-9A-Za-z.-]+)$")

  if("${version_string}" MATCHES ${version_regex_release})
    set(version_regex ${version_regex_release})
  elseif("${version_string}" MATCHES ${version_regex_prerelease})
    set(version_regex ${version_regex_prerelease})
  else()
    message(ERROR "[boost.dispatch] Unknown version format")
    return()
  endif()

  string(REGEX REPLACE ${version_regex} "\\1" ${prefix}_MAJOR "${version_string}")
  string(REGEX REPLACE ${version_regex} "\\2" ${prefix}_MINOR "${version_string}")
  string(REGEX REPLACE ${version_regex} "\\3" ${prefix}_PATCH "${version_string}")
  set(${version_name}_IS_PRERELEASE 0)

  if("${version_string}" MATCHES ${version_regex_prerelease})
    string(REGEX REPLACE ${version_regex} "\\4" ${prefix}_PRERELEASE "${version_string}")
    set(${prefix}_IS_PRERELEASE 1)
  endif()

  math(EXPR ${prefix} "${${prefix}_MAJOR} * 10000 + ${${prefix}_MINOR} * 100 + ${${prefix}_PATCH}")

  foreach(ARG "" _MAJOR _MINOR _PATCH _PRERELEASE _IS_PRERELEASE)
    set(${prefix}${ARG} ${${prefix}${ARG}} PARENT_SCOPE)
  endforeach()

endfunction()

##===================================================================================================
## Setup revision ID
##===================================================================================================
if(GIT_EXECUTABLE AND NOT EXISTS GIT_EXECUTABLE)
  unset(GIT_EXECUTABLE CACHE)
endif()

find_package(Git QUIET)
if(GIT_EXECUTABLE)
  execute_process(COMMAND ${GIT_EXECUTABLE} describe --tags
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                  OUTPUT_VARIABLE BOOST_DISPATCH_VERSION_STRING
                  OUTPUT_STRIP_TRAILING_WHITESPACE
                 )
endif()

if(NOT DEFINED BOOST_DISPATCH_VERSION_STRING)
  if((NOT GIT_EXECUTABLE OR NOT EXISTS GIT_EXECUTABLE) AND IS_DIRECTORY ${PROJECT_SOURCE_DIR}/.git)

    message ( FATAL_ERROR "[boost.dispatch] Git not found, verify your GIT_EXECUTABLE variable "
                          "or specify BOOST_DISPATCH_VERSION_STRING manually"
            )

  elseif(NOT EXISTS ${PROJECT_SOURCE_DIR}/tagname)

    message ( FATAL_ERROR "BOOST_DISPATCH_VERSION_STRING must be specified "
                          "manually if no tagname file nor Git"
            )

  endif()

  file(READ tagname BOOST_DISPATCH_VERSION_STRING)
  string(REGEX REPLACE "[ \r\n\t]+$" "" BOOST_DISPATCH_VERSION_STRING "${BOOST_DISPATCH_VERSION_STRING}")

endif()

parse_revision("${BOOST_DISPATCH_VERSION_STRING}" BOOST_DISPATCH_VERSION)

set(boost_dispatch_release "(release)")
if(BOOST_DISPATCH_VERSION_IS_PRERELEASE)
  set(boost_dispatch_release "(pre-release)")
endif()

message(STATUS "[boost.dispatch] Configuring Boost.Dispatch version ${BOOST_DISPATCH_VERSION_STRING} ${boost_dispatch_release}")
