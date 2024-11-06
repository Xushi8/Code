// 2024/11/06 21:40:59
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

void solve()
{
    int n;
    cin >> n;

    auto get = [&]
    {
        vector<pii> a(n);
        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            a[i] = {round(x * 1e4), round(y * 1e4)};
        }
        sort(a.begin(), a.end(),
            [](pii const& lhs, pii const& rhs)
            {
                if (lhs.second != rhs.second)
                    return lhs.second < rhs.second;
                else
                    return lhs.first < rhs.first;
            });

        pii back = a.back();
        std::adjacent_difference(a.begin(), a.end(), a.begin(),
            [](pii const& rhs, pii const& lhs) // 没写错, 这个函数很怪, 第一个它是 output[i] = op(input[i], input[i - 1]) 如 output[i] = (input[i] - input[i - 1])
            { return pii{rhs.first, rhs.second - lhs.second}; });

        a[0].second = a[0].second + 3600000 - back.second;

        auto zuixiaobiaoshi = [&]
        {
            auto func = [&]
            {
                auto tmp = a;
                tmp.insert(tmp.end(), a.begin(), a.end());
                size_t i, j, k;
                for (i = 0, j = 1; i < n && j < n;)
                {
                    for (k = 0; k < n && tmp[i + k] == tmp[j + k]; k++) {}
                    if (tmp[i + k] > tmp[j + k])
                        i += k + 1;
                    else
                        j += k + 1;
                    if (i == j)
                    {
                        j++;
                    }
                }

                return min(i, j);
            };

            size_t k = func();

            std::rotate(a.begin(), a.begin() + k, a.end());
        };

        zuixiaobiaoshi();

        return a;
    };

    auto a = get();
    auto b = get();

    if (n == 1)
    {
        cout << (a[0].first == b[0].first ? "Same" : "Different") << '\n';
    }
    else
    {
        cout << (a == b ? "Same" : "Different") << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
