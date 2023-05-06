#include<stdio.h>
#include<stdlib.h>

int arr1[10000];
int arr2[10000];
int small_compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int big_compare(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    scanf("%d", &arr1[0]);
    int i = 0;
    double sum = 0.0f;
    int j = 0;
    while(arr1[i] != -1)
    {
        if(arr1[i]<=100)
        {
            sum += arr1[i];
            j++;
        }
        i++;
        scanf("%d", &arr1[i]);
    }
    int n;
    scanf("%d", &n);
    
    double average = sum/j;
    printf("%.2lf\n", average);
    
    qsort(arr1, i+1, sizeof(int), big_compare);
    i = 0;
    while(arr1[i] > average)
    {
        arr2[i] = arr1[i];
        i++;
    }
    if(n == 1)
    {
        qsort(arr2, i, sizeof(int), big_compare);
    }
    else
    {
        qsort(arr2, i, sizeof(int), small_compare);
    }
    
    i = 0;
    while(arr2[i] > 0)
    {
        if(arr2[i]<=100)
        {
            printf("%d ", arr2[i]);
        }
        i++;
    }
    
    return 0;
}