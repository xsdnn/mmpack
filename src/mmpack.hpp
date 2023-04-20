#include <vector>

#include "utils/macro.hpp"
#include "config.hpp"

#include "utils/allocator.hpp"

namespace mmpack {
    typedef std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>> vector;
    typedef std::vector<vector> tensor;
} // mmpack

