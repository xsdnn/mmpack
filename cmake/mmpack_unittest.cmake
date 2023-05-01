add_subdirectory(${MMPACK_ROOT}/cmake/external/googletest EXCLUDE_FROM_ALL)

enable_testing()

set(MMPACK_TEST_ROOT ${MMPACK_ROOT}/test)

macro(AddTest TARGET SOURCES)
    add_executable(${TARGET} ${SOURCES})
    target_link_libraries(${TARGET} ${LIBS} GTest::gtest_main mmpack)
    add_test(${TARGET} ${TARGET})
endmacro()

set(mmpack_common_src 
    ${MMPACK_TEST_ROOT}/test_allocator.cpp
    ${MMPACK_TEST_ROOT}/test_vector.cpp
        )

AddTest(
    mmpack_allocator_test
    ${MMPACK_TEST_ROOT}/test_allocator.cpp
        )

AddTest(
    mmpack_vector_test
    ${MMPACK_TEST_ROOT}/test_vector.cpp
        )
