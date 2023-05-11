#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    long long a = 1024*1024*100;
    int* p = (int*)malloc(a);
    int i = 1;
    while(1)
    {
        printf("当前占用内存%dM\n", 100*i);
        memset(p, 1, a*i);
        getchar();
        i++;
        p = realloc(p, (long long)a*i);
    }
    return 0;
}



