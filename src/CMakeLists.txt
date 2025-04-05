add_library(ctest_demo_lib
    parallel_ops.cpp
)

target_include_directories(ctest_demo_lib
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(ctest_demo_lib
    PUBLIC OpenMP::OpenMP_CXX
    PUBLIC ${OpenCL_LIBRARIES}
)

add_executable(ctest_demo
    main.cpp
)

target_link_libraries(ctest_demo
    PRIVATE ctest_demo_lib
)