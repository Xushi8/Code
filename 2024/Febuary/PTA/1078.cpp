// 2024/02/04 14:33:19
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    get_primes();
    int n, t;
    cin >> n >> t;
    swap(n, t);
    t = *lower_bound(primes.begin(), primes.end(), t);
    vector<bool> vis(t, 0);

    auto insert = [&](int val) -> void
    {
        for (int i = 0; i < t; i++)
        {
            int j = (val + i * i) % t;
            if (!vis[j])
            {
                vis[j] = 1;
                cout << j;
                return;
            }
        }
        cout << '-';
    };

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            cout << ' ';
        int x;
        cin >> x;
        insert(x);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}