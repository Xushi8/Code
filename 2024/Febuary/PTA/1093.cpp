// 2024/02/04 18:03:10
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

    string s;
    cin >> s;
    vector<pair<long long, long long>> a(s.size(), {0, 0});
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
            a[i].first = 1;
        else if (s[i] == 'T')
            a[i].second = 1;
    }

    for (size_t i = 1; i < s.size(); i++)
    {
        a[i].first += a[i - 1].first;
    }

    for (size_t i = s.size() - 2; i >= 1; i--)
    {
        a[i].second += a[i + 1].second;
    }

    ll ans = 0;
    constexpr ll MOD = 1e9 + 7;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            ans += a[i].first * a[i].second % MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}