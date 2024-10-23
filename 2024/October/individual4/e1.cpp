#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9 + 7;
ll pwrs[100005];

ll val(char a)
{
    return a + 1;
}

string ans;

ll ret(string b)
{
    string a = ans;
    ll runpref = 0;
    ll runsuf = 0;
    ll ans = -1;
    ll aptr = a.length() - 1;
    ll bptr = 0;

    ll mini = min(a.length(), b.length());

    for (ll i = 0; i < mini; i++)
    {
        runpref = runpref * 26 + val(b[bptr + i]);
        if (runpref >= MOD)
            runpref -= MOD;

        runsuf = runsuf + pwrs[i] * val(a[aptr - i]);
        if (runsuf >= MOD)
            runsuf -= MOD;

        if (runpref == runsuf)
            ans = i;
    }
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 0; i < 100005; i++)
        if (i == 0)
            pwrs[i] = 1;
        else
            pwrs[i] = (26 * pwrs[i - 1]) % MOD;

    ll n;
    cin >> n;
    string A[n];
    for (ll i = 0; i < n; i++)
        cin >> A[i];

    ans = "";

    for (ll i = 0; i < n - 1; i++)
    {
        if (i == 0)
            ans += A[i];
        ll nxt = ret(A[i + 1]);
        for (ll j = nxt + 1; j < A[i + 1].length(); j++)
            ans.push_back(A[i + 1][j]);
    }
    cout << ans << "\n";
}