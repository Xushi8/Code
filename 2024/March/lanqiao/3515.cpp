// 2024/04/12 17:42:03
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

int pre[N], nex[N];
ll adds[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	priority_queue<pll, vector<pll>, greater<>> que;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = i - 1;
		nex[i] = i + 1;
		ll x;
		cin >> x;
		que.emplace(x, i);
	}

	while (k--)
	{
		auto [val, id] = que.top();
		que.pop();
		if (adds[id] != 0)
		{
			val += adds[id];
			adds[id] = 0;
			que.emplace(val, id);
			k++;
			continue;
		}
		adds[pre[id]] += val;
		adds[nex[id]] += val;
		nex[pre[id]] = nex[id];
		pre[nex[id]] = pre[id];
	}

	vector<pll> ans;
	while (!que.empty())
	{
		auto [val, id] = que.top();
		que.pop();
		if (adds[id] != 0)
		{
			val += adds[id];
			adds[id] = 0;
		}
		ans.emplace_back(id, val);
	}
	sort(ans.begin(), ans.end());
	for (auto [x, y] : ans)
	{
		cout << y << ' ';
	}
	cout << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}