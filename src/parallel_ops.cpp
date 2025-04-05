#include "parallel_ops.h"
#include <omp.h>
#include <CL/cl.h>
#include <stdexcept>

namespace ctest_demo {

std::vector<double> ParallelOps::vectorMultiplyOMP(
    const std::vector<double>& a, 
    const std::vector<double>& b) {
    
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be of equal size");
    }

    std::vector<double> result(a.size());

    #pragma omp parallel for
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] * b[i];
    }

    return result;
}

std::vector<double> ParallelOps::vectorMultiplyOpenCL(
    const std::vector<double>& a, 
    const std::vector<double>& b) {
    
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be of equal size");
    }

    // Simple implementation for now - replace with actual OpenCL implementation
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] * b[i];
    }

    return result;
}

} // namespace ctest_demo