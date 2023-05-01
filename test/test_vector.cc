#include "../mmpack.h"
#include <gtest/gtest.h>

TEST(vector, _01) {
    mmpack::vector<mmpack::mm_scalar> v;
    v.reserve(10);

    for (size_t i = 0; i < 10; ++i) {
        v[i] = (mmpack::mm_scalar) (i * i); 
    }


    for (size_t i = 0; i < 10; ++i) {
        ASSERT_EQ(v[i], i * i); 
    }
}

TEST(vector, _02) {
    const int32_t N = 10;
    mmpack::vector<mmpack::mm_scalar> v;
    v.reserve(N);

    for (size_t i = 0; i < 10; ++i) {
        v[i] = (mmpack::mm_scalar) (i * i); 
    }

    mmpack::mm_scalar* data = v.data();

    for (size_t i = 0; i < N; ++i) {
       ASSERT_EQ(*data, i * i);
       data++; 
    }
}

TEST(vector, RandomElem) {
    const int32_t N = 10;
    mmpack::vector<mmpack::mm_scalar> v;
    v.reserve(N);

    for (size_t i = 0; i < 10; ++i) {
        v[i] = (mmpack::mm_scalar) (i * i);
    }

    for (size_t i = 0; i < N; ++i) {
        ASSERT_EQ(v(i), i * i);
    }
}
