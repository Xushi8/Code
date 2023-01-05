#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include <time.h>

// int main()
// {
//     int count;
//     double a;
//     scanf("%d", &count);
//     scanf("%30lf", &a);
//     char num[100];

//     sprintf(num, "%d", count);
//     puts(num);

//     sprintf(num, "%.20lf", a);
//     puts(num);

//     return 0;
// }

// int main()
// {
//     int count_num = 0;//记录数字数目
//     int num[10] = { 0 };//记录不同位数的数的个数
//     int sum = 0;//记录和
//     int ch;
//     int judge = 0;
//     int tmp = 0;//存储数字,重点
//     while ((ch = getchar()) != '\n')
//     {
//         if (ch >= '0' && ch <= '9')
//         {
//             judge++;
//             tmp *= 10;//tmp进一位
//             tmp += ch - '0';//加上新读取的数字
//         }
//         else if (judge != 0)//else if保证未读取到数字时进入
//         {
//             count_num++;
//             if (judge >= 2)
//             {
//                 sum += tmp;
//                 tmp = 0;
//                 num[judge - 1]++;
//             }
//             judge = 0;
//         }
//     }

//     printf("有%d个数字\n", count_num);
//     printf("其中有\n%d个二位数\n%d个三位数\n%d个四位数\n%d个五位数\n%d个六位数\n%d个七位数\n%d个八位数\n%d个九位数\n%d个十位数\n", num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], num[9]);
//     printf("他们的和是%d", sum);

//     return 0;
// }

char* my_strcpy(char* dest, const char* str)
{
    char* ret = dest;

    while (*dest++ = *str++)
    {
        continue;
    }

    return ret;
}

// void* my_memcpy(void* dest, const void* str, long long count)
// {
//     char* s1 = (char*)dest;
//     const char* s2 = (char*)str;
//     while (count--)
//     {
//         *(char*)s1++ = *(char*)s2++;
//     }

//     return dest;
// }

void* my_memcpy(void* dest, const void* str, long long count)
{
    void* ret = dest;

    while (count--)
    {
        *(char*)dest = *(char*)str;
        dest = (char*)dest + 1;
        str = (char*)str + 1;
    }

    return ret;
}

int main()
{
    clock_t start, stop;
    start = clock();
    char s1[20] = "12345";
    char s2[20] = "dsfhseu";
    my_strcpy(s1, s2);
    puts(s1);

    long long size = 1000;
    int* s3 = (int*)malloc(size);
    int* s4 = (int*)malloc(size);
    long long ret = sizeof(int) * size;
    my_memcpy(s3, s4, ret);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", s3[i]);
    }
    printf("\n");

    stop = clock();
    double second;
    second = (double)(stop - start) / CLK_TCK;
    printf("%lf", second);

    return 0;
}