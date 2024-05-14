// 2024/05/14 14:08:56
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

using i64 = int64_t;
using pii = pair<int, int>;
constexpr int N = 1000005;

bool dfs(int len, int cnt, int now, int now_cnt, int last, vector<int> const& sticks, vector<bool> & vis)
{
	if (now_cnt == cnt)
	{
		return true;
	}
	if (now == len)
	{
		return dfs(len, cnt, 0, now_cnt + 1, 0, sticks, vis);
    }

	int last_fail = -1;
	for (int i = last; i < sticks.size(); i++)
	{
		if (!vis[i] && now + sticks[i] <= len && sticks[i] != last_fail)
		{
			vis[i] = 1;
			auto ret = dfs(len, cnt, now + sticks[i], now_cnt, last + 1, sticks, vis);
			if (ret)
				return true;

			// 失败
			last_fail = sticks[i];
			vis[i] = 0;
			if (now == 0 || now + sticks[i] == len)
				return false;
        }
	}

	return false;
}

void solve(int n)
{
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
        sum += a[i];
	}
	// int sum = reduce(a.begin(), a.end());
	int maxx = *max_element(a.begin(), a.end());
	sort(a.begin(), a.end(), greater<>());
	for (int ans = maxx; ans <= sum; ans++)
	{
		if (sum % ans != 0)
			continue;
		vector<bool> vis(n);
		if (dfs(ans, sum / ans, 0, 0, 0, a, vis))
		{
			cout << ans << '\n';
			break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	while (cin >> n && n)
	{
		solve(n);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}