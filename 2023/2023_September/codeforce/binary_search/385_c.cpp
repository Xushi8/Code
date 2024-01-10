// 2023/10/11 13:14:32
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
constexpr int N = 10000005;

bool isnp[N];
vector<int> primes;

void get_primes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isnp[i])
            primes.emplace_back(i);
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

ll mp[N], sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        set<int> st;
        for (int p : primes)
        {
            if (p * p > x)
                break;
            while (x % p == 0)
            {
                x /= p;
                st.insert(p);
            }
        }
        if (x != 1)
            st.insert(x);
        for (int y : st)
            mp[y]++;
    }

    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + mp[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (r >= N)
            r = N - 1;
        if (l >= N)
            l = N - 1;
        cout << sum[r] - sum[l - 1] << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}