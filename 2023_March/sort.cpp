#include<bits/stdc++.h>
using namespace std;

void insert_sort(int* arr, int* end)
{
    int i, j, tmp;
    size_t n = end - arr;
    for (i = 1; i < (int)n; i++)
    {
        tmp = arr[i];
        for (j = i; j - 1 >= 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

int search_pivot(int* arr, int left, int right)
{
    int middle = (right + left) / 2;
    if (arr[left] > arr[middle]) swap(arr[left], arr[middle]);
    if (arr[middle] > arr[right]) swap(arr[middle], arr[right]);
    if (arr[left] > arr[middle]) swap(arr[left], arr[middle]);

    swap(arr[right], arr[middle]);
    return arr[right];
}

void Qsort(int* arr, int left, int right)
{
    int i = left, j = right;
    if (left + 3 <= right)
    {
        int pivot = search_pivot(arr, left, right);
        while (1)
        {
            while (arr[++i] < pivot) {}
            while (arr[--j] > pivot) {}

            if (i < j)
            {
                swap(arr[j], arr[i]);
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

void quick_sort(int* begin, int* end)
{
    Qsort(begin, 0, (int)(end - begin) - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int begin, end;

    begin = clock();
    int arr[10000000];
    for(int i = 0; i < 10000000; i++)
    {
        arr[i] = rand();
    }
    sort(arr, arr + 10000000);
    for (int i = 0; i < 10000000; i++)
    {
        cout << arr[i] << '\n';
    }
    end = clock();
    ofstream ofs;
    ofs.open("vector与数组.out", ios::out);
    ofs << (end - begin) / 1000.0 << '\n';

    begin = clock();
    vector<int> v;
    v.reserve(10000000);
    for (int i = 0; i < 10000000; i++)
    {
        v.push_back(rand());
    }
    
    sort(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << '\n';
    }
    
    end = clock();
    ofs << (end - begin) / 1000.0 << '\n';

    system("pause");
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int arr[10] = { 54,542,233,12,43,43,2,34,34,2 };
//     sort(arr, arr + 10);
//     for(int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << endl;
//     }

//     system("pause");
//     return 0;
// }