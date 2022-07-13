cmake_minimum_required(VERSION 3.0)

project(
  synapse-modules-lib
  VERSION 0.1.0
  LANGUAGES C
)

file(
    GLOB_RECURSE src_synapse_modules_lib CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_library(
  synapse_modules_lib
  STATIC
  ${src_synapse_modules_lib}
)

target_include_directories(
  synapse_modules_lib 
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
  synapse_modules_lib
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_include_directories(
  synapse_modules_lib
  PRIVATE
  ${CMAKE_SOURCE_DIR}/submodules/synapse-structure/include
)