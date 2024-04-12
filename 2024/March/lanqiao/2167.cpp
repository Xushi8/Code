// 2024/04/12 19:57:07
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
constexpr int N = 28;

bool vis[N];
int own[N];

ll ans = 0;

void dfs(int deep)
{
	if (deep == N)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (own[i] == i)
			{
				cnt++;
			}
		}

		if (cnt == N / 2)
		{
			ans++;
		}
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			own[deep] = i;
			dfs(deep + 1);
			vis[i] = 0;
        }
    }
}

ll A(ll n)
{
	ll res = 1;
	for (ll i = 1; i <= n; i++)
	{
		res *= i;
	}
	return res;
}

ll C(ll m, ll n)
{
	ll res = 1;
	for (ll i = 1; i <= n; i++)
	{
		res *= m--;
	}
	return res / A(n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// dfs(0);
	
	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}