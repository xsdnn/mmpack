#include <vector>

#include "utils/macro.h"
#include "config.h"

#include "utils/allocator.h"

namespace mmpack {
    typedef std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>> vec_t;
    typedef std::vector<vec_t> tensor;
} // mmpack

