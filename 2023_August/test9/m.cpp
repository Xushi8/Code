// 2023/08/15 10:27:02
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

vector<int> G[N];
int in[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            in[i] = 0;
            G[i].clear();
        }

        string s;
        cin.ignore(1024, '\n');
        set<pii> same;
        for (int i = 0; i < m; i++)
        {
            getline(cin, s);
            int a = 0, b = 0;
            bool flag = 1;
            char target;
            for (char ch : s)
            {
                if (isdigit(ch))
                {
                    if (flag)
                    {
                        a = a * 10 + ch - '0';
                    }
                    else
                    {
                        b = b * 10 + ch - '0';
                    }
                }
                else if (isspace(ch))
                {
                    flag = 0;
                }
                else if (ch == '>')
                {
                    target = ch;
                }
                else if (ch == '<')
                {
                    target = ch;
                }
                else if (ch == '=')
                {
                    target = ch;
                }
            }

            if (target == '>')
            {
                in[a]++;
                G[b].emplace_back(a);
            }
            else if (target == '<')
            {
                in[b]++;
                G[a].emplace_back(b);
            }
            else if (target == '=')
            {
                same.emplace(a, b);
                G[a].emplace_back(b);
                G[b].emplace_back(a);
            }
        }

        for (int i = 0; i < n; i++)
        {
            G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
        }

        set<int> st;
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                que.emplace(i);
            }
        }

        vector<int> ans;
        while (!que.empty())
        {
            int u = que.front(); que.pop();
            if (st.count(u) != 0)
                continue;
            
            ans.emplace_back(u);
            st.emplace(u);
            for (int v : G[u])
            {
                in[v]--;
                if (same.count({ u, v }) != 0 || same.count({ v, u }) != 0)
                {
                    if (in[v] != 0)
                    {
                        cout << "CONFLICT\n";
                        goto nex;
                    }
                }

                if (in[v] == 0 && st.count(v) == 0)
                {
                    que.emplace(v);
                }

                if (in[v] < 0)
                {
                    cout << "CONFLICT\n";
                    goto nex;
                }
            }
        }

        if (ans.size() == 1ULL * n)
        {
            cout << "OK\n";
        }
        else
        {
            cout << "UNCERTAIN\n";
        }

    nex:
        ;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}