cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

# parsing
add_library(parsing STATIC src/parsing.cpp include/parsing.h)

# pattern
add_library(pattern STATIC src/pattern.cpp include/pattern.h)


# main
add_executable(test src/main.cpp)
target_link_libraries(test  parsing pattern ${CMAKE_THREAD_LIBS_INIT})