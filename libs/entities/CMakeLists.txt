add_library(entities STATIC
        include/entities.hpp
        source/entities.cpp)
target_include_directories(entities PUBLIC include)