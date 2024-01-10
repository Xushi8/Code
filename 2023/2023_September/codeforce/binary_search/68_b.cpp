// 2023/10/03 17:44:43
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
// #include <format>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double decreases = 1.0 - k / 100.0;

    auto check = [&](double x) -> bool
        {
            double adds = 0.0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > x)
                {
                    adds += (arr[i] - x) * decreases;
                }
                else
                {
                    adds -= (x - arr[i]);
                }
            }

            return adds >= 0.0;
        };

    double l = *min_element(arr.begin(), arr.end());
    double r = *max_element(arr.begin(), arr.end());

    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    // cout << format("{:.8f}\n", l);
    printf("%.8lf", l);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}