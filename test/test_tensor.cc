//
// Created by rozhin on 01.05.23.
// Copyright (c) 2021-2023 xsdnn. All rights reserved.
//

#include "../mmpack.h"
#include "test_utils.h"
#include <gtest/gtest.h>

TEST(tensor, _01) {
    mmpack::tensor t;
    t.reserve(10, 10);

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            t(i, j) = (mmpack::mm_scalar) (i * j);
        }
    }

    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            ASSERT_EQ(t(i, j), i * j);
        }
    }
}
