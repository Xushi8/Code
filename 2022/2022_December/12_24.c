#include<stdio.h>
#include<stdlib.h>

// int main()
// {
//     int n;
//     int code[7];
//     int prize[7] = {0};
//     int arr[7];
//     scanf("%d", &n);
//     scanf("%d %d %d %d %d %d %d", 
//                                 &code[0], &code[1], &code[2],
//                                 &code[3], &code[4], &code[5], &code[6]);
//     int i,j,k;
//     for(i = 0; i<n; i++)
//     {
//         int count = 0;
//         scanf("%d %d %d %d %d %d %d", 
//                                 &arr[0], &arr[1], &arr[2],
//                                 &arr[3], &arr[4], &arr[5], &arr[6]);
//         for(j = 0; j<7; j++)
//         {
//             for(k = 0; k<7; k++)
//             {
//                 if(arr[j] == code[k])
//                 {
//                     count++;
//                 }
//             }
//         }           

//         if(count == 0)
//         {
//             continue;
//         }           

//         prize[7-count]++;
//     }

//     printf("%d", prize[0]);
//     for(i = 1; i<7; i++)
//     {
//         printf(" %d", prize[i]);
//     }
//     return 0;
// }

// int buyer[1000];

// int main()
// {
//     int m,n;
//     scanf("%d %d", &m, &n);
//     for(int i = 0; i<n; i++)
//     {
//         scanf("%d", &buyer[i]);
//     }
//     for(int i = 0; i<n; i++)
//     {
//         for(int j = 0; j<n-1; j++)
//         {
//             if(buyer[j] < buyer[j+1])
//             {
//                 int ret = buyer[j];
//                 buyer[j] = buyer[j+1];
//                 buyer[j+1] = ret;
//             }
//         }
//     }

//     int max = -1;
//     int _ret = -1;
//     int i,j,k;
//     for(i = 0; i<m; i++)
//     {
//         if(buyer[i]*(i+1) >= max)
//         {
//             max = buyer[i]*(i+1);
//             _ret = i;
//         }
//     }

//     printf("%d %d", buyer[_ret], max);

//     return 0;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int x = 1;
//     int y = 1;
//     int z = 1;
//     int count = 0;
//     while(1)
//     {
//         count += x;
//         y--;
//         if(y == 0)
//         {
//             x++;
//             y = x;
//             z += x;
//         }
//         if(z > n)
//         {
//             z -= x;
//             break;
//         }
//     }
//     while(z < n)
//     {
//         count += x;
//         z++;
//     }
//     printf("%d", count);
//     return 0;
// }

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int arr[10000];
    int i;
    for(i = 0; i<9999; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
    printf("\n");printf("\n");

    qsort(arr, 9999, sizeof(int), compare);
    for(i = 0; i<9999; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}