// 2023/07/17 22:34:46
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
#include <bitset>
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

    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }


    /*
    8
    45 45 12 546 78 2 45 45
    */

    sort(arr.begin(), arr.end());

    // pii now = arr[0];
    // vector<int> same_start_index;
    // int count = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i].first == now.first)
    //     {
    //         count++;
    //     }
    //     else
    //     {
    //         if (count > 1)
    //         {
    //             auto x = lower_bound(arr.begin(), arr.end(), now) - arr.begin();
    //             same_start_index.emplace_back(x);
    //             count = 1;
    //             now = arr[i];
    //         }
    //     }
    // }

    // if (same_start_index[0] == 0)
    // {
    //     sort(lower_bound(arr.begin(), arr.end(), arr[0]), upper_bound(arr.begin(), arr.end(), arr[0]), greater<pii>());
    // }

    // for (size_t i = 1; i < same_start_index.size(); i++)
    // {
    //     auto it1 = lower_bound(arr.begin(), arr.end(), arr[same_start_index[i]]);
    //     auto it2 = upper_bound(arr.begin(), arr.end(), arr[same_start_index[i]]);
    //     sort(it1, it2, greater<pii>());
    // }

    // int ans = 0;

    // bool flag = 0;
    // int lst = 0;
    // for (size_t i = 1; i < same_start_index.size(); i++)
    // {
    //     auto it1 = lower_bound(arr.begin(), arr.end(), arr[same_start_index[i]]);
    //     auto it2 = upper_bound(arr.begin(), arr.end(), arr[same_start_index[i]]);
    //     sort(it1, it2, greater<pii>());
    //     int maxn = INT32_MIN;
    //     int minn = INT32_MAX;
    //     for (; it1 < it2; it1++)
    //     {
    //         maxn = max(maxn, it1->second);
    //         minn = min(minn, it1->second);
    //     }

    //     if (!flag)
    //     {
    //         if (maxn < lst)
    //             lst = minn;
    //         else
    //         {
    //             lst = maxn;
    //             flag = 1;
    //         }
    //     }
    //     else
    //     {
    //         if (minn > lst)
    //             lst = maxn;
    //         else
    //         {
    //             lst = minn;
    //             ans++;
    //             flag = 0;
    //         }
    //     }
    // }


    // int ans = 0;
    // for (int i = 1; i < n - 1; i++)
    // {
    //     if (arr[i].second < arr[i - 1].second && arr[i].second < arr[i + 1].second)
    //         ans++;
    // }
    // if (arr[0] < arr[1])
    //     ans++;
    // if (arr[n - 1] < arr[n - 2])
    //     ans++;


    int ans = 0;
    bool flag = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        int maxn = arr[i].second;
        int minn = arr[i].second;
        while (pos < n && arr[pos].first == arr[pos + 1].first)
        {
            maxn = max(maxn, arr[pos + 1].second);
            minn = min(minn, arr[pos + 1].second);
            pos++;
        }

        if (!flag)
        {
            if (maxn < tmp)
                tmp = minn;
            else
            {
                tmp = maxn;
                flag = 1;
            }
        }
        else
        {
            if (minn > tmp)
                tmp = maxn;
            else
            {
                tmp = minn;
                ans++;
                flag = 0;
            }
        }
        i = pos;
    }

    cout << ans << '\n';

    cout << flush;
    return 0;
}


