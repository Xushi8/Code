#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int ar[10] = { 1,3,5,32,4,6,2,5,7,3 };

void print_arr(int* arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void insert_sort(int* arr, int* end)
{
    int i, j;
    int n = (int)(end - arr);
    int tmp;
    for (i = 1; i < n; i++)
    {
        tmp = arr[i];
        for (j = i; j - 1 >= 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}
void shell_sort(int* arr, int* end)
{
    int i, j, k;
    int n = (int)(end - arr);
    int tmp;
    for (k = n >> 1; k > 0; k >>= 1)
    {
        for (i = k; i < n; i++)
        {
            tmp = arr[i];
            for (j = i; j - k >= 0 && arr[j - k] > tmp; j -= k)
            {
                arr[j] = arr[j - k];
            }
            arr[j] = tmp;
        }
    }
}

int search_pivot(int* arr, int left, int right)
{
    int middle = (right + left) / 2;
    if (arr[left] > arr[middle]) swap(arr[left], arr[middle]);
    if (arr[middle] > arr[right]) swap(arr[middle], arr[right]);
    if (arr[left] > arr[middle]) swap(arr[left], arr[middle]);

    swap(arr[middle], arr[right]);
    return arr[right];
}

void Qsort(int* arr, int left, int right)
{
    int i, j;
    i = left;
    j = right;
    if (left + 3 <= right)
    {
        int pivot = search_pivot(arr, left, right);
        while (1)
        {
            while (arr[++i] < pivot) {}
            while (arr[--j] > pivot) {}

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
        Qsort(arr, left, i - 1);
        Qsort(arr, i + 1, right);
    }
    else
    {
        insert_sort(arr + left, arr + right + 1);
    }
}

void quick_sort(int* arr, int* end)
{
    Qsort(arr, 0, (int)(end - arr) - 1);
}
#include<fstream>
void to_file(int* arr, int num)
{
    ofstream ofs;
    ofs.open("sort.out", ios::out);
    for (int i = 0; i < num; i++)
    {
        ofs << arr[i] << ' ';
    }
    ofs << endl;
    ofs.close();
}
#include<ctime>
const int max_arr = 1000000;
int test[max_arr];
void init_arr(int* arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        arr[i] = rand();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    init_arr(test, max_arr);
    //insert_sort(ar, ar + 10);
    //shell_sort(ar, ar + 10);
    quick_sort(test, test + max_arr);
    to_file(test, max_arr);

    system("pause");
    return 0;
}