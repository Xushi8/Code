#include <bits/stdc++.h>
using namespace std;

// #define inf 0x3f3f3f3f

// int arr[1000005], dp[1000005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         dp[i] = inf;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         *lower_bound(dp, dp + n, arr[i]) = arr[i];
//     }
//     cout << lower_bound(dp, dp + n, inf) - dp;
    

//     cout << flush;
//     system("pause");
//     return 0;
// }

#define maxn 10005
int par[maxn], rank[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        ::rank[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x)
    {
        return x;
    }

    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (::rank[x] < ::rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (::rank[x] == ::rank[y]) ::rank[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    init(n);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            unite(b, c);
        }
        else
        {
            if (same(b, c))
            {
                puts("Y");
            }
            else
            {
                puts("N");
            }
        }
    }

    
    cout << flush;
    system("pause");
    return 0;
}