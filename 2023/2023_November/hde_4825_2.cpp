// 2023/11/25 20:43:53
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
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 500005 * 35;

int trie[N][2];
int cnt;
ll arr[N];

void init()
{
    for (int i = 0; i <= cnt; i++)
    {
        trie[i][0] = trie[i][1] = 0;
        // arr[i] = 0;
    }

    // memset(trie, 0, sizeof(trie));
    // memset(arr, 0, sizeof(arr));

    cnt = 0;
}

void insert(ll n)
{
    int root = 0;
    for (int i = 33; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        int& tmp = trie[root][bit];
        if (tmp == 0)
        {
            tmp = ++cnt;
        }

        root = tmp;
    }

    arr[root] = n;
}

ll find(ll n)
{
    int root = 0;
    for (int i = 33; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        root = trie[root][bit ^ 1] != 0 ? trie[root][bit ^ 1] : trie[root][bit];
    }

    return arr[root];
}

void solve()
{
    init();
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        ll x;
        cin >> x;
        insert(x);
    }

    while (m--)
    {
        ll x;
        cin >> x;
        cout << find(x) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
	{
		cout << "Case #" << i << ":\n";
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}