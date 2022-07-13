cmake_minimum_required(VERSION 3.0)

project(
  synapse-modules-lib
  VERSION 0.1.0
  LANGUAGES C
)

add_library(
  synapse_modules_lib
  STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/*.c
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