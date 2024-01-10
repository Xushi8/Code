// 2023/10/27 10:50:40
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
constexpr int N = 1000005;
map<char, int> in;
vector<char> G[N];
set<int> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int tt;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin >> s;
        char a = s[2], b = s[0], c = s[3];
        G[a].push_back(b);
        G[b].push_back(c);
        in[b]++;
        in[c]++;
        st.emplace(a);
        st.emplace(b);
        st.emplace(c);
    }

    for (auto ch : st)
    {
        if (in.count(ch) == 0)
            in.emplace(ch, 0);
    }

    queue<char> que;
    for (auto [a, b] : in)
    {
        if (b == 0)
            que.push(a);
    }

    vector<char> ans;
    while (!que.empty())
    {
        char u = que.front(); que.pop();
        ans.push_back(u);
        for (char v : G[u])
        {
            if (--in[v] == 0)
            {
                que.push(v);
            }
        }
    }

    if (ans.size() == st.size())
    {
        for (auto ch : ans)
        {
            cout << ch;
        }
    }
    else
    {
        cout << "No Answer\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}