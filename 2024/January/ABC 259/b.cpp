// 2024/01/13 21:29:02
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
constexpr double pi = 3.141592657832528;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a, b, d;
    cin >> a >> b >> d;
    double len = sqrt(a * a + b * b);
    double deg = atan2(b, a);
    deg += d * pi / 180;
    cout << setprecision(6) << fixed;
    cout << len * cos(deg) << ' ' << len * sin(deg) << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}