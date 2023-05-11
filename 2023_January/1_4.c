#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// func(int a, int b)
// {
//     return ((b - a + 1) * (a + b))/2;
// }
// int main()
// {
//     int i, j, k;
//     int m;
//     int ret = func(297, 328);
//     scanf("%d", &m);
//     for (i = 1; i < m; i++)
//     {
//         for (j = i + 1; j < m; j += 10)
//         {
//             if ((ret = func(i, j)) < m)
//             {
//                 continue;
//             }
//             else
//             {
//                 j -= 10;
//                 break;
//             }
//         }

//         for (k = j; k < m; k++)
//         {
//             if ((ret = func(i, k)) == m)
//             {
//                 printf("%d %d\n", i, k);
//                 break;
//             }
//             else if ((ret = func(i, k)) > m)
//             {
//                 break;
//             }
//         }
//     }

//     return 0;
// }

// char s1[15];
// char s2[1000003];
// int main()
// {
//     gets(s1);
//     gets(s2);
//     int len1 = strlen(s1);
//     int len2 = strlen(s2);
//     int i;
//     for(i = 0; i< len1 -1; i++)
//     {
//         if (s1[i] >= 'A' && s1[i] <= 'Z')
//         {
//             s1[i] += 32;
//         }
//     }
//     for(i = 0; i < len2 -1; i++)
//     {
//         if (s2[i] >= 'A' && s2[i] <= 'Z')
//         {
//             s2[i] += 32;
//         }
//     }
//     int count = 0;
//     int first;
//     for (i = 0; i < len2 - 1 - len1; i++)
//     {
//         int judge = 0;
//         if (strncmp(s1, s2 + i, len1) == 0)
//         {
//             if (i == 0)
//             {
//                 if (*(s2 + i + len1) == ' ')
//                 {
//                     judge = 1;;
//                 }
//             }
//             else
//             {
//                 if ((*(s2 + i - 1) == ' ') && (*(s2 + i + len1) == ' '))
//                 {
//                     judge = 1;;
//                 }
//             }

//             if (judge == 0)
//             {
//                 continue;
//             }
//             else
//             {
//                 if (count == 0)
//                 {
//                     first = i;
//                     count++;
//                 }
//                 else
//                 {
//                     count++;
//                 }
//             }
//         }
//     }
//     if (count != 0)
//     {
//         printf("%d %d", count, first);
//     }
//     else
//     {
//         puts("-1");
//     }

//     return 0;
// }

// int main()
// {
//     char s1[14];
//     gets(s1);
//     int i;
//     int sum = 0;
//     sum = sum +s1[0] - '0';
//     for (i = 2; i <=4; i++)
//     {
//         sum = sum + (s1[i] - '0') * i;
//     }
//     for (i = 6; i <= 10; i++)
//     {
//         sum = sum + (s1[i] - '0') * (i - 1);
//     }
    
//     int ret = sum % 11;
//     if ((ret == (s1[12] - '0')) || (ret == 10 && s1[12] == 'X'))
//     {
//         printf("Right");
//     }
//     else
//     {
//         for (i = 0; i < 12; i++)
//         {
//             putchar(s1[i]);
//         }
//         if (ret == 10)
//         {
//             printf("X");
//         }
//         else
//         {
//             printf("%d", ret);
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int arr[26] = {0};
//     int ch;
//     while ((ch = getchar()) != EOF)
//     {
//         if (!(ch >= 'A' && ch <= 'Z'))
//         {
//             continue;
//         }

//         arr[ch - 'A']++;
//     }
//     int max_num = -1;
//     int i, j;
//     for (i = 0; i < 26; i++)
//     {
//         if (arr[i] > max_num)
//         {
//             max_num = arr[i];
//         }
//     }

//     for (i = 0; i < max_num; i++)
//     {
//         if (i + arr[0] >= max_num)
//         {
//             putchar('*');
//         }
//         else
//         {
//             printf(" ");
//         }
        
//         for (j = 1; j < 26; j++)
//         {
//             if (i + arr[j] >= max_num)
//             {
//                 printf(" *");
//             }
//             else
//             {
//                 printf("  ");
//             }
//         }
//         putchar('\n');
//     }
//     printf("A");
//     for (i = 1; i < 26; i++)
//     {
//         printf(" %c", i + 65);
//     }


