#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int N = 3e3 + 10;
bool A[N][N];
int cnt[N];
int ccc[N];
bool vis1[N];
bool vis2[N];
int ans;
using pii = pair<int, int>;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            cnt[i] += A[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ccc[i] += A[j][i];
        }
    }

    vector<pii> S(n);
    for (int i = 1; i <= n; i++)
    {
        S[i - 1] = {cnt[i], i};
    }
    sort(S.begin(), S.end());

    for (size_t i = 0; i < S.size(); i++)
    {
        if (!vis1[i])
        {
            int tmp = n + 1;
            int k = -1;
            for (int j = 1; j <= n; j++)
            {
                if (A[S[i].second][j] && !vis2[j])
                {
                    if (tmp > ccc[j])
                    {
                        tmp = ccc[j];
                        k = j;
                    }
                }
            }
            if (k != -1)
            {
                vis1[i] = 1;
                vis2[k] = 1;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}
