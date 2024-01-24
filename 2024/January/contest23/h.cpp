// 2024/01/23 10:45:29
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t = 1;; t++)
    {
        vector<ll> adds;
        ll x, k;
        cin >> x >> k;
        if (x == 0 && k == 0)
        {
            break;
        }
        cout << "Case #" << t << ": ";
        // cerr << '\n';

        // for (ll i = 1; i <= k; i++)
        // {
        //     ll mod = x % i;
        //     if (mod != 0)
        //         x += (i - mod);
        //     cerr << i << ' ' << x << ' ' << i - mod << '\n';
        // }

        for (ll i = 1; i <= k; i++)
        {
            ll mod = x % i;
            if (mod != 0)
            {
                x += (i - mod);
                adds.emplace_back(i - mod);
            }

            if (i % 100 == 0)
            {
                bool flag = 1;
                for (ll j = adds.size() - 50; j < adds.size(); j++)
                {
                    if (adds[j] != adds[j - 1])
                    {
                        flag = 0;
                        break;
                    }
                }

                if (flag)
                {
                    x += (k - i) * adds.back();
                    break;
                }
            }
        }
        cout << x << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}