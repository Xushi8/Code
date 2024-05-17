// 2024/05/17 21:30:21
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
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		set<string> st(a.begin(), a.end());

		for (auto s : a)
		{
			bool flag = 0;
			for (int i = 1; i < s.size(); i++)
			{
				auto x = s.substr(0, i);
				auto y = s.substr(i);
				if (st.count(x) && st.count(y))
				{
					cout << 1;
					flag = 1;
					break;
				}
			}
			if (!flag)
				cout << 0;
		}
		cout << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}