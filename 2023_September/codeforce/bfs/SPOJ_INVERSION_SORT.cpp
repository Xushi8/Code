// 2023/09/24 20:15:28
#pragma GCC optimize(3)
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unordered_map<string, int> dis;
    string tmp = "abcdefghij";
    dis[tmp] = 1;
    queue<string> que;
    que.emplace(tmp);
    while (!que.empty())
    {
        string u = que.front(); que.pop();
        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                string v = u;
                reverse(v.begin() + i, v.begin() + j + 1);
                if (dis[v] == 0)
                {
                    dis[v] = dis[u] + 1;
                    que.emplace(v);
                }
            }
        }
    }
    string s, t;
    while (1)
    {
        cin >> s >> t;
        if (s == "*")
            break;
        map<char, char> mp;
        for (int i = 0; i < 10; i++)
        {
            mp[s[i]] = tmp[i];
        }
        for (int i = 0; i < 10; i++)
        {
            t[i] = mp[t[i]];
        }

        cout << dis[t] - 1 << '\n';
    }

    // cerr << dis.size() << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}