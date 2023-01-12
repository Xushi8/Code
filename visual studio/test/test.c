#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define SIZE 10000000//���ݴ�С


void print(int arr[])
{
    for (int i = 0; i < SIZE; i++)
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

int search_pivot(int* arr, int left, int right)
{
    int middle = (left + right) / 2;
    if (arr[left] > arr[middle])
    {
        reverse(&arr[left], &arr[middle]);
    }
    if (arr[middle] > arr[right])
    {
        reverse(&arr[middle], &arr[right]);
    }
    if (arr[left] > arr[middle])
    {
        reverse(&arr[left], &arr[middle]);
    }

    reverse(&arr[middle], &arr[right]);
    return arr[right];
}

//��������
void sort1(int* arr, int* end)
{
    int n = end - arr;
    int i, j;
    int tmp;
    for (i = 1; i < n; i++)
    {
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[j] = tmp;
    }
}

//ϣ������
void sort2(int* arr, int* end)
{
    int n = end - arr;
    int increment;
    int i, j;
    int tmp;
    for (increment = n / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < n; i++)
        {
            tmp = arr[i];
            for (j = i; j >= increment && arr[j - increment] > tmp; j -= increment)
            {
                arr[j] = arr[j - increment];
            }

            arr[j] = tmp;
        }
    }
}

void quick_sort(int* arr, int left, int right)
{
    int i = left, j = right;
    int pivot = search_pivot(arr, left, right);

    if (left + 3 <= right)
    {
        while (1)
        {
            while (arr[++i] < pivot)
                continue;
            while (arr[--j] > pivot)
                continue;

            if (i < j)
            {
                reverse(&arr[i], &arr[j]);
            }
            else
            {
                break;
            }
        }

        reverse(&arr[i], &arr[right]);

        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
    else
    {
        sort1(arr + left, arr + right + 1);
    }

}

void sort3(int* arr, int* end)
{
    quick_sort(arr, 0, end - arr - 1);//�������������Ҳ��±�
}

int arr[SIZE];
int main()
{
    srand((unsigned)time(NULL));
    int begin, end;
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10;
    }
    puts("��ʱ��ʼ");
    //print(arr);
    begin = clock();
    //sort1(arr, arr + SIZE);
    //sort2(arr, arr + SIZE);
    //sort3(arr, arr + SIZE);
    end = clock();
    //print(arr);
    printf("��ʱ: %dms\n", end - begin);

    system("pause");
    return 0;
}