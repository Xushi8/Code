#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b)                \
do                                \
{                                 \
    typeof(a) tmp = a;            \
    a = b;                        \
    b = tmp;                      \
} while (0)

int main()
{
    int a = 10;
    int b = 20;
    printf("%d %d\n", a, b);
    SWAP(a, b);
    printf("%d %d\n", a, b);

    return 0;
}