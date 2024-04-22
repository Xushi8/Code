// 2024/04/22 16:48:22
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

int ans[N];
int n;

bool dfs(int now, int maxx)
{
	if (now == maxx)
	{
		return n == ans[now - 1];
    }
	set<int> st;
	for (int i = now - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			int sum = ans[i] + ans[j];
			if (st.count(sum) == 0 && sum > ans[now - 1] && sum <= n)
			{
				ans[now] = sum;
				st.emplace(sum);
				if (dfs(now + 1, maxx))
					return true;
            }
        }
	}
	return false;
}

void solve()
{
	ans[0] = 1;
    int maxx;
	for (maxx = 1; maxx < 1000; maxx++)
	{
		if (dfs(1, maxx))
			break;
	}

	for (int i = 0; i < maxx; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	while (cin >> n && n)
	{
		solve();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}