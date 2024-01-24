// 2024/01/23 20:23:02
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

    int n, a, b;
    cin >> n >> a >> b;
    string s, t;
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        s.append(b, op == 0 ? '.' : '#');
        op = !op;
    }
    op = 0;
    for (int i = 0; i < n; i++)
    {
        t.append(b, op == 0 ? '#' : '.');
        op = !op;
    }
    op = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << (op == 0 ? s : t) << '\n';
        }
        op = !op;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}