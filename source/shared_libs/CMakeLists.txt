cmake_minimum_required(VERSION 3.0)

project(
  synapse-modules-dll
  VERSION 0.1.0
  LANGUAGES C
)

file(
    GLOB_RECURSE
    src_synapse_modules_lib
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/*.c
)

add_library(
    synapse_modules_dll
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/modules.c
    ${src_synapse_modules_lib}
)

target_include_directories(
  synapse_modules_dll
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_link_libraries(
    synapse_modules_dll
    synapse_memory_dll
    synapse_structure_dll
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
  target_compile_options(
    synapse_modules_dll 
    PRIVATE 
    /Dsynapse_modules_export_mode
  )

  set_target_properties(
    synapse_modules_dll
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/lib/build
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  )
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(
    synapse_modules_dll 
    PRIVATE 
    -Dsynapse_modules_export_mode
  )

  set_target_properties(
    synapse_modules_dll
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  )
endif()