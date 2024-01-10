// 2023/09/06 14:17:10
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
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> square(N);
    for (ll i = 1; i <= N; i++)
    {
        square[i - 1] = i * i;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll tmp = arr[i] * arr[i] + arr[j];
            ll a = ans;
            ans += binary_search(square.begin(), square.end(), tmp);
            if (a != ans)
            {
                cout << arr[i] << ' ' << arr[j] << ' ' << tmp << ' ' << (int)sqrt(tmp) << '\n';
            }
        }
    }

    cout << ans << '\n';

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}