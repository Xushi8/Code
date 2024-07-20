// 2024/07/20 12:27:42
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

struct A
{
	string name;
	pii x;
	A() = default;
	A(string name_, pii x_) :
		name(name_), x(x_) {}
};

void solve()
{
	int n;
	cin >> n;
	map<string, int> mp;
	vector<A> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].name >> a[i].x.first >> a[i].x.second;
		mp[a[i].name]++;
	}

	int m;
	cin >> m;
	vector<A> b(m);
	for (int i = 0; i < m; i++)
	{
		cin >> b[i].name >> b[i].x.first >> b[i].x.second;
		mp[b[i].name]++;
	}

	set<string> st;
	for (auto&& [l, r] : mp)
	{
		if (r == 2 && l != "lzr010506")
		{
			st.emplace(l);
		}
	}

	a.erase(remove_if(a.begin(), a.end(), [&](A const& val)
				{
					return st.count(val.name) > 0;
				}),
		a.end());
	b.erase(remove_if(b.begin(), b.end(), [&](A const& val)
				{
					return st.count(val.name) > 0;
				}),
		b.end());

	sort(a.begin(), a.end(), [](A const& l, A const& r)
		{
			if (l.x.first != r.x.first)
				return l.x.first > r.x.first;
			else
				return l.x.second < r.x.second;
		});
	sort(b.begin(), b.end(), [](A const& l, A const& r)
		{
			if (l.x.first != r.x.first)
				return l.x.first > r.x.first;
			else
				return l.x.second < r.x.second;
		});

	int i1 = find_if(a.begin(), a.end(), [](A const& val)
				 {
					 return val.name == "lzr010506";
				 })
			 - a.begin();

	int i2 = find_if(b.begin(), b.end(), [](A const& val)
				 {
					 return val.name == "lzr010506";
				 })
			 - b.begin();
	cout << min(i1, i2) + 1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}