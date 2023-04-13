cmake_minimum_required(VERSION 3.13)
project(mmpack C CXX)

option(mmpack_USE_SSE OFF)
option(mmpack_USE_AVX OFF)

if (mmpack_USE_SSE)
    add_compile_definitions(MM_USE_SSE) # TODO: добавить generic
endif(mmpack_USE_SSE)

if (mmpack_USE_AVX)
    add_compile_definitions(MM_USE_AVX) # TODO: добавить generic
endif(mmpack_USE_AVX)
