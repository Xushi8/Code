#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// enum {MINUS = 1, ADD };

// int main()
// {
//     int n;
//     puts("请选择你的操作:");
//     puts("1.减法, 2.加法");
//     scanf("%d", &n);
//     getchar();
//     puts("请输入两个操作数");
//     int a, b;
//     scanf("%d %d", &a, &b);
//     switch (n)
//     {
//     case MINUS:
//         b = -b;//这里没有break
//     case ADD:
//         printf("%d", a + b);
//         break;
//     default:
//         puts("输入错误");
//         break;
//     }

//     system("pause");
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     if (*(char*)&a == 1)
//     {
//         puts("小端");
//     }
//     else
//     {
//         puts("大端");
//     }

//     return 0;
// }


// typedef union A
// {
//     short a;
//     char b[2];
// }A;
// int main()
// {   
//     A a;
//     a.a = 0x1234;
//     printf("%x %x", a.b[0], a.b[1]);

//     return 0;
// }
// #include<stdbool.h>
// int main()
// {
//     printf("%d", sizeof(bool));

//     return 0;
// }

// int main()
// {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     int max_num = a > b ? a : b;
//     while (max_num--)
//     {
//         puts("HelloWorld!");
//     }

//     return 0;
// }

// int main()
// {
//     puts("**************************");
//     puts("         Very    Good!");
//     puts("**************************");

//     return 0;
// }

// int main()
// {
//     int a, b, c;
//     scanf("%d%d%d", &a, &b, &c);
//     a = a > b ? a : b;
//     a = a > c ? a : c;
//     printf("%d\n", a);

//     return 0;
// }

// int main()
// {
//     char str[102];
//     scanf("%s", str);
//     int i = 0;
//     while (str[i] != '\0')
//     {
//         str[i] += 4;
//         if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
//         {
//             str[i] -= 26;
//         }
//         i++;
//     }
//     puts(str);

//     return 0;
// }

// int main()
// {
//     double pi = 3.14;
//     double r, h;
//     scanf("%lf%lf", &r, &h);
//     printf("C1=%.2lf\nSa=%.2lf\nSb=%.2lf\nVa=%.2lf\nVb=%.2lf\n", pi * 2 * r, pi * r * r, pi * 4 * r * r, (4.0 / 3.0) * pi * r * r * r, pi * r * r * h);

//     return 0;
// }

// int main()
// {
//     double n;
//     scanf("%lf", &n);
//     printf("c=%.2lf", (5.0 * (n - 32.0)) / 9);

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     if (n < 1)
//     {
//         printf("%d", n);
//     }
//     else if (n >= 1 && n < 10)
//     {
//         printf("%d", 2 * n - 1);
//     }
//     else
//     {
//         printf("%d", 3 * n - 11);
//     }

//     return 0;
// }

// int main()
// {
//     int x;
//     scanf("%d", &x);
//     if (x >= 90) puts("A");
//     else if (x >= 80 && x < 90) puts("B");
//     else if (x >= 70 && x < 80) puts("C");
//     else if (x >= 60 && x < 70) puts("D");
//     else puts("E");


//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int arr[15];
//     int i = 0;
//     while (n)
//     {
//         arr[i++] = n % 10;
//         n /= 10;
//     }
//     printf("%d\n", i);
//     int ret = i - 2;
//     printf("%d", arr[i - 1]);
//     for (; ret >= 0; ret--)
//     {
//         printf(" %d", arr[ret]);
//     }
//     printf("\n");
//     for (int j = 0; j < i; j++)
//     {
//         printf("%d", arr[j]);
//     }

//     return 0;
// }

int main()
{
    int n;
    scanf("%d", &n);
    int ret;
    if (n <= 100000) ret = (0.1) * n;
    else if (n > 100000 && n <= 200000) ret = 0.1 * 100000 + 0.075 * (n - 100000);
    else if (n > 200000 && n <= 400000) ret = 0.1 * 100000 + 0.075 * (200000 - 100000) + 0.05 * (n - 200000);
    else if (n > 400000 && n <= 600000) ret = 0.1 * 100000 + 0.075 * (200000 - 100000) + 0.05 * (400000 - 200000) + 0.03 * (n - 400000);
    else if (n > 600000 && n <= 1000000) ret = 0.1 * 100000 + 0.075 * (200000 - 100000) + 0.05 * (400000 - 200000) + 0.03 * (600000 - 400000) + 0.015 * (n - 600000);
    else ret = 0.1 * 100000 + 0.075 * (200000 - 100000) + 0.05 * (400000 - 200000) + 0.03 * (600000 - 400000) + 0.015 * (1000000 - 600000) + 0.01 * (n - 1000000);
    printf("%d", ret);

    return 0;
}