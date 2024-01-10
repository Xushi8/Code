// 2023/08/07 17:23:45
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
    
    ofstream ofs("in");
    int n = 1;
    ofs << n << '\n';
    for (int i = 0; i < n; i++)
        ofs << i << ' ';
    ofs.close();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}