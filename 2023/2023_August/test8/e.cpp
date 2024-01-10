// 2023/08/10 20:01:07
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
const int N = 1000005;
int sum[N], trie[N][2];

vector<pii> G[N];
int ans, cnt;
void insert(int num)
{
    int root = 0;
    for (int i = 30; i >= 0; i--)
    {
        int p = (num >> i) & 1;
        if(trie[root][p] == 0)
        {
            trie[root][p] = ++cnt;
        }
        root = trie[root][p];
    }
}

void check(int num)
{
    int tmp = 0;
    int root = 0;
    for (int i = 30; i >= 0; i--)
    {
        int p = (num >> i) & 1;
        if (trie[root][p ^ 1] != 0)
        {
            root = trie[root][p ^ 1];
            tmp += 1 << i;
        }
        else
        {
            root = trie[root][p];
        }
    }
    ans = max(ans, tmp);
}

void dfs(int u, int from)
{
    insert(sum[u]);
    check(sum[u]);
    for (auto [v, w] : G[u])
    {
        if (v == from)
            continue;

        sum[v] = sum[u] ^ w;
        dfs(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    dfs(1, 0);
    cout << ans << '\n';


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}