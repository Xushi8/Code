// 2025/03/05 13:45:48
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i != a[i])
        {
            swap(a[i], a[a[i]]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != a[i])
        {
            ans.emplace_back(a[i] + 1);
        }
    }

    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
