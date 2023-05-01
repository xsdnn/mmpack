cmake_minimum_required(VERSION 3.13)
project(mmpack C CXX)

option(mmpack_USE_SSE OFF)
option(mmpack_USE_AVX OFF)
option(mmpack_BUILD_UNITTESTS ON)

set(MMPACK_ROOT ${PROJECT_SOURCE_DIR}/..)

if (mmpack_USE_SSE)
    add_compile_definitions(MM_USE_SSE) # TODO: добавить generic
endif(mmpack_USE_SSE)

if (mmpack_USE_AVX)
    add_compile_definitions(MM_USE_AVX) # TODO: добавить generic
endif(mmpack_USE_AVX)

include_directories(
    external/pector/include
)

set(mmpack_common_src
    ${MMPACK_ROOT}/src/utils/allocator.cc
    ${MMPACK_ROOT}/src/gemm/sgemm.cc
)
add_library(mmpack STATIC ${mmpack_common_src})

if(mmpack_BUILD_UNITTESTS)
    include(mmpack_unittest.cmake)
endif(mmpack_BUILD_UNITTESTS)
