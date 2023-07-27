// 2023/07/27 20:09:25
#pragma GCC optimize(2)
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

bool isnp[N];
vector<int> primes;
void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
        {
            primes.emplace_back(i);
        }
        for (int p : primes)
        {
            if (p * i >= N)
                break;

            isnp[p * i] = 1;

            if (i % p == 0)
                break;
        }
    }
}

ll pow(ll a, int n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * a;
        a *= a;
        n /= 2;
    }

    return res;
}

vector<ll> arr;

void func()
{
    for (ll i = 1; i <= 1000000000000LL; i *= 2)
    {
        arr.emplace_back(i);
    }

    for (ll i = 1; i * i <= 1000000000000LL; i++)
    {
        arr.emplace_back(i * i);
        if (i * i * 2 <= 1000000000000LL)
        {
            arr.emplace_back(i * i * 2);
        }
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
}


// 2 4 8 9 16 18 25 32 36 49 64 72 81 98
// 2 的幂次， 平方数  18 32 72 98    平方数 * 2
ll solve(ll n)
{
    ll res = n;
    ll cnt = upper_bound(arr.begin(), arr.end(), n) - arr.begin();
    res -= cnt;

    return res;

    // if (n == 1)
    //     return 1;

    // vector<pii> arr;
    // for (int p : primes)
    // {
    //     if (p * p > n)
    //         break;

    //     if (n % p == 0)
    //     {
    //         int cnt = 0;
    //         while (n % p == 0)
    //         {
    //             n /= p;
    //             cnt++;
    //         }

    //         arr.emplace_back(p, cnt);
    //     }
    // }

    // if (arr.empty() || n > 1)
    //     arr.emplace_back(n, 1);

    // ll res = 1;
    // for (auto [x, y] : arr)
    // {
    //     res *= (::pow(x, y + 1) - 1);
    // }
    // for (auto [x, y] : arr)
    // {
    //     res /= (x - 1);
    // }
    // return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();
    int tt = 1;
    cin >> tt;
    int Case = 1;
    func();
    while (tt--)
    {
        ll n;
        cin >> n;
        cout << "Case " << Case++ << ": " << solve(n) << '\n';

        // for (int i = 1; i < 100; i++)
        // {
        //     cout << i << ' ' << solve(i) << '\n';
        // }
    }

    cout << flush;
    return 0;
}


/*
1 1
2 3
3 4
4 7
5 6
6 12
7 8
8 15
9 13
10 18
11 12
12 28
13 14
14 24
15 24
16 31
17 18
18 39
19 20
20 42
21 32
22 36
23 24
24 60
25 31
26 42
27 40
28 56
29 30
30 72
31 32
32 63
33 48
34 54
35 48
36 91
37 38
38 60
39 56
40 90
41 42
42 96
43 44
44 84
45 78
46 72
47 48
48 124
49 57
50 93
51 72
52 98
53 54
54 120
55 72
56 120
57 80
58 90
59 60
60 168
61 62
62 96
63 104
64 127
65 84
66 144
67 68
68 126
69 96
70 144
71 72
72 195
73 74
74 114
75 124
76 140
77 96
78 168
79 80
80 186
81 121
82 126
83 84
84 224
85 108
86 132
87 120
88 180
89 90
90 234
91 112
92 168
93 128
94 144
95 120
96 252
97 98
98 171
99 156
*/