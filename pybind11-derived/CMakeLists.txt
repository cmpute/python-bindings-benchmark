cmake_minimum_required(VERSION 3.12)

project(pybind11_derived)

find_package(PythonExtensions REQUIRED)
find_package(NumPy REQUIRED)
find_package(pybind11 REQUIRED)
include_directories(${NumPy_INCLUDE_DIRS})
include_directories(${pybind11_INCLUDE_DIRS})

get_filename_component(main_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
include_directories(${main_dir})

pybind11_add_module(pybind11_derived pybind11_derived.cxx)
# target_link_libraries(pybind11_dervied ...)
install(TARGETS pybind11_derived LIBRARY DESTINATION .)
