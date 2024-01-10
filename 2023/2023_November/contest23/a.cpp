// 2023/11/15 14:04:18
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

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<>());
        deque<ll> dque;
        dque.emplace_back(a.front());
        size_t i;
        for (i = 1; i + 1 < a.size(); i += 2)
        {
            size_t j = i;
            size_t k = i + 1;
            ll x, y;
            x = dque.front() * a[j] + dque.back() * a[k];
            y = dque.front() * a[k] + dque.back() * a[j];
            if (x > y)
            {
                dque.emplace_front(a[j]);
                dque.emplace_back(a[k]);
            }
            else
            {
                dque.emplace_front(a[k]);
                dque.emplace_back(a[j]);
            }
        }

        if (i < a.size())
        {
            dque.emplace_back(a.back());
        }

        ll ans = 0;
        for (size_t i = 0; i + 1 < a.size(); i++)
        {
            ans += dque[i] * dque[i + 1];
        }
        ans += dque.front() * dque.back();
        cout << ans << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}