// 2023/05/25 17:34:30
#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long)1e9 + 7;

vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    vector<vector<int>> c(a.size(), vector<int>(a[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            for (int k = 0; k < b.size(); k++)
            {
                c[i][j] += a[i][k] % MOD * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

vector<vector<int>> pow(vector<vector<int>> a, unsigned long long n)
{
    vector<vector<int>> res(a.size(), vector<int>(a[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
        res[i][i] = 1;

    while (n)
    {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned long long n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    arr = pow(arr, k);
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += arr[i][j] % MOD;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    cout << flush;
    system("pause");
    return 0;
}