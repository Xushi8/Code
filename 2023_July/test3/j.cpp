// 2023/07/25 19:34:27
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;
string a, b;
bool vis[N];

class Node
{
public:

    string num;
    int cnt;
};

Node n1, n2;

int bfs()
{
    queue<Node> que;
    n1.num = a;
    n1.cnt = 0;
    memset(vis, 0, sizeof(vis));
    vis[stoi(a)] = 1;
    que.emplace(n1);
    while (!que.empty())
    {
        n1 = que.front(); que.pop();
        if (n1.num == b)
            return n1.cnt;

        for (int i = 0; i < 4; i++)
        {
            n2 = n1;
            if (n1.num[i] == '9')
                n2.num[i] = '1';
            else
                n2.num[i] = n1.num[i] + 1;
            if (!vis[stoi(n2.num)])
            {
                n2.cnt = n1.cnt + 1;
                vis[stoi(n2.num)] = 1;
                que.emplace(n2);
            }

            n2 = n1;
            if (n1.num[i] == '1')
                n2.num[i] = '9';
            else
                n2.num[i] = n1.num[i] - 1;
            if (!vis[stoi(n2.num)])
            {
                n2.cnt = n1.cnt + 1;
                vis[stoi(n2.num)] = 1;
                que.emplace(n2);
            }
        }

        for (int i = 0; i < 3; i++)
        {
            n2 = n1;
            n2.num[i] = n1.num[i + 1];
            n2.num[i + 1] = n1.num[i];
            if (!vis[stoi(n2.num)])
            {
                n2.cnt = n1.cnt + 1;
                vis[stoi(n2.num)] = 1;
                que.emplace(n2);
            }
        }
    }


    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> a >> b;
        cout << bfs() << '\n';
    }

    cout << endl;
    return 0;
}