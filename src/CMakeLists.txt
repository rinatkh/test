add_executable(program main.cpp ../tests/test.cpp)
target_link_libraries(program parser entities)