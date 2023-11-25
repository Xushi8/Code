// 2023/11/25 16:34:11
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

ll arr[N], tmp[N];

ll solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    auto check = [&](int val) -> bool
    {
        for (int i = 0; i < val; i++)
        {
            tmp[i] = arr[i];
        }

        int p = val;
        for (int i = val; i < val * k; i++)
        {
            while(p < n && arr[p] < tmp[i - val] * 2) {
                p++;
            }

            if(p == n) {
                return false;
            }

            tmp[i] = arr[p];
            p++;
        }

        return true;
    };

    int l = 0, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": " << solve() << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}