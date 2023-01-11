#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

void print(int arr[])
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void reverse(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//��������
void sort1(int* arr, int* end)
{
    int n = end - arr;
    int i, j;
    for (i = 1; i < n; i++)
    {
        int k = i;
        for (j = k - 1; j >= 0; j--)
        {
            if (arr[j] > arr[k])
            {
                reverse(arr + j, arr + k);
                k--;
            }
        }
    }
}

//ϣ������
void sort2(int* arr, int* end)
{
    int n = end - arr;
    int increment;
    int i, j, k;
    for (increment = n / 2; increment > 0; increment /= 2)
    {
        for (i = 1; i < n; i += increment)
        {
            int k = i;
            for (j = k - increment; j >= 0; j -= increment)
            {
                if (arr[j] > arr[k])
                {
                    reverse(arr + j, arr + k);
                    k -= increment;
                }
            }
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int begin, end;
    int arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 100;
    }
    print(arr);
    begin = clock();
    //sort1(arr, arr + 100);
    sort2(arr, arr + 100);
    end = clock();
    print(arr);
    printf("ʱ��: %dms", end - begin);


    return 0;
}