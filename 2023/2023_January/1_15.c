#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// void swap(int* a, int* b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int search_piovt(int* arr, int left, int right)
// {
//     int middle = (left + right) / 2;
//     if (arr[left] > arr[middle])
//     {
//         swap(&arr[left], &arr[middle]);
//     }
//     if (arr[middle] > arr[right])
//     {
//         swap(&arr[middle], &arr[right]);
//     }
//     if (arr[left] > arr[middle])
//     {
//         swap(&arr[left], &arr[middle]);
//     }

//     swap(&arr[middle], &arr[right]);
//     return arr[right];
// }

// void insertsort(int* arr, int* end)
// {
//     int i, j;
//     int tmp;
//     int n = end - arr;
//     for (i = 1; i < n; i++)
//     {
//         tmp = arr[i];
//         for (j = i; j > 0 && arr[j - 1] > tmp; j--)
//         {
//             arr[j] = arr[j - 1];
//         }
//         arr[j] = tmp;
//     }
// }

// void quicksort(int* arr, int left, int right)
// {
//     int i= left, j = right;
//     int pivot = search_piovt(arr, left, right);
//     if (left + 3 <= right)
//     {
//         while (1)
//         {
//             while (arr[++i] < pivot)
//             {
//                 continue;
//             }
//             while (arr[--j] > pivot)
//             {
//                 continue;
//             }

//             if (i < j)
//             {
//                 swap(&arr[i], &arr[j]);
//             }
//             else
//             {
//                 break;
//             }
//         }

//         swap(&arr[i], &arr[right]);

//         quicksort(arr, left, i - 1);
//         quicksort(arr, i + 1, right);
//     }
//     else
//     {
//         insertsort(arr + left, arr + right + 1);
//     }
// }

// void my_sort(int* arr, int* end)
// {
//     quicksort(arr, 0, end - arr - 1);
// }

// int arr[10000005];
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     my_sort(arr, arr + i);
//     printf("%d", arr[0]);
//     for (i = 1; i < n; i++)
//     {
//         printf(" %d", arr[i]);
//     }

//     return 0;
// }

int main()
{
    

    return 0;
}