// 2024/01/18 10:46:40
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
vector<int> ans;
vector<int> a;
int n, k;

void dfs(int now, int sum, int id)
{
    if (now == 0)
    {
        ans.emplace_back(sum);
        return;
    }
    if (id == a.size() - 1)
    {
        ans.emplace_back(sum + now * a[id]);
        return;
    }
    for (int i = now; i >= 0; i--)
    {
        dfs(now - i, sum + a[id] * i, id + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    dfs(k, 0, 0);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (auto x : ans)
    {
        cout << x << ' ';
    }

#ifdef LOCAL
    cerr
        << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}