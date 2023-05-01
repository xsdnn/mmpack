//
// Created by rozhin on 01.05.23.
// Copyright (c) 2021-2023 xsdnn. All rights reserved.
//

#ifndef MMPACK_TENSOR_H
#define MMPACK_TENSOR_H

#include <pector/pector.h>
#include "../config.h"

namespace mmpack {


template <class T,
        class Alloc = std::allocator<T>,
        class SizeType = size_t,
        class RecommendedSize = pt::default_recommended_size,
        bool  check_size_overflow = true>
class vector : public pt::pector<T, Alloc, SizeType, RecommendedSize, check_size_overflow> {
public:
    using pt::pector<T, Alloc, SizeType, RecommendedSize, check_size_overflow>::pector;

public:
    T& operator() (const size_t i) { return this->operator[](i); }
    const T& operator() (const size_t i) const { return this->operator[](i); }
};

/*
 * 2-dim tensor a.k.a. Matrix2D
 */
template <class T,
        class Alloc = std::allocator<T>,
        class SizeType = size_t,
        class RecommendedSize = pt::default_recommended_size,
        bool  check_size_overflow = true>
class tensor : public pt::pector<T, Alloc, SizeType, RecommendedSize, check_size_overflow>{
public:
    using pt::pector<T, Alloc, SizeType, RecommendedSize, check_size_overflow>::pector;

public:
    void reserve(const size_t i, const size_t j) {
        num_rows = i;
        num_cols = j;
        pt::pector<T, Alloc, SizeType, RecommendedSize, check_size_overflow>::reserve(i * j);
    }

    T& operator() (const size_t i, const size_t j) {
        return this->operator[](i * num_cols + j);
    }

    const T& operator() (const size_t i, const size_t j) const {
        return this->operator[](i * num_cols + j);
    }

private:
    size_t num_rows = 0;
    size_t num_cols = 0;
};

} // mmpack



#endif //MMPACK_TENSOR_H
