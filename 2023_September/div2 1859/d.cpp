// 2023/09/02 16:08:51
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
        vector<pii> arr(n);
        for (int i = 0; i < n; i++)
        {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            arr[i] = { l, b };
        }

        sort(arr.begin(), arr.end());

        vector<pii> tmp;
        for (int i = 0; i < n; i++)
        {
            if (!tmp.empty() && tmp.back().second >= arr[i].first)
            {
                tmp.back().second = max(tmp.back().second, arr[i].second);
            }
            else
            {
                tmp.emplace_back(arr[i]);
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;

            long long index = upper_bound(tmp.begin(), tmp.end(), make_pair(x, (int)1e9 + 5)) - 1 - tmp.begin();
            if (index >= 0)
            {
                x = max(x, tmp[index].second);
            }
            cout << x << ' ';
        }
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}