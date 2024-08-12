#ifndef BASIC_UNROLL_LOOP
#if defined(__GNUC__) || defined(__clang__)
// GCC or Clang
#define TOSTRING(X) #X
#define BASIC_UNROLL_LOOP(N) _Pragma(TOSTRING(GCC unroll N))
#elif defined(_MSC_VER)
// MSVC
#define BASIC_UNROLL_LOOP(N) __pragma(loop(unroll, N))
#else
// Other compilers
#define BASIC_UNROLL_LOOP(N)
#endif
#endif

#include <cstdio>

int main()
{
    BASIC_UNROLL_LOOP(12)
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", i);
    }
}