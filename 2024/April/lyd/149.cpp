// // 2024/04/14 09:40:40
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <cmath>
// #include <stack>
// #include <array>
// #include <fstream>
// #include <bitset>
// #include <numeric>
// using namespace std;

// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// constexpr int N = 1000005;

// struct A
// {
// 	ll val, deep;
// 	bool is_first;
// 	A() = default;
// 	A(ll val_, ll deep_, bool is_first_) :
// 		val(val_), deep(deep_), is_first(is_first_) {}
// };

// struct cmp
// {
// 	bool operator()(A const& x, A const& y)
// 	{
// 		if (x.val != y.val)
// 			return x.val > y.val;
// 		else
// 			return x.deep < y.deep;
// 	}
// };

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	size_t n, k;
// 	cin >> n >> k;
// 	priority_queue<A, vector<A>, cmp> que;
// 	vector<ll> a(n);
// 	for (auto& x : a)
// 	{
// 		cin >> x;
// 		que.emplace(x, 0, true);
// 	}

// 	multiset<pll> cnts;

// 	while (que.size() >= 2)
// 	{
// 		vector<A> tmp(k);
// 		size_t pre_size = que.size();
// 		for (size_t i = 0; i < min(k, pre_size); i++)
// 		{
// 			tmp[i] = que.top();
// 			que.pop();
// 		}

// 		ll sum = 0;
// 		ll maxn = 0;
// 		for (size_t i = 0; i < min(k, pre_size); i++)
// 		{
// 			sum += tmp[i].val;
// 			maxn = max(maxn, tmp[i].deep);
// 		}
// 		for (size_t i = 0; i < min(k, pre_size); i++)
// 		{
// 			if (tmp[i].is_first)
// 			{
// 				cnts.emplace(maxn, tmp[i].val);
// 			}
// 		}
// 		que.emplace(sum, maxn + 1, false);
// 	}

// 	ll max_deep = que.top().deep;

// 	ll ans = 0;
// 	for (auto x : a)
// 	{
// 		auto it = cnts.lower_bound({-1, x});
// 		ans += (max_deep - it->first) * x;
// 		cnts.erase(it);
// 	}

// 	cout << ans - 1 << endl
// 		 << max_deep - 1 << endl;

// #ifdef LOCAL
// 	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
// #endif
// 	return 0;
// }

// 2024/04/14 10:14:41
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n, k;
	cin >> n >> k;
	priority_queue<pll, vector<pll>, greater<>> que;
	for (size_t i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		que.emplace(x, 0);
	}

	while (k - 1 != 0 && k - 1 != 1 && que.size() % (k - 1) != 1)
	{
		que.emplace(0, 0);
	}

	ll ans = 0;
	while (que.size() >= 2)
	{
		ll sum = 0;
		ll maxn = 0;
		for (size_t i = 0; i < k; i++)
		{
			auto [val, deep] = que.top();
			que.pop();
			sum += val;
			maxn = max(maxn, deep);
		}
		ans += sum;
		que.emplace(sum, maxn + 1);
	}

	cout << ans << endl;
	cout << que.top().second << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}