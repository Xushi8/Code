// 2023/12/03 13:19:01
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    n *= 2;
    vector<int> arr(n);
    for (int& x : arr)
    {
        cin >> x;
    }

    size_t i = 0;
    vector<int> a, b;
    int flag = 0;
    while (i < n)
    {
        size_t j = i + 1;
        while (j < n && arr[j] < arr[i])
        {
            j++;
        }
        int len = j - i;
        if (j != n)
        {
            if (arr[j] >= arr[i])
            {
                if (a.size() < b.size())
                {
                    flag = 1;
                }
                else
                {
                    flag = 2;
                }
            }
            else
            {
                flag = 1;
            }
        }
        else
        {
            if (a.size() < b.size())
            {
                flag = 1;
            }
            else
            {
                flag = 2;
            }
        }
        if (flag == 1)
        {
            for (size_t x = i; x < j; x++)
            {
                a.emplace_back(arr[x]);
            }
        }
        else
        {
            for (size_t x = i; x < j; x++)
            {
                b.emplace_back(arr[x]);
            }
        }
        i = j;
    }

    if (a.size() > n / 2 || b.size() > n / 2)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int x : a)
        {
            cout << x << ' ';
        }
        cout << '\n';
        for (int y : b)
        {
            cout << y << ' ';
        }
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}