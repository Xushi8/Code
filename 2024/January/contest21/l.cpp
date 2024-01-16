// 2024/01/16 15:31:38
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

map<int, int> par;
int find(int x)
{
    if (par.count(x) == 0)
    {
        return par[x] = x;
    }
    else if(par[x] == x)
    {
        return par[x];
    }
    else
    {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        par[x] = y;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<int> a, b;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.emplace_back(x);
    }
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum ^= a[i];
    }
    a.emplace_back(sum);
    sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum ^= b[i];
    }
    b.emplace_back(sum);
    auto c = a, d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    if (c != d)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<pii> eg;
    size_t ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            eg.emplace_back(a[i], b[i]);
            ans++;
        }
    }

    if (ans == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    eg.emplace_back(a[n], b[n]);

    for (auto [x, y] : eg)
    {
        unite(x, y);
    }

    set<int> st;
    for (auto [x, y] : par)
    {
        st.emplace(find(x));
    }

    ans += st.size();
    ans--;
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}