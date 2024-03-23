// 2024/03/23 18:40:11
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

void solve()
{
	map<int, pii> mp;
	int all = 0;
	int x;
	char ch;
	set<int> st;
	while (cin >> x && x != 0)
	{
		cin >> ch;
		int tim = 0;
		int h, m;
		char tmp;
		cin >> h >> tmp >> m;
		tim = h * 60 + m;
		if (ch == 'S')
		{
			auto it = mp.find(x);
			if (it != mp.end())
			{
				continue;
				mp.erase(it);
			}
			mp[x].first = tim;
		}
		else
		{
			auto it = mp.find(x);
			if (it == mp.end())
				continue;
			all += tim - mp[x].first;
			mp.erase(it);
			st.emplace(x);
		}
	}
	cin >> ch;
	int tim = 0;
	int h, m;
	char tmp;
	cin >> h >> tmp >> m;

	// cout << st.size() << ' ' << (st.size() == 0 ? 0 : (all + st.size() - 1) / st.size()) << '\n';
	cout << st.size() << ' ';
	if (st.size() == 0)
		cout << 0;
	else
	{
		double x = (1.0 * all) / st.size();
		int y = static_cast<int>(x);
		if (x - y >= 0.5)
			y++;
		cout << y;
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}