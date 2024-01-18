// 2024/01/16 11:16:24
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

    ll n, A, B;
    cin >> n >> A >> B;
    vector<pii> vec(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i].second;
    }

    constexpr ll len = int(1e9 + 1);
    ll ans = 0;
    {
        ll t = min(A, B);
        ll cnt = t / n;
        ans += 2 * len * cnt;
        A -= cnt * n;
        B -= cnt * n;
    }

    deque<ll> ql, qr;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second == 0)
            ql.emplace_back(vec[i].first);
        else
            qr.emplace_front(len - vec[i].first);
    }

    while (1)
    {
        if (ql.empty())
        {
            if (B == 0)
            {
                ans += qr.back();
                break;
            }
            else
            {
                B--;
                ql.emplace_back(qr.front() + len);
                qr.pop_front();
            }
        }
        else if (qr.empty())
        {
            if (A == 0)
            {
                ans += ql.back();
                break;
            }
            else
            {
                A--;
                qr.emplace_back(ql.front() + len);
                ql.pop_front();
            }
        }
        else
        {
            if (ql.front() < qr.front())
            {
                if (A == 0)
                {
                    ql.pop_front();
                }
                else
                {
                    A--;
                    qr.emplace_back(ql.front() + len);
                    ql.pop_front();
                }
            }
            else
            {
                if (B == 0)
                {
                    qr.pop_front();
                }
                else
                {
                    B--;
                    ql.emplace_back(qr.front() + len);
                    qr.pop_front();
                }
            }
        }
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}