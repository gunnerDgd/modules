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