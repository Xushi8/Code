// 2024/07/23 13:56:10
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

i64 change(i64 x, i64 h)
{
	return abs(x - h);
}

void solve()
{
	int n;
	i64 D;
	cin >> n >> D;
	vector<i64> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	set<i64> st;
	for (auto x : h)
	{
		st.emplace(D % x);
		st.emplace(x - D % x);
	}

	i64 ans = 9e18;
	for (auto x : h)
	{
		for (auto y : st)
		{
			ans = min({ans, x % y, x - x % y});
        }
	}

	for (auto x : h)
		cout << x << ' ';
	cout << '\n';
	for (auto y : st)
		cout << y << ' ';
	cout << '\n';
	
	cout << ans << '\n';
}

void biao()
{
	int n;
	i64 D;
	cin >> n >> D;
	vector<i64> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		D %= h[i];
	}
	set<i64> st;
	st.emplace(D);
	auto dfs = [&](auto&& self, i64 u) -> void
	{
		for (auto val : h)
		{
			i64 v = change(u, val);
			if (!st.count(v))
			{
				st.emplace(v);
				cout << u << ' ' << val << ' ' << v << ' ' << st.size()<< '\n';
				self(self, v);
			}
		}
	};

	dfs(dfs, D);
	for (auto x : st)
	{
		cout << x << ' ';
	}
	cout << '\n';
}

void test()
{
	int n;
	i64 D;
	cin >> n >> D;
	vector<i64> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		D %= h[i];
	}
	i64 ans = D;
	for (auto val : h)
	{
		ans = min(ans, change(val, D));
	}
	cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
		// solve();
		// biao();
		test();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}