// 2024/01/12 14:46:39
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> a(n + 1);
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    stack<int> stk;

    for (int i = 1; i <= n; i++)
    {
        while (!stk.empty() && a[stk.top()].first <= a[i].first)
        {
            stk.pop();
        }

        L[i] = stk.empty() ? 0 : stk.top();
        stk.emplace(i);
    }

    stack<int>().swap(stk);

    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && a[stk.top()].first <= a[i].first)
        {
            stk.pop();
        }

        R[i] = stk.empty() ? n + 1 : stk.top();
        stk.emplace(i);
    }

    vector<int> val(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        val[L[i]] += a[i].second;
        val[R[i]] += a[i].second;
    }

    cout << *max_element(val.begin() + 1, val.begin() + n + 1) << endl;

#ifdef LOCAL
    cerr
        << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}