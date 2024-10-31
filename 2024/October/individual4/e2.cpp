#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9 + 7;
ll pwrs[1000005];

ll val(char a)
{
    return a + 1;
}

string ans;

ll ret(string b)
{
    ll runpref = 0;
    ll runsuf = 0;
    ll res = -1;
    ll aptr = ans.length() - 1;
    ll bptr = 0;

    ll mini = min(ans.length(), b.length());

    for (ll i = 0; i < mini; i++)
    {
        runpref = runpref * 257 + val(b[bptr + i]);
        if (runpref >= MOD)
            runpref %= MOD;

        runsuf = runsuf + pwrs[i] * val(ans[aptr - i]);
        if (runsuf >= MOD)
            runsuf %= MOD;

        if (runpref == runsuf)
            res = i;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 0; i < 1000005; i++)
        if (i == 0)
            pwrs[i] = 1;
        else
            pwrs[i] = (257 * pwrs[i - 1]) % MOD;

    ll n;
    cin >> n;
    string A[n];
    for (ll i = 0; i < n; i++)
        cin >> A[i];

    ans = A[0];

    for (ll i = 1; i < n; i++)
    {
        ll nxt = ret(A[i]);
        for (ll j = nxt + 1; j < A[i].length(); j++)
            ans.push_back(A[i][j]);
    }
    cout << ans << '\n';
}