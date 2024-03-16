#ifdef DEBUG
// 2024/03/16 13:17:55
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
#include <span>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int n, m;
vector<int> tmp;
int ans;
vector<int> all_ans;

int lcm(span<const int> s)
{
	int res = s.front();
	for (size_t i = 1; i < s.size(); i++)
	{
		res = lcm(res, s[i]);
	}
	return res;
}

void dfs(int deep)
{
	if (deep == m)
	{
		if (lcm(tmp) == n)
		{
			ans++;
			for (auto x : tmp)
			{
				cerr << x << ' ';
			}
			cerr << '\n';
		}

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		tmp.emplace_back(i);
		dfs(deep + 1);
		tmp.pop_back();
	}
}

void solve()
{
	cin >> n >> m;
	ans = 0;
	dfs(0);
	all_ans.emplace_back(ans);
	cerr << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

	for (auto x : all_ans)
	{
		cerr << x << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}

#else
// 2024/03/16 15:25:33
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
constexpr int MOD = 998244353;
constexpr int N = 100005;
bool isnp[N];
vector<int> primes;
void get_primes()
{
	for (int i = 2; i < N; i++)
	{
		if (!isnp[i])
			primes.emplace_back(i);
		for (auto p : primes)
		{
			if (p * i >= N)
				break;
			isnp[p * i] = 1;
			if (i % p == 0)
				break;
		}
	}
}

ll qmi(ll a, ll n)
{
	ll b = 1;
	while (n)
	{
		if (n & 1)
			b = b * a % MOD;
		a = a * a % MOD;
		n /= 2;
	}
	return b;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	if (n == 1)
	{
		cout << 1 << '\n';
		return;
	}
	map<int, size_t> yinzi;
	for (auto p : primes)
	{
		if (p * p > n)
			break;
		while (n % p == 0)
		{
			yinzi[p]++;
			n /= p;
		}
	}
	if (n != 1)
	{
		yinzi[n]++;
	}

	size_t num = 0;
	for (auto [x, y] : yinzi)
	{
		num += y;
	}
	num = (num - 1) * yinzi.size() + 1;
	cerr << yinzi.size() << ' ' << num << ' ';
	cout << qmi(num + 1, m) - qmi(yinzi.size() + num + 1, num - 1) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	get_primes();

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}
	NULL;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}

#endif
