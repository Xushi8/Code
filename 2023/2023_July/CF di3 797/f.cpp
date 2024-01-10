// 2023/07/16 17:22:49
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
const int N = 205;

bool vis[N];

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i], arr[i]--;

    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;

        int x = arr[i];
        vector<int> loop;
        loop.emplace_back(x);
        vis[x] = 1;
        while (x != i)
        {
            x = arr[x];
            loop.emplace_back(x);
            vis[x] = 1;
        }

        unordered_map<int, int> m;
        for (size_t j = 0; j < loop.size(); j++)
        {
            char ch = s[loop[j]];
            size_t cnt = 0;
            while (cnt < loop.size())
            {
                cnt++;
                loop[j] = arr[loop[j]];
                if (s[loop[j]] == ch)
                    m[(int)cnt]++;
            }
        }

        ll minn = INF;
        for (auto [u, v] : m)
        {
            if (v == (int)loop.size())
            {
                minn = min(minn, (ll)u);
            }
        }

        ans = ans / __gcd(minn, ans) * minn;
    }

    cout << ans << '\n';
    memset(vis, 0, sizeof(vis));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    cout << endl;
    return 0;
}