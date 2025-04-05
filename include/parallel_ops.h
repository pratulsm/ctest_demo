#pragma once

#include <vector>

namespace ctest_demo {

class ParallelOps {
public:
    // OpenMP parallel operation
    static std::vector<double> vectorMultiplyOMP(
        const std::vector<double>& a, 
        const std::vector<double>& b);

    // OpenCL parallel operation
    static std::vector<double> vectorMultiplyOpenCL(
        const std::vector<double>& a, 
        const std::vector<double>& b);
};

} // namespace ctest_demo