#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int a;
    scanf("%d", &a);
    getchar();
    if (a > 10)
    {
        exit(1);
    }
    else
    {
        getchar();
    }


    return 0;
}

