enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test test.cpp)

target_link_libraries(test gtest_main)
add_test(test test)