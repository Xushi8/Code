// 2023/09/09 17:05:24
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
constexpr ll mod = 998244353;

ll fast_pow(ll a, ll n)
{
    ll res = 1;
    while (n != 0)
    {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), cnta(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cnta[i];
    }

    int m;
    cin >> m;
    vector<int> b(m), cntb(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> cntb[i];
    }

    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (a[i] > b[j])
        {
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            int t = min(cnta[i], cntb[j]);
            cnta[i] -= t; cntb[j] -= t;
            i++; j++;
        }
    }

    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; i++)
    {
        suma += cnta[i];
    }
    for (int i = 0; i < m; i++)
    {
        sumb += cntb[i];
    }

    ll ans = 0;
    if (sumb != 0)
        ans = 0;
    else
    {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (cnta[i] != 0)
                st.emplace(a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            if (cntb[i] != 0)
                st.emplace(b[i]);
        }
        size_t cnt = st.size();

        ans = fast_pow(2, cnt);
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}