// 2024/01/18 09:10:27
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <iterator>
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

    int n, q;
    cin >> n >> q;
    vector<set<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i].emplace(x);
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        // a[y].emplace(a[y].end(), make_move_iterator(a[x].begin()), make_move_iterator(a[x].end()));
        // a[y].emplace(a[y].end(), a[x].begin(), a[x].end());
        // for (auto it = a[x].begin(); it != a[x].end(); it++)
        // {
        //     a[y].emplace(*it);
        // }
        if (a[y].size() < a[x].size())
        {
            for (auto it = a[y].begin(); it != a[y].end(); it++)
            {
                a[x].emplace(*it);
            }
            a[y] = move(a[x]);
        }
        else
        {
            for (auto it = a[x].begin(); it != a[x].end(); it++)
            {
                a[y].emplace(*it);
            }
        }

        a[x].clear();
        cout << a[y].size() << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}