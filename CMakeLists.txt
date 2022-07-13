cmake_minimum_required(VERSION 3.0)

project(
  synapse-modules
  VERSION 0.1.0
  LANGUAGES C
)

add_subdirectory(source/c)
add_subdirectory(source/shared_libs)
add_subdirectory(source/cpp)

add_dependencies(
    synapse_modules_dll
    synapse_modules_lib
)

add_dependencies(
    synapse_modules_lib_cpp
    synapse_modules_lib
    synapse_modules_dll
)