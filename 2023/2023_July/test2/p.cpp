// 2023/07/21 10:15:03
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h;
    cin >> h;
    vector<int> arr(h + 1);
    for (int i = 0; i <= h; i++)
        cin >> arr[i];

    int begin_index = -1;
    for (int i = 1; i <= h - 1; i++)
    {
        if (arr[i] > 1 && arr[i + 1] > 1)
        {
            begin_index = i;
            break;
        }
    }

    if (begin_index == -1)
    {
        cout << "perfect\n";
    }
    else
    {
        cout << "ambiguous\n";
        vector<int> a, b;
        int begin = 0; // 上一层最后节点的index
        for (int i = 0; i <= begin_index; i++)
        {
            for (int j = 0; j < arr[i]; j++)
                a.emplace_back(begin);

            begin += arr[i];
        }
        b = a;

        // for (int j = 0; j < arr[begin_index + 1]; j++)
        // {
        //     a.emplace_back(begin);
        //     b.emplace_back(begin - 1);
        // }

        a.emplace_back(begin);
        a.emplace_back(begin);
        b.emplace_back(begin);
        b.emplace_back(begin - 1);

        for (int j = 2; j < arr[begin_index + 1]; j++)
        {
            a.emplace_back(begin);
            b.emplace_back(begin);
        }

        begin += arr[begin_index + 1];

        for (int i = begin_index + 2; i <= h; i++)
        {
            for (int j = 0; j < arr[i]; j++)
                a.emplace_back(begin), b.emplace_back(begin);

            begin += arr[i];
        }

        for (size_t i = 0; i < a.size(); i++)
            cout << a[i] << " \n"[i == a.size() - 1];
        for (size_t i = 0; i < a.size(); i++)
            cout << b[i] << " \n"[i == a.size() - 1];
    }

    cout << endl;
    return 0;
}