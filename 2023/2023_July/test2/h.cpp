// 2023/07/21 16:57:01
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
const int N = 3005;

int n;
int arr[N];
vector<int> G[N];
bool used[N];
bool is_true[N];

bool dfs(int u)
{
    if (used[u])
        return is_true[u];

    is_true[u] = 0;
    used[u] = 1;
    for (auto v : G[u])
    {
        if(arr[u] > arr[v])
            if (!dfs(v))
            {
                is_true[u] = 1;
                break;
            }
    }

    return is_true[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int a, b;
    while (cin >> a >> b)
    {
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (dfs(i))
            cout << i + 1 << ' ';
        
        memset(used, 0, sizeof(used));
    }

    cout << endl;
    return 0;
}