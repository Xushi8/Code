// 2024/01/26 11:27:03
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
constexpr int N = 1000005 * 35;

int trie[N][2];
int cnt[N];
int now;

void insert(int x)
{
    int u = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        int& v = trie[u][bit];
        if (v == 0)
        {
            v = ++now;
        }
        u = v;
        cnt[u]++;
    }
}

int n, k;
ll get_cnt(int x)
{
    int u = 0;
    ll sum = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        if ((k >> i) & 1)
        {
            u = trie[u][!bit];
            if (u == 0)
                return sum;
        }
        else
        {
            sum += cnt[trie[u][!bit]];
            u = trie[u][bit];
            if (u == 0)
                return sum;
        }
    }

    return sum + cnt[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

cin >> n >> k;
    vector<int> sum(n);
    for (int i = 0; i < n; i++)
        cin >> sum[i];
    for (int i = 1; i < n; i++)
    {
        sum[i] ^= sum[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum[i] >= k)
            ans++;
    }

    for (int i = 0; i < n; i++)
    {
        ans += get_cnt(sum[i]);
        insert(sum[i]);
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}