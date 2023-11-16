// 2023/11/15 11:19:56
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
int n, m, q;

bool solve()
{
    vector<int> a(n);
    for (int& x : a)
    {
        cin >> x;
    }

    stack<int> stk;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        while (stk.size() < m && now < a[i])
        {
            stk.emplace(now + 1);
            now++;
        }

        if (now < a[i])
        {
            return false;
        }
        else if (stk.top() != a[i])
        {
            return false;
        }
        else
        {
            stk.pop();
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> q;
    while (q--)
    {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}