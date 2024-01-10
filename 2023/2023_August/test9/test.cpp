// 2023/08/15 14:26:32
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
#include <fstream>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand((unsigned)time(nullptr));
    ofstream ofs("in");
    int n = 100000, m = 300000;
    ofs << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << rand() << '\n';
    }

    for (int i = 0; i < m; i++)
    {
        int a = rand() % n, b = rand() % n;
        if (a == b)
            i--;
        else
            ofs << a << ' ' << b << '\n';
    }

    ofs.close();
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}