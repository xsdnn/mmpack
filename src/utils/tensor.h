//
// Created by rozhin on 01.05.23.
// Copyright (c) 2021-2023 xsdnn. All rights reserved.
//

#ifndef MMPACK_TENSOR_H
#define MMPACK_TENSOR_H

#include <vector>
#include "../config.h"
#include "allocator.h"

namespace mmpack {

/*
 * 2-dim tensor a.k.a. Matrix2D
 */
class tensor : public std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>>{
public:
    tensor() : std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>>() {}

    tensor(const size_t i, const size_t j)
            : std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>>(i * j),
            num_rows(i), num_cols(j) {}

    tensor(const tensor& rhs)
            : std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>>(rhs),
            num_rows(rhs.num_rows), num_cols(rhs.num_cols) {}

    tensor& operator=(const tensor& rhs) {
        std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>>::operator=(rhs);
        num_rows = rhs.num_rows;
        num_cols = rhs.num_cols;
        return *this;
    }

public:
    void reserve(const size_t i, const size_t j) {
        num_rows = i;
        num_cols = j;
        std::vector<mm_scalar, aligned_allocator<mm_scalar, 64>>::reserve(i * j);
    }

    mm_scalar& operator() (const size_t i, const size_t j) {
        return this->operator[](i * num_cols + j);
    }

    const mm_scalar& operator() (const size_t i, const size_t j) const {
        return this->operator[](i * num_cols + j);
    }

private:
    size_t num_rows = 0;
    size_t num_cols = 0;
};

} // mmpack



#endif //MMPACK_TENSOR_H
