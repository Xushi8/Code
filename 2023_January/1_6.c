#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int a = 's';
    putchar(a);
    a = toupper(a);
    putchar(a);
    a = tolower(a);
    putchar(a);
    a = tolower(a);
    putchar(a);

    return 0;
}