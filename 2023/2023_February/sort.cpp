#include<bits/stdc++.h>
using namespace std;

int find_pivot(int* arr, int left, int right);
void insert_sort(int* arr, int* end);
void shell_sort(int* arr, int* end);
void quick_sort(int* arr, int* end);
void Qsort(int* arr, int left, int right);
void print_arr(int* arr, size_t n);
void to_file(int* arr, size_t n);
void init_array(int* arr, size_t n);

const int SIZE = 450000000;
int ar[SIZE];
int main()
{
    srand((unsigned int)time(NULL));
    cout << "数据量: " << SIZE << endl;
    init_array(ar, SIZE);
    int begin, end;
    //to_file(ar, SIZE);
    //system("pause");
    
    // begin = clock();
    // insert_sort(ar, ar + SIZE);
    // end = clock();
    // cout << "插入排序时间: " << (end - begin) / 1000.0 << endl;

    // init_array(ar, SIZE);
    // begin = clock();
    // shell_sort(ar, ar + SIZE);
    // end = clock();
    // cout << "希尔排序时间: " << (end - begin) / 1000.0 << endl;

    init_array(ar, SIZE);
    begin = clock();
    quick_sort(ar, ar + SIZE);
    end = clock();
    cout << "快速排序时间: " << (end - begin) / 1000.0 << endl;

    init_array(ar, SIZE);
    begin = clock();
    sort(ar, ar + SIZE);
    end = clock();
    cout << "STL快速排序时间: " << (end - begin) / 1000.0 << endl;

    //to_file(ar, SIZE);

    system("pause"); 
    return 0;
}

int find_pivot(int* arr, int left, int right)
{
    int middle = (right + left) / 2;
    if (arr[left] > arr[middle]) swap(arr[left], arr[middle]);
    if (arr[middle] > arr[right]) swap(arr[middle], arr[right]);
    if (arr[left] > arr[middle]) swap(arr[left], arr[middle]);

    swap(arr[middle], arr[right]);
    return arr[right];
}

void insert_sort(int* arr, int* end)
{
    int n = (int)(end - arr);
    int i;
    int j;
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
    int n = (int)(end - arr);
    int i, j, tmp;
    int increment;
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

void quick_sort(int* arr, int* end)
{
    Qsort(arr, 0, (int)(end - arr - 1));
}

void Qsort(int* arr, int left, int right)
{
    int i = left, j = right;
    if (i + 32 <= right)
    {
        int pivot = find_pivot(arr, left, right);
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
}

void print_arr(int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
    cout << endl;
}

void to_file(int* arr, size_t n)
{
    ofstream ofs;
    ofs.open("sort.out", ios::out);
    for (size_t i = 0; i < n; i++)
    {
        ofs << arr[i] << '\n';
    }
    ofs << endl;
    ofs.close();
}

void init_array(int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}