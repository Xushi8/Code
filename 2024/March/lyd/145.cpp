// 2024/04/03 16:36:32
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

void solve(int n)
{
	if (n == 0)
	{
		cout << 0 << '\n';
		return;
	}
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {y, x};
	}
	sort(a.begin(), a.end());
	priority_queue<int, vector<int>, greater<>> less_que;
	less_que.emplace(a.front().second);
	for (int i = 1; i < n; i++)
	{
		auto [tim, val] = a[i];
		if (tim > less_que.size())
			less_que.emplace(val);
		else
		{
			if (val > less_que.top())
			{
				less_que.pop();
				less_que.emplace(val);
			}
		}
	}

	int ans = 0;
	while (!less_que.empty())
	{
		ans += less_que.top();
		less_que.pop();
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		solve(n);
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}