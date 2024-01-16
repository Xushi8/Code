#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pdd = pair<long double, long double>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pdd> a(n), b(n);
    for (auto& [x, y] : a)
    {
        cin >> x >> y;
        if (y < 0) y += 360.;
    }
    for (auto& [x, y] : b)
    {
        cin >> x >> y;
        if (y < 0) y += 360.;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i].first - b[i].first) > 1e-4)
        {
            cout << "Different" << endl;
            return 0;
        }
    }

    auto check = [&](long double val) -> int
    {
        vector<pdd> tmp(a);
        for (int i = 0; i < n; i++)
        {
            tmp[i].second += val;
            while (tmp[i].second > 360.) tmp[i].second -= 360.;
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; i++)
        {
            if (abs(tmp[i].second - b[i].second) > 1e-6)
            {
                // if (tmp[i].second - b[i].second > 0)
                // {
                //     long double x = tmp[i].second - b[i].second;
                //     if (x < 180)
                //         return 1;
                //     else
                //         return -1;
                // }
                // else
                // {
                //     long double x = b[i].second - tmp[i].second;
                //     if (x < 180)
                //         return -1;
                //     else
                //         return 1;
                // }
            }
        }

        return 0;
    };

    long double l = 0, r = 360.;
    for (int i = 0; i < 35; i++)
    {
        long double mid = (l + r) / 2;
        int ret = check(mid);
        if (ret > 0)
            r = mid;
        else if (ret < 0)
            l = mid;
        else
            break;
    }

    if (check((l + r) / 2) == 0)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Different" << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}