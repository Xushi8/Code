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
const int N = 10005;

vector<int> G[N];
int in[N];


int par[N], rk[N];
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (rk[x] < rk[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rk[x] == rk[y])
        {
            rk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        for (int i = 0; i < n; i++)
        {
            in[i] = 0;
            G[i].clear();
        }

        string s;
        cin.ignore(1024, '\n');
        vector<pii> tmp;
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
                // in[find(a)]++;
                // G[find(b)].emplace_back(find(a));
                tmp.emplace_back(b, a);
            }
            else if (target == '<')
            {
                // in[find(b)]++;
                // G[find(a)].emplace_back(find(b));
                tmp.emplace_back(a, b);
            }
            else if (target == '=')
            {
                unite(a, b);
            }
        }

        for (auto [u, v] : tmp)
        {
            G[find(u)].emplace_back(find(v));
            in[find(v)]++;
        }

        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (in[find(i)] == 0 && i == find(i))
            {
                que.emplace(find(i));
            }
        }

        vector<int> ans;
        bool conflict = 0;
        while (!que.empty())
        {
            if (que.size() >= 2)
            {
                conflict = 1;
            }
            
            int u = que.front(); que.pop();
            ans.emplace_back(find(u));
            for (int v : G[find(u)])
            {
                in[find(v)]--;
                if (in[find(v)] == 0)
                {
                    que.emplace(find(v));
                }
            }
        }

        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.emplace(find(i));
        }
        
        if (ans.size() != st.size())
        {
            cout << "CONFLICT\n";
        }
        else
        {
            if (conflict)
            {
                cout << "UNCERTAIN\n";
            }
            else
            {
                cout << "OK\n";
            }
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}