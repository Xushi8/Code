// 2023/09/18 19:51:37
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
constexpr int N = 1000005;

ll cnt[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> in(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        in[p[i]] += c[i];
    }

    set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++)
    {
        st.emplace(in[i], i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto now = *st.begin(); st.erase(st.begin());
        ans += now.first;
        auto it = st.find(make_pair(in[p[now.second]], p[now.second]));
        if (it != st.end())
        {
            auto tmp = *it; st.erase(it);
            in[p[now.second]] -= c[now.second];
            tmp.first -= c[now.second];
            st.emplace(tmp);
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}