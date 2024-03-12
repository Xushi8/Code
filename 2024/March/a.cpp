// 2024/03/11 13:24:19
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using ll = long long;
constexpr size_t N = 1e7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> ans;
	ans.reserve(N);
	queue<ll> que;
	que.emplace(1);
	while (1)
	{
		auto x = que.front();
		que.pop();
		if (ans.size() >= N)
			break;
		ans.emplace_back(x);
		que.emplace(x * 2);
		que.emplace(x * 3);
		que.emplace(x * 5);
	}

	sort(ans.begin(), ans.end());

	int tt;
	cin >> tt;
	while (tt--)
	{
		size_t x;
		cin >> x;
		x--;
		cout << ans[x] << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}
