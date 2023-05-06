#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    struct tm* st;
    time_t ti;
    time(&ti);
    st = localtime(&ti);
    scanf("%d", &st->tm_hour);
    return 0;
}
