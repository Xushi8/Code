// 2024/01/23 20:37:32
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

    int n, q;
    cin >> n >> q;
    map<int, int> m1, m2;
    for (int i = 1; i <= n; i++)
    {
        m1[i] = i;
        m2[i] = i;
    }

    while (q--)
    {
        int x;
        cin >> x;
        int index = m2[x];
        auto it = m1.find(index);
        auto it1 = it;
        it1++;
        if (it1 == m1.end())
        {
            it1 = it;
            it1--;
        }
        swap(it->second, it1->second);
        m2[it->second] = it->first;
        m2[it1->second] = it1->first;
    }

    for (auto [x, y] : m1)
    {
        cout << y << ' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}