#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

// int gcd(int a, int b)
// {
//     do
//     {
//         int tmp = b;
//         b = a % b;
//         a = tmp;
//     } while (b);
//     return a;
// }

// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     printf("%d", gcd(a, b));

//     system("pause");
//     return 0;
// }

// void insert_sort(int* arr, int* end)
// {
//     int i, j, tmp, n;
//     n = end - arr;
//     for (i = 1; i < n; i++)
//     {
//         tmp = arr[i];
//         for (j = i; j - 1 >= 0 && arr[j - 1] > tmp; j--)
//         {
//             arr[j] = arr[j - 1];
//         }
//         arr[j] = tmp;
//         for (int k = 0; k < n; k++)
//         {
//             printf("%d ", arr[k]);
//         }
//         putchar('\n');
//     }
// }

// int arr[105];
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     putchar('\n');
//     insert_sort(arr, arr + n);

//     system("pause");
//     return 0;
// }

int arr[2000005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min_num = arr[0], max_num = 0;
    for (int i = 1; i < n; i++)
    {
        if (max_num < arr[i] - min_num) max_num = arr[i] - min_num;
        if (min_num > arr[i]) min_num = arr[i];
    }
    if (max_num != 0)
        printf("%d", max_num);
    else
        printf("-1");

    system("pause");
    return 0;
}