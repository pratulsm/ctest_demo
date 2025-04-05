add_executable(ctest_demo_tests
    test_parallel_ops.cpp
)

target_link_libraries(ctest_demo_tests
    PRIVATE ctest_demo_lib
    PRIVATE GTest::gtest
    PRIVATE GTest::gtest_main
)

add_test(NAME ctest_demo_tests
         COMMAND ctest_demo_tests
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

set_tests_properties(ctest_demo_tests
    PROPERTIES
    FAIL_REGULAR_EXPRESSION ".*FAILED.*"
)