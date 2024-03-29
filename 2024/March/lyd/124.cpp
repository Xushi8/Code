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

int get(char ch)
{
	if (isdigit(ch))
		return ch - '0';
	if (isupper(ch))
		return ch - 'A' + 10;
	return ch - 'a' + 36;
}

char put(int val)
{
	if (val <= 9)
		return val + '0';
	if (val <= 35)
		return val - 10 + 'A';
	return val - 36 + 'a';
}

void solve()
{
	int from, to;
	string s;
	cin >> from >> to >> s;
	cout << from << ' ' << s << '\n';
	cout << to << ' ';

	reverse(s.begin(), s.end());
	vector<int> num(s.size());
	for (size_t i = 0; i < s.size(); i++)
	{
		num[i] = get(s[i]);
	}
	vector<int> ans;

	while (!num.empty())
	{
		int yushu = 0;
		for (int i = num.size() - 1; i >= 0; i--)
		{
			num[i] += yushu * from;
			yushu = num[i] % to;
			num[i] /= to;
		}
		ans.emplace_back(yushu);
		while (!num.empty() && num.back() == 0)
			num.pop_back();
	}
	

	reverse(ans.begin(), ans.end());
	for (auto x : ans)
	{
		cout << put(x);
	}

	cout << "\n\n";
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