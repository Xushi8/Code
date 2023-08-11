// 2023/08/11 15:00:48
#pragma GCC optimize(2)
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
const int N = 500005;

int trie[N][26], sum[N], fail[N];
int cnt = 0;
int n;
void init()
{
    cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            trie[i][j] = 0;
        }
        sum[i] = 0;
        fail[i] = 0;
    }
}
void add(const string& s)
{
    int root = 0;
    for (char ch : s)
    {
        ch -= 'a';
        if (trie[root][ch] == 0)
            trie[root][ch] = ++cnt;
        root = trie[root][ch];
    }

    sum[root]++;
}

void add_fail()
{
    queue<int> que;
    int root = 0;
    for (int i = 0; i < 26; i++)
    {
        if (trie[root][i] != 0)
        {
            que.emplace(trie[root][i]);
            fail[trie[root][i]] = root;
        }
    }

    while (!que.empty())
    {
        int now = que.front(); que.pop();
        for (int i = 0; i < 26; i++)
        {
            if (trie[now][i] != 0)
            {
                que.emplace(trie[now][i]);
                fail[trie[now][i]] = trie[fail[now]][i];
            }
            else
            {
                trie[now][i] = trie[fail[now]][i];
            }
        }
    }
}

ull check(const string& s)
{
    ull ans = 0;
    int now = 0;
    for (char ch : s)
    {
        ch -= 'a';
        now = trie[now][ch];
        for (int j = now; j != 0 && sum[j] != -1; j = fail[j])
        {
            ans += sum[j];
            sum[j] = -1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            add(s);
        }
        cin >> s;
        add_fail();
        cout << check(s) << '\n';
        init();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}