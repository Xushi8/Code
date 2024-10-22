#include <algorithm>
#include <fmt/ranges.h>
using fmt::print;
int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void insert_sort(int* begin, int* end)
{
    int* arr = begin;
    int n = end - begin;
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        int j;
        for (j = i; j - 1 >= 0 && arr[j - 1] > val; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = val;
    }
}

void quick_sort(int* begin, int* end)
{
    const int n = end - begin;
    if (n < 3)
    {
        insert_sort(begin, end);
        return;
    }

    int* arr = begin;
    int pivot = arr[0];
    int l = 0, r = n - 1;
    while (1)
    {
        while (l + 1 < n && arr[l] <= pivot)
        {
            l++;
        }
        while (r - 1 >= 0 && arr[r] >= pivot)
        {
            r--;
        }
        if (l < r)
        {
            std::swap(arr[l], arr[r]);
            l++;
            r--;
        }
        else
        {
            break;
        }
    }

    std::swap(arr[r], arr[0]);

    quick_sort(begin, begin + l);
    quick_sort(begin + l, end);
}

int main()
{
    quick_sort(a, a + 10);

    print("{}\n", a);
}