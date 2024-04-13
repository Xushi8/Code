#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// constexpr size_t N = 2e5 + 5;


// void insert(vector<int> const& a) {
//     int u = 0;
//     for (auto x : a) {
//         int& v = trie[u][x];
//         if (v == 0)
//             v = ++tot;
//         u = v;
//     }
// }

// int query(vector<int> const& a) {
//     int u = 0;
//     int res = 0;
//     for (auto x : a) {
//         int& v = trie[u][x];
//         if (v == 0)
//             break;
//         u = v;
//         res++;
//     }
//     return res;
// }

#define N 200005
int tot = 0;
map<int, int> trie[N];
vector<int> GA[N], GB[N];
int va[N], vb[N];
int n, m;

void dfs(int u, int vau, int par) {
    for (int v : GA[u]) {
        if (v == par)
            continue;
        int vav = va[v];
        trie[vau][vav] = ++tot;
        dfs(v, trie[vau][vav], u);
    }
}

int check(int u, int vbu, int par) {
    int res = 0;
    for (int v : GB[u]) {
        if (v == par)
            continue;
        int vbv = vb[v];
        if (trie[vbu][vbv] != 0) {
            res = max(res, check(v, trie[vbu][vbv], u));
        }
    }
    return res + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vb[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        GA[u].emplace_back(v);
        GA[v].emplace_back(u);
    }

    for (int i = 0; i < m - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        GB[u].emplace_back(v);
        GB[v].emplace_back(u);
    }

    if (va[0] != vb[0]) {
        cout << 0 << endl;
        return 0;
    }

    dfs(0, va[0], -1);
    int ans = check(0, vb[0], -1);
    cout << ans << endl;

    return 0;
}