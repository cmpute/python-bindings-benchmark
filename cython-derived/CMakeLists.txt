cmake_minimum_required(VERSION 3.12)

project(cython_derived)

find_package(PythonExtensions REQUIRED)
find_package(Cython REQUIRED)
find_package(NumPy REQUIRED)
include_directories(${NumPy_INCLUDE_DIRS})

get_filename_component(main_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
include_directories(${main_dir})
include_directories(${main_dir}/cython-base) # for cython header

add_cython_target(cython_derived CXX)
add_library(cython_derived MODULE ${cython_derived})
python_extension_module(cython_derived)
install(TARGETS cython_derived LIBRARY DESTINATION .)
