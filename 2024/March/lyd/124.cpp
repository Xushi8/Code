// 2024/03/29 20:07:18
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

int func(char ch)
{
	if (isdigit(ch))
		return ch - '0';
	if (isupper(ch))
		return ch - 'A' + 10;
	if (islower(ch))
		return ch - 'a' + 36;
}

void solve()
{
	int from, to;
	string s;
	cin >> from >> to >> s;
	cout << from << ' ' << s << '\n';
	cout << to << ' ';

	reverse(s.begin(), s.end());
	vector<int> ans;
	ll val = 0;
	ll tot = 1;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		val += func(ch) * tot;
		tot *= to;
		while (val >= to)
		{
			ans.emplace_back(val % to);
			val /= to;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}