//     return 0;
// }

char* reverse(char* str)
{
    int right;
    int left = 0;
    for (int i = 0; i < 199; i++)
    {
        if (str[i] == '\0' || str[i] == '\n')
        {
            right = i - 1;
            break;
        }
    }

    char ret;
    if (right != 0)
    {
        while (str[right] == '0')
        {
            right--;
        }
        str[right + 1] = '\0';

        while (left < right)
        {
            ret = str[left];
            str[left] = str[right];
            str[right] = ret;
            left++;
            right--;
        }
    }
    

    return str;
}

void swap_zhengshu(char* str)
{
    str = reverse(str);
    printf(str);
}
void swap_xiaoshu(char* str)
{
    int right;
    int left = 0;
    char ret1[20] = {0};
    char ret2[20] = {0};
    char ret[2] = { 0 };
    int i, j;
    for (i = 0; i < 199; i++)
    {
        if (str[i] == '.')
        {
            right = i - 1;
            break;
        }

        ret1[i] = str[i];
    }
    strcat(ret1, ret);
    reverse(ret1);

    for (i++, j = 0; i < 100; i++, j++)
    {
        if (str[i] == '\0' || str[i] == '\n')
        {
            right = i - 1;
            break;
        }

        ret2[j] = str[i];
    }
    strcat(ret2, ret);
    for (int i = 0; i < 199; i++)
    {
        if (ret2[i] == '\0' || ret2[i] == '\n')
        {
            right = i - 1;
            break;
        }
    }
    left = 0;

    char tmp;

    while (left < right)
    {
        tmp = ret2[left];
        ret2[left] = ret2[right];
        ret2[right] = tmp;
        left++;
        right--;
    }

    
    if (ret2[0] != '0')
    {
        for (i = 0; i < 398; i++)
        {
            if (ret2[i] == '\0' || ret2[i] == '\n')
            {
                break;
            }
        }
        j = i;
        for (i--; i >= 0; i--)
        {
            if (ret2[i] >= '1' && ret2[i] <= '9')
            {
                break;
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    ret2[i] = ret2[i + 1];
                }
            }
        }
    }

    printf("%s.%s", ret1, ret2);

    
}
void swap_fenshu(char* str)
{
    int right;
    int left = 0;
    char ret1[20] = { 0 };
    char ret2[20] = { 0 };
    char ret[2] = { 0 };
    int i, j;
    for (i = 0; i < 199; i++)
    {
        if (str[i] == '/')
        {
            right = i - 1;
            break;
        }

        ret1[i] = str[i];
    }
    strcat(ret1, ret);
    reverse(ret1);

    for (i++, j = 0; i < 100; i++, j++)
    {
        if (str[i] == '\0' || str[i] == '\n')
        {
            right = i - 1;
            break;
        }

        ret2[j] = str[i];
    }
    strcat(ret2, ret);
    reverse(ret2);

    printf("%s/%s", ret1, ret2);

}
void swap_baifenshu(char* str)
{
    char ret1[30] = {0};
    int i;
    for (i = 0; i < 122; i++)
    {
        if (str[i] == '%')
        {
            break;
        }

        ret1[i] = str[i];
    }
    char ret[2] = { 0 };
    strcat(ret1, ret);
    reverse(ret1);
    printf("%s", ret1);
    putchar('%');
}
int main()
{
    char str[23];
    gets(str);
    int arr[4] = { 0 };
    int i;
    for (i = 0; i < 23; i++)
    {
        if (str[i] == '\0')
        {
            arr[0]++;
            break;
        }
        else if (str[i] == '.')
        {
            arr[1]++;
            break;
        }
        else if (str[i] == '/')
        {
            arr[2]++;
            break;
        }
        else if (str[i] == '%')
        {
            arr[3]++;
            break;
        }
    }

    if (arr[0] == 1)
    {
        swap_zhengshu(str);
    }
    else if (arr[1] == 1)
    {
        swap_xiaoshu(str);
    }
    else if (arr[2] == 1)
    {
        swap_fenshu(str);
    }
    else
    {
        swap_baifenshu(str);
    }


    return 0;
}