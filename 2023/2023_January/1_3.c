#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// int main()
// {
//     int n, m;
//     scanf("%d %d", &m, &n);
//     int arr[n][m];
//     int i, j;
//     int min_num = 1000002;
//     int min_index;
//     int sum = 0;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < m; j++)
//         {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for (i = 0; i < n; i++)
//     {
//         if (arr[i][0] < min_num)
//         {
//             min_num = arr[i][0];
//             min_index = i;
//         }
//     }
//     sum += arr[min_index][0];
//     for (j = 1; j < m; j++)
//     {
//         if (min_index != n-1)
//         {
//             if (arr[min_index][j] < arr[min_index + 1][j])
//             {
//                 sum += arr[min_index][j];
//             }
//             else
//             {
//                 sum += arr[++min_index][j];
//             }
//         }
//         else
//         {
//             if (arr[min_index][j] < arr[0][j])
//             {
//                 sum += arr[min_index][j];
//             }
//             else
//             {
//                 sum += arr[0][j];
//                 min_index = 0;
//             }
//         }
//     }
//     printf("%d", sum);

//     return 0;
// }

// 
// void print(char* str, int n)
// {
//     if (str[0] != 100)
//     {
//         str++;
//         print(str, n - 1);
//     }
//     else
//     {
//         return;
//     }

//     str--;
//     putchar(str[0]);
// }
// int main()
// {
//     int m, n;
//     char str[32];
//     char ans[32];
//     scanf("%d", &m);
//     scanf("%s", str);
//     scanf("%d", &n);
//     int len = strlen(str);
//     int ret = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             str[i] -= 55;
//         }
//         else
//         {
//             str[i] -= '0';
//         }
//     }
//     for (int i = len - 1; i >= 0; i--)
//     {
//         ret += pow(m, len - 1 - i) * str[i];
//     }
//     int i = 0;
//     while (ret)
//     {
//         ans[i] = ret % n;
//         ret /= n;
//         if (ans[i] >= 10 && ans[i] <= 33)//这里33只是偷懒
//         {
//             ans[i] += 55;
//         }
//         else
//         {
//             ans[i] += '0';
//         }
//         i++;
//     }
//     ans[i] = 126;//结束条件
//     i--;
//     print(ans, i);//递归打印

//     return 0;
// }

int main()
{
    int k;
    scanf("%d", &k);
    int i;
    int count = 0;
    int index = 0;
    int j = 0;
    int ans = k + 1;
    while (1)
    {
        index += ans - 1;
        while (index > 2 * k - 1 - count)
        {
            index %= 2 * k - count;
        }

        if (index >= 0 && index <= k - 1)
        {
            count = 0;
            ans++;
            index = 0;
            continue;
        }
        else
        {
            count++;
            if (count == k)
            {
                printf("%d", ans);
                break;
            }
        }
    }

    return 0;
}