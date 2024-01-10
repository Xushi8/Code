// 2023/11/05 17:54:24
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b;
        b.push_back(0);
        vector<bool> used(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int best = -1;
            int id = -1;
            for (int j = 0; j < n; j++)
            {
                if (!used[j] && best < __gcd(b.back(), a[j]))
                {
                    best = __gcd(b.back(), a[j]);
                    id = j;
                }
            }

            used[id] = 1;
            b.push_back(best);
            ans.push_back(a[id]);
        }
        for (int x : ans)
            cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}