// 2024/04/02 08:52:05
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
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

ll a[N], L[N], R[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		stack<ll> stk;

		for (int i = 1; i <= n; i++)
		{
			while (!stk.empty() && a[stk.top()] >= a[i])
				stk.pop();

			L[i] = stk.empty() ? 0 : stk.top();
            stk.emplace(i);
		}

		stack<ll>().swap(stk);

		for (int i = n; i >= 1; i--)
		{
			while (!stk.empty() && a[stk.top()] >= a[i])
				stk.pop();

			R[i] = stk.empty() ? n + 1 : stk.top();
            stk.emplace(i);
		}

		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, a[i] * (R[i] - L[i] - 1));
		}
		cout << ans << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}