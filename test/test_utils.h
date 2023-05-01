//
// Created by rozhin on 01.05.23.
// Copyright (c) 2021-2023 xsdnn. All rights reserved.
//

#ifndef MMPACK_TEST_UTILS_H
#define MMPACK_TEST_UTILS_H
#include "../mmpack.h"
#include <iostream>
using namespace mmpack;

namespace utils {
    void init(mm_scalar* ptr, size_t rows, size_t cols) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                *ptr = i * cols + j;
                ptr += 1;
            }
        }
    }

    void print(mm_scalar* ptr, size_t rows, size_t cols) {
        std::cout << "[";
        for (size_t i = 0; i < rows; ++i) {
            if (i == 0) {
                std::cout << "[";
            } else {
                std::cout << " [";
            }
            for (size_t j = 0; j < cols; ++j) {
                if (j != cols - 1) {
                    std::cout << *ptr << ", ";
                } else {
                    std::cout << *ptr << "]";
                }
                ptr += 1;
            }
            if (i != rows - 1) {
                std::cout << std::endl;
            }
        } std::cout << "]" << std::endl;
    }
} // utils

#endif //MMPACK_TEST_UTILS_H
