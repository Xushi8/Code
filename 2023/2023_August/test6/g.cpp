// 2023/08/04 09:12:43
#ifndef LOCAL
#pragma GCC optimize(2)
#endif
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

    int n, m, d, l;
    cin >> n >> m >> d >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    vector<int> speed;
    for (int i = 0; l + d * i <= arr.back(); i++)
    {
        speed.emplace_back(l + d * i);
    }

    ll ans = 0;
    int index = 0, pre_index = 0;
    for (int i = 0; i < (int)speed.size(); i++)
    {
        index = (int)(lower_bound(arr.begin(), arr.end(), l + d * i) - arr.begin());
        index = max(index, pre_index);
        for (int j = 0; j < m; j++)
        {
            if (index < n)
            {
                ans++;
                index++;
                pre_index = index;
            }
            else
            {
                goto out;
            }
        }
    }

out:
    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}