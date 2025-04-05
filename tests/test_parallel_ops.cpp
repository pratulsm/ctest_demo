#include <gtest/gtest.h>
#include "parallel_ops.h"

using namespace ctest_demo;

TEST(ParallelOpsTest, VectorMultiplyOMPTest) {
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> b = {2.0, 3.0, 4.0, 5.0};
    std::vector<double> expected = {2.0, 6.0, 12.0, 20.0};

    auto result = ParallelOps::vectorMultiplyOMP(a, b);
    
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_DOUBLE_EQ(result[i], expected[i]);
    }
}

TEST(ParallelOpsTest, VectorMultiplyOpenCLTest) {
    std::vector<double> a = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> b = {2.0, 3.0, 4.0, 5.0};
    std::vector<double> expected = {2.0, 6.0, 12.0, 20.0};

    auto result = ParallelOps::vectorMultiplyOpenCL(a, b);
    
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_DOUBLE_EQ(result[i], expected[i]);
    }
}