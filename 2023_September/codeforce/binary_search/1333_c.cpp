<<<<<<< HEAD
// 2023/10/10 12:33:20
=======
// 2023/10/08 10:46:40
>>>>>>> 6535fab98e25c507a3085df5d2bb3159a66712e3
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
    
    int n;
    cin >> n;
    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum[i + 1] = sum[i] + x;
    }

    ll ans = 0;
    set<ll> st;
    st.emplace(0);
    int l = 0, r = 0;
    while (l < n)
    {
        while (r < n && st.count(sum[r + 1]) == 0)
        {
            st.emplace(sum[++r]);
        }
        ans += r - l;
        st.erase(sum[l++]);
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}