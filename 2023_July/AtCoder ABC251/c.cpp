// 2023/07/05 19:37:25
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    map<string, pii> m;
    // while (tt--)
    // {
    //     string s;
    //     int n;
    //     cin >> s >> n;
    //     m.emplace(s, n, );
    // }
    for (int i = 0; i < tt; i++)
    {
        string s;
        int n;
        cin >> s >> n;
        m.emplace(s, make_pair(n, i + 1));
    }

    int maxn = INT32_MIN;
    int index = -1;
    for (auto x : m)
    {
        if (x.second.first > maxn)
        {
            maxn = x.second.first;
            index = x.second.second;
        }
    }

    cout << index << '\n';

    cout << endl;
    return 0;
}