#include "../src/mmpack.hpp"
#include <cstddef>
#include <cstdint>
#include <gtest/gtest.h>

TEST(vector, _01) {
    mmpack::vector v(10);

    for (size_t i = 0; i < 10; ++i) {
        v[i] = (mmpack::mm_scalar) (i * i); 
    }


    for (size_t i = 0; i < 10; ++i) {
        ASSERT_EQ(v[i], i * i); 
    }
}

TEST(vector, _02) {
    const int32_t N = 10;
    mmpack::vector v(N);

    for (size_t i = 0; i < 10; ++i) {
        v[i] = (mmpack::mm_scalar) (i * i); 
    }

    mmpack::mm_scalar* data = v.data();

    for (size_t i = 0; i < N; ++i) {
       ASSERT_EQ(*data, i * i);
       data++; 
    }
}
