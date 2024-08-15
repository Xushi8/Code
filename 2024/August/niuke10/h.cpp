#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
using namespace std;

int n, m;
int ans;
int inv;
const int mod = 998244353;
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
vector<int> ansp;
vector<int> ansP;
set<int> X;
map<int, int> mp;
void lock(int x, int y, int z, int step)
{
    z <<= 1;
    step++;
    // cout<<x<<"ss"<<y<<"aa"<<step<<endl;
    if (X.count(x) > 0)
    {
        int left = mp[x];
        int right = step;
        int len = qpow(2, right - left);
        // cout<<left<<endl<<right<<endl<<len<<endl;

        if (left != 1)
        {
            ansp.push_back(ansp[left - 1]);
            ansP.push_back(ansP[left - 1] * (len - 1) % mod);
        }
        else
        {
            ansp.push_back(1);
            ansP.push_back((len - 1));
        }

        return;
    }
    if (x == y)
    {
        ansp.push_back(ansp[ansp.size() - 1] * (z / ansP[ansP.size() - 1]) % mod);
        ansP.push_back(z);
        ansp[ansp.size() - 1]++;
        return;
    }
    else if (x < y)
    {
        X.insert(x);
        mp[x] = step;
        int lx = x << 1;
        int ly = y - x;
        ansp.push_back(ansp[ansp.size() - 1] * (z / ansP[ansP.size() - 1]) % mod);
        ansP.push_back(z);
        ansp[ansp.size() - 1]++;
        lock(lx, ly, z, step);
    }
    else
    {
        X.insert(x);
        mp[x] = step;
        ansp.push_back(ansp[ansp.size() - 1] * (z / ansP[ansP.size() - 1]) % mod);
        ansP.push_back(z);
        ansp[ansp.size() - 1]++;
        int lx = x - y;
        int ly = y << 1;
        lock(lx, ly, z, step);
    }
}
void solve()
{
    cin >> n >> m;
    inv = qpow(2, mod - 2);
    if (n == m)
    {
        cout << inv << " " << inv << endl;
    }
    else
    {
        ansp.push_back(0);
        ansP.push_back(1);
        lock(n, m, 1, 0);
        int p = ansp[ansp.size() - 1];
        int P = ansP[ansP.size() - 1];
        int _p = P - p;
        int ans1 = p * (qpow(P, mod - 2)) % mod;
        int ans2 = _p * (qpow(P, mod - 2)) % mod;
        if ((n < m && p > _p) || (n > m && p < _p))
        {
            swap(ans1, ans2);
        }
        // ans1 = ans1 * 3 % mod;
        // ans2 = ans2 * 3 % mod;
        cout << ans1 << ' ' << ans2 << '\n';
    }

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}