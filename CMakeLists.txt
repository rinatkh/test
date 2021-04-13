cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

# parsing
add_library(parsing STATIC src/parsing.c include/parsing.h)

# pattern
add_library(pattern STATIC src/pattern.c include/pattern.h)


# main
add_executable(test src/main.c)
target_link_libraries(test  parsing pattern ${CMAKE_THREAD_LIBS_INIT})