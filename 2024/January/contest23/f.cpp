// 2024/01/23 10:08:39
#include <cstddef>
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
constexpr int N = 200005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t n, m, p;
    cin >> n >> m >> p;
    vector<bitset<N>> a(m);
    vector<string> s(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            a[j][i] = s[i][j] - '0';
        }
    }

    size_t tar = (n + 1) / 2;
    vector<bool> can_use(m, 1);
    for (size_t i = 0; i < m; i++)
    {
        if (a[m].count() < tar)
        {
            can_use[i] = 0;
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}