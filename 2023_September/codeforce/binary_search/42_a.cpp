// 2023/10/03 20:14:43
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    // ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    double v;
    cin >> n >> v;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    double x = b[0] / a[0];
    for (int i = 1; i < n; i++)
    {
        x = min(x, b[i] / a[i]);
    }

    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * x;
    }

    printf("%.8lf\n", min(ans, v));

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}