// 2023/08/18 15:42:03
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 10005;

class A
{
public:
    int a, b, c;
};

bool operator == (const A& a, const A& b)
{
    return a.a == b.a && a.b == b.b && a.c == b.c;
}

bool operator < (const A& a, const A& b)
{
    return a.a < b.a && a.b < b.b && a.c < b.c;
}

vector<int> G[N];
int in[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<A> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }

    if (arr[0] < arr[1] || arr[1] < arr[0])
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                G[i].emplace_back(j);
                in[j]++;
            }
        }
    }

    vector<int> ans(n, 0);
    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            que.emplace(i);
        }
    }

    while (!que.empty())
    {
        int u = que.front(); que.pop();
        for (int v : G[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                que.emplace(v);
                ans[v] = ans[u] + 1;
            }
        }
    }

    int val = max(ans[0], ans[1]);
    for (int i = 0; i < n; i++)
    {
        in[i] = 0;
        ans[i] = 0;
    }

    for (int u = 0; u < n; u++)
    {
        for (int v : G[u])
        {
            in[v]++;
        }
    }

    while (!que.empty())
        que.pop();

    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            que.emplace(i);
        }
    }

    ans[0] = ans[1] = val;
    int maxn = 0;
    while (!que.empty())
    {
        int u = que.front(); que.pop();
        maxn = max(maxn, ans[u]);
        for (int v : G[u])
        {
            in[v]--;
            ans[v] = max(ans[v], ans[u] + 1);
            if (in[v] == 0)
                que.emplace(v);
        }
    }

    if (maxn <= 255 && ans[0] == ans[1])
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << '\n';
        }
    }
    else
    {
        cout << -1 << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}