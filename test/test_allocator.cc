#include "../mmpack.h"
#include <gtest/gtest.h>
using namespace mmpack;

TEST(allocator, vanilla) {
    aligned_allocator<mm_scalar, 64> alloc;

    float* p = alloc.allocate(300);
    alloc.deallocate(p, 300);
}

TEST(allocator, vector) {
    std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>> vec_t;

    for (size_t i = 0; i < 1000; i++) {
        vec_t.push_back((mm_scalar)i);
    }
}

TEST(allocator, allocate) {
    aligned_allocator<float, 64> alloc;
    float* ptr = nullptr;
    ptr = alloc.allocate(100 * sizeof(float));
    ASSERT_TRUE(ptr != nullptr);
}
