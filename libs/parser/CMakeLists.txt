add_library(parser STATIC
        include/parsing.hpp
        source/parsing.cpp)
target_include_directories(parser PUBLIC include ../../third_party)
target_link_libraries(parser entities)