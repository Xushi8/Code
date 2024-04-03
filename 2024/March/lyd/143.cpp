// 2024/04/03 15:31:44
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
constexpr int N = 1000005 * 32;

int trie[N][2];
int cnt;

void insert(ll x)
{
	int u = 0;
	for (ll i = 32; i >= 0; i--)
	{
		int bit = (x >> i) & 1;
		int& v = trie[u][bit];
		if (v == 0)
		{
			v = ++cnt;
		}
		u = v;
	}
}

ll find(ll x)
{
	int u = 0;
	ll res = 0;
	for (ll i = 32; i >= 0; i--)
	{
		int bit = (x >> i) & 1;
		if (trie[u][bit ^ 1] != 0)
		{
			res += (1 << i);
			u = trie[u][bit ^ 1];
		}
		else
		{
			u = trie[u][bit];
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll ans = 0;
	while (n--)
	{
		ll x;
		cin >> x;
		insert(x);
		ans = max(ans, find(x));
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}