// 2024/04/01 14:11:45
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

int sum[N], ans[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	stack<int> L, R;
	ans[0] = -1e9;
	while (q--)
	{
		char ch;
		cin >> ch;
		if (ch == 'I')
		{
			int x;
			cin >> x;
			L.emplace(x);
			size_t l = L.size();
			sum[l] = sum[l - 1] + L.top();
			ans[l] = max(ans[l - 1], sum[l]);
		}
		else if (ch == 'D')
		{
			if (!L.empty())
				L.pop();
		}
		else if (ch == 'L')
		{
			if (!L.empty())
			{
				R.emplace(L.top());
				L.pop();
			}
		}
		else if (ch == 'R')
		{
			if (!R.empty())
			{
				L.emplace(R.top());
				R.pop();
				size_t l = L.size();
				sum[l] = sum[l - 1] + L.top();;
				ans[l] = max(ans[l - 1], sum[l]);
			}
		}
		else
		{
			int x;
			cin >> x;
			cout << ans[x] << '\n';
		}
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}