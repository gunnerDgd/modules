cmake_minimum_required(VERSION 3.0)

project(
  synapse-modules-lib-cpp
  VERSION 0.1.0
  LANGUAGES CXX
)

add_library(
    synapse_modules_lib_cpp
    STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

target_include_directories(
  synapse_modules_lib_cpp
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
  synapse_modules_lib_cpp
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)