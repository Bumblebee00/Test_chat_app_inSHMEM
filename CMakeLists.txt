cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfatal-errors -pthread")

project(TemplateProject)    # Modify the project name here

if (" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
	In-source builds are not allowed.
	Please, create a separate directory for build files (e.g. build/).
	Delete CMakeCache.txt, make a separate dir and try again.
	")
endif ()

message("-----------------")
message("OS detection:")
message(${CMAKE_SYSTEM_NAME})
message(${CMAKE_SYSTEM})
message("-----------------")

if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(PROJECT_VERSION "2.4.0")
set(PROJECT_UTILS_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
configure_file(cmakevariables.h.in version.h @ONLY)

find_package(toml11 REQUIRED)
find_library(MOSQUITTO_LIBRARY
             NAMES
             mosquitto
             libmosquitto
             libmosquitto-dev
             )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(lib/ExampleLibrary)
#add_subdirectory(lib/ExampleLibrary2)

add_subdirectory(src/ExampleProgram)
#add_subdirectory(src/ExampleProgram2)

enable_testing()
add_subdirectory(tests)
