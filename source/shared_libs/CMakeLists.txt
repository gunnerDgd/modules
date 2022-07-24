cmake_minimum_required(VERSION 3.0)

project(
  synapse-modules-dll
  VERSION 0.1.0
  LANGUAGES CXX
)

add_library(
    synapse_modules_dll
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/modules.c
)

target_include_directories(
  synapse_modules_dll
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
  synapse_modules_dll
  PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_link_libraries(
    synapse_modules_dll
    synapse_modules_lib
)

target_link_libraries(
    synapse_modules_dll
    synapse_memory_dll
    synapse_structure_dll
)

target_compile_options(
    synapse_modules_dll 
    PRIVATE 
    /Dsynapse_modules_export_mode
)