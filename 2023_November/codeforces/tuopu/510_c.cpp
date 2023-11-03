// 2023/11/03 09:26:26
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
vector<char> G[300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    map<char, int> in;
    set<char> st;
    for (int i = 0; i < n - 1; i++)
    {
        const string& a = s[i];
        const string& b = s[i + 1];
        for (size_t j = 0; j < min(a.size(), b.size()); j++)
        {
            if (a[j] != b[j])
            {
                G[a[j]].push_back(b[j]);
                st.emplace(a[j]);
                st.emplace(b[j]);
                in[b[j]]++;
                break;
            }

            if (j == min(a.size(), b.size()) - 1 && a.size() >= b.size())
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    queue<char> que;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (st.count(i) == 1 && in[i] == 0)
        {
            que.emplace(i);
        }
    }
    vector<char> ans;

    while (!que.empty())
    {
        char u = que.front();
        que.pop();
        ans.emplace_back(u);
        for (char v : G[u])
        {
            if (--in[v] == 0)
            {
                que.emplace(v);
            }
        }
    }

    if (ans.size() != st.size())
    {
        cout << "Impossible\n";
    }
    else
    {
        for (char ch : ans)
        {
            cout << ch;
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            if (st.count(i) == 0)
            {
                cout << i;
            }
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}