#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
const int M = 1ll << 30;
int n, m, k;
const int N = 1e6 + 10;
int A[N];
int B[N];
int C[N];
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> B[i];
    }
    C[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        C[i] = (C[i - 1] ^ B[i - 1]);
    }

    int S[35];
    for (int i = 0; i < 35; i++)
    {
        S[i] = 8;
    }
    for (int i = 1; i <= n; i++)
    {
        if (C[i] >= C[i - 1])
        {
            int cht = C[i] ^ C[i - 1];
            int t = 0;
            while (cht)
            {
                cht >>= 1;
                t++;
            }
            if (S[t] != 8 && S[t] == 1)
            {
                cout << "-1" << endl;
                return;
            }
            S[t] = 0;
        }
        else if (C[i] < C[i - 1])
        {
            int cht = C[i] ^ C[i - 1];
            int t = 0;
            while (cht)
            {
                cht >>= 1;
                t++;
            }
            if (S[t] != 8 && S[t] == 0)
            {
                cout << "-1" << endl;
                return;
            }
            S[t] = 1;
        }
    }
    int kk = k - 1;
    int ii = 1;
    while (kk)
    {
        while (S[ii] != 8)
        {
            ii++;
        }
        if ((kk & 1) == 1)
        {
            S[ii] = 1;
        }
        else
        {
            S[ii] = 0;
        }

        kk >>= 1;
    }
    reverse(S + 1, S + 31);
    /*
    for(int i=1;i<31;i++)
    {
        cout<<S[i];
    }
    cout<<endl;
    */
    int cnt = 0;
    int crt = 1;
    for (int i = 1; i < 31; i++)
    {
        if (S[i] == 8)
        {
            continue;
        }
        cnt += (S[i]) * (crt);
        cnt <<= 1;
        crt <<= 1;
        // cout<<cnt<<" "<<crt<<endl;
    }
    cnt >>= 1;
    // cout<<cnt<<endl;
    if (cnt > M)
    {
        cout << "-1" << endl;
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int aa = C[i] ^ cnt;
        if (aa > M)
        {
            cout << "-1" << endl;
            return;
        }
        ans.push_back(aa);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
signed main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
