#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

void to_file(int* arr);

void sort1(int* arr, int* end);
void sort2(int* arr, int* end);
void sort3(int* arr, int* end);
void quicksort(int* arr, int left, int right);
int search_pivot(int* arr, int left, int right);

#define SIZE 100000000
int arr[SIZE];
double procedure_time;
int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }
    int begin = clock();
    //sort1(arr, arr + SIZE);
    //sort2(arr, arr + SIZE);
    sort3(arr, arr + SIZE);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    int end = clock();
    procedure_time = (double)(end - begin)/1000.0;
    to_file(arr);

    return 0;
}

void sort1(int* arr, int* end)
{
    int i, j, tmp;
    int n = end - arr;
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

void sort2(int* arr, int* end)
{
    int i, j, tmp, increment;
    int n = end - arr;
    for (increment = n / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < n; i++)
        {
            tmp = arr[i];
            for (j = i; j - increment >= 0 && arr[j - increment] > tmp; j -= increment)
            {
                arr[j] = arr[j - increment];
            }
            arr[j] = tmp;
        }
    }
}

void sort3(int* arr, int* end)
{
    quicksort(arr, 0, end-arr-1);
}

void quicksort(int* arr, int left, int right)
{
    int i = left, j = right;
    if (left + 3 <= right)
    {
        int pivot = search_pivot(arr, left, right);
        while (1)
        {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);

            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
            else
            {
                break;
            }
        }
        swap(arr[i], arr[right]);
        quicksort(arr, left, i - 1);
        quicksort(arr, i + 1, right);
    }
    else
    {
        sort1(arr + left, arr + right + 1);
    }
}

int search_pivot(int* arr, int left, int right)
{
    int middle = (left + right) / 2;
    if (arr[left] > arr[middle])
    {
        swap(arr[left], arr[middle]);
    }
    if (arr[middle] > arr[right])
    {
        swap(arr[middle], arr[right]);
    }
    if (arr[left] > arr[middle])
    {
        swap(arr[left], arr[middle]);
    }

    swap(arr[middle], arr[right]);
    return arr[right];
}

void to_file(int* arr)
{
    ofstream ofs;
    ofs.open("sort1.out", ios::out);
    ofs << "用时: " << procedure_time;
    for (int i = 0; i < SIZE; i++)
    {
        ofs << arr[i] << '\n';
    }
    ofs << endl;
    ofs.close();
}
