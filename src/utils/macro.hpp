#pragma once

#define MM_UNUSED_PARAMETER(x) (void) (x)

#if defined(__GNUC__) || defined(__clang__) || defined(__ICC)
#define MM_STRONG_INLINE __attribute__((always_inline)) inline
#else
#define MM_STRONG_INLINE inline
#endif

// defined SSE support

#if (defined(_M_AMD64) || defined(_M_X64) || defined(__amd64)) && ! defined(__x86_64__)
    #define __x86_64__ 1
#endif

#ifndef SSE_INSTR_SET
    #if defined ( __AVX2__ )
        #define SSE_INSTR_SET 8
    #elif defined ( __AVX__ )
        #define SSE_INSTR_SET 7
    #elif defined ( __SSE4_2__ )
        #define SSE_INSTR_SET 6
    #elif defined ( __SSE4_1__ )
        #define SSE_INSTR_SET 5
    #elif defined ( __SSSE3__ )
        #define SSE_INSTR_SET 4
    #elif defined ( __SSE3__ )
        #define SSE_INSTR_SET 3
    #elif defined ( __SSE2__ ) || defined ( __x86_64__ )
        #define SSE_INSTR_SET 2
    #elif defined ( __SSE__ )
        #define SSE_INSTR_SET 1
    #elif defined ( _M_IX86_FP )          
        #define SSE_INSTR_SET _M_IX86_FP
    #else
        #define SSE_INSTR_SET 0
    #endif // instruction set defined
#endif // SSE_INSTR_SET
      
#if SSE_INSTR_SET > 7                  // AVX2 and later
    #ifdef __GNUC__
        #include <x86intrin.h>      
    #else
        #include <immintrin.h>         // MS version of immintrin.h covers AVX, AVX2 and FMA3
    #endif // __GNUC__
#elif SSE_INSTR_SET == 7
    #include <immintrin.h>             // AVX
#elif SSE_INSTR_SET == 6
    #include <nmmintrin.h>             // SSE4.2
#elif SSE_INSTR_SET == 5
    #include <smmintrin.h>             // SSE4.1
#elif SSE_INSTR_SET == 4
    #include <tmmintrin.h>             // SSSE3
#elif SSE_INSTR_SET == 3
    #include <pmmintrin.h>             // SSE3
#elif SSE_INSTR_SET == 2
    #include <emmintrin.h>             // SSE2
#elif SSE_INSTR_SET == 1
    #include <xmmintrin.h>             // SSE
#endif // SSE_INSTR_SET
