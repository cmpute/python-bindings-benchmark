cmake_minimum_required(VERSION 3.12)

project(cython_base)

find_package(PythonExtensions REQUIRED)
find_package(Cython REQUIRED)
find_package(NumPy REQUIRED)
include_directories(${NumPy_INCLUDE_DIRS})

get_filename_component(main_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
include_directories(${main_dir})

add_cython_target(cython_base CXX)
add_library(cython_base MODULE ${cython_base})
python_extension_module(cython_base)
install(TARGETS cython_base LIBRARY DESTINATION .)
