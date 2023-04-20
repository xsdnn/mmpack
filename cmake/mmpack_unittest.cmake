set (GTEST_ROOT ${MMPACK_ROOT}/cmake/external/googletest)
find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Not found Gtest")
endif()


set(MMPACK_TEST_ROOT ${MMPACK_ROOT}/test)

macro(AddTest TARGET SOURCES LIBS)
    add_executable(${TARGET} ${SOURCES})
    target_link_libraries(${TARGET} ${LIBS} GTest::gtest_main)
    add_test(${TARGET} ${TARGET})
endmacro()

set(mmpack_common_src 
    ${MMPACK_TEST_ROOT}/test_allocator.cpp
    )

AddTest(
    mmpack_common_test
    ${mmpack_common_src}
    mmpack
    )
