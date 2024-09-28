cmake_minimum_required(VERSION 3.22)

project(
    test_example
    VERSION 1.0
    LANGUAGES CXX
    )
    
add_library(my_lib my_lib.hpp my_lib.cpp)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE my_lib)
    
