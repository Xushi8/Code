// 2023/08/10 19:40:19
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

int trie[N][26], sum[N];
int cnt = 0;
vector<string> arr;

void insert(const string& s)
{
    int root = 0;
    for (char ch : s)
    {
        int id = ch - 'a';
        if (trie[root][id] == 0)
            trie[root][id] = ++cnt;
        root = trie[root][id];
        sum[root]++;
    }
}

int query(const string& s)
{
    int root = 0;
    int res = 0;
    for (char ch : s)
    {
        int id = ch - 'a';
        if (sum[root] == 1)
        {
            return res;
        }
        res++;
        root = trie[root][id];
    }

    return (int)s.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    while (cin >> s)
    {
        insert(s);
        arr.emplace_back(move(s));
    }

    for (int i = 0; i < (int)arr.size(); i++)
    {
        int len = query(arr[i]);
        cout << arr[i] << ' ' << arr[i].substr(0, len) << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}