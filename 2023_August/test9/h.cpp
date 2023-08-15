// 2023/08/15 16:51:33
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int par[N];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    par[x] = y;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

class Edge
{
public:
    Edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }

    int u, v, w;
};

vector<Edge> arr;
vector<int> used;

int n, m;

int kruskal(int x)
{
    int res = 0;
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        if (i == x)
            continue;

        if (!same(arr[i].u, arr[i].v))
        {
            unite(arr[i].u, arr[i].v);
            res += arr[i].w;
            num++;
            if (x == -1)
                used.push_back(i);
        }

        if (num == n - 1)
            break;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (par[i] == i)
            cnt++;
    }

    if (cnt > 1)
        return -1;
    else
        return res;
}

bool cmp(const Edge& a, const Edge& b)
{
    return a.w < b.w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> m;
        init(n);
        arr.clear();
        used.clear();

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            arr.push_back({ u, v, w });
        }
        sort(arr.begin(), arr.end(), cmp);

        int ans = kruskal(-1);

        bool flag = 1;
        for (int i = 0; i < used.size(); i++)
        {
            init(n);
            if (ans == kruskal(used[i]))
            {
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << ans << '\n';
        else
            cout << "Not Unique!\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}