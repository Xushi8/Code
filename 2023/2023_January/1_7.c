#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main()
{
    int a = 0;
    char s1[] = "732764287";
    a = atoi(s1);
    printf("%d\n", a);
    char s2[9];
    sprintf(s2, "%d\n\n\n\n", a);
    puts(s2);
    putchar('1');

    return 0;
}