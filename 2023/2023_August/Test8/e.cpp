// 2023/08/12 10:12:21
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
const int N = 6000;

int trie[N][26], vis[N];
int cnt = 0;

void add(const string& s)
{
    int root = 0;
    for (char ch : s)
    {
        int id = ch - 'A';
        if (trie[root][id] == 0)
            trie[root][id] = ++cnt;
        root = trie[root][id];
    }

    vis[root]++;
}

struct A
{
    int cnt, id;
};

void query()
{
    int root = 0;
    string s;
    queue<A> que;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}