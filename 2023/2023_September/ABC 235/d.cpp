// 2023/09/03 15:04:33
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000000;

ll dp[N];
ll a, n;

ll get_reverse(ll i)
{
    string s = to_string(i);
    char ch = s.back();
    for (size_t j = s.size() - 1; j >= 1; j--)
    {
        s[j] = s[j - 1];
    }
    s.front() = ch;
    return stoll(s);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> a >> n;
    ll ans = 0;
    ll now = 1;
    while (now <= 10)
    {
        dp[now] = ans;
        ans++;
        now *= a;
    }
    dp[now] = ans;

    queue<ll> que;
    que.emplace(now);
    while (!que.empty())
    {
        ll l = que.front(); que.pop();
        if (l * a < N && dp[l * a] == -1)
        {
            dp[l * a] = dp[l] + 1;
            que.emplace(l * a);
        }
        
        if (l % 10 != 0)
        {
            ll r = get_reverse(l);
            if (r < N && dp[r] == -1)
            {
                dp[r] = dp[l] + 1;
                que.emplace(r);
            }
        }
    }

    cout << dp[n] << '\n';

    // for (int i = 1; i <= n; i++)
    // {
    //     cerr << i << ' ' << dp[i] << '\n';
    // }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}