// 2023/10/05 15:58:43
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    n = int(arr.size());
    cout << setprecision(6) << fixed;

    auto check = [&](double val) -> tuple<double, double, double>
        {
            double a = 0.0, b = 0.0, c = 0.0, lst;
            a = arr[0] + val;
            lst = a + val;
            int i;
            for (i = 1; i < n; i++)
            {
                if (arr[i] > lst)
                {
                    break;
                }
            }
            if (i == n)
                return { a, b, c };
            
            b = arr[i] + val;
            lst = b + val;
            for (; i < n; i++)
            {
                if (arr[i] > lst)
                    break;
            }
            if (i == n)
                return { a, b, c };

            c = arr[i] + val;
            lst = c + val;
            for (; i < n; i++)
            {
                if (arr[i] > lst)
                    return { -1.0, 0.0, 0.0 };
            }
            return { a, b, c };
        };

    double l = 0.0, r = 2e9;
    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2.0;
        auto [a, b, c] = check(mid);
        if (a >= 0.0)
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;
    auto [a, b, c] = check(r);
    cout << a << ' ' << b << ' ' << c << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}