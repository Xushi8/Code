// 2023/08/10 16:56:51
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
const int N = 3000005;

int trie[N][65], sum[N];
int cnt;

void init()
{
    // memset(trie, 0, sizeof(trie));
    // memset(sum, 0, sizeof(sum));
    for (int i = 0; i <= cnt; i++)
    {
        for (int j = 0; j < 65; j++)
        {
            trie[i][j] = 0;
        }
        sum[i] = 0;
    }
    
    cnt = 0;
}

int getnum(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x - 'A';
    else if (x >= 'a' && x <= 'z')
        return x - 'a' + 26;
    else
        return x - '0' + 52;
}

void insert(const string& s)
{
    int root = 0;
    for (char ch : s)
    {
        int id = getnum(ch);
        if (trie[root][id] == 0)
            trie[root][id] = ++cnt;
        root = trie[root][id];
        sum[root]++;
    }
}

int query(const string& s)
{
    int root = 0;
    for (char ch : s)
    {
        int id = getnum(ch);
        if (trie[root][id] == 0)
            return 0;

        root = trie[root][id];
    }

    return sum[root];
}

void solve()
{
    init();
    string s;
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        cin >> s;
        insert(move(s));
    }
    while (q--)
    {
        cin >> s;
        cout << query(move(s)) << '\n';
    }

    // cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}