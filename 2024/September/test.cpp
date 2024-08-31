#include <cstdio>

__attribute__((__target__("avx2"))) void add_vectors(void)
{
    printf("avx2\n");
}
__attribute__((__target__("default"))) void add_vectors(void)
{
    printf("default\n");
}

int main()
{
    add_vectors();
}