project(
  synapse-modules-dll
  VERSION 0.1.0
  LANGUAGES CXX
)

add_library(
    synapse_modules_dll
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
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

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../cpp)
target_link_libraries(
    synapse_modules_lib_cpp
    synapse_modules_dll
)