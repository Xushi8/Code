// 2024/03/23 19:20:01
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

struct A
{
	string name;
	set<int> flags;
	int n;
};

bool cmp(A const& x, A const& y)
{
	if (x.flags.size() != y.flags.size())
	{
		return x.flags.size() > y.flags.size();
	}
	else
	{
		return x.n < y.n;
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<A> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].name;
		cin >> a[i].n;
		for (int j = 0; j < a[i].n; j++)
		{
			int x;
			cin >> x;
			a[i].flags.emplace(x);
		}
	}

	sort(a.begin(), a.end(), cmp);

	vector<string> ans;
	for (int i = 0; i < min(3, n); i++)
	{
		ans.emplace_back(a[i].name);
	}

	while (ans.size() < 3)
		ans.emplace_back("-");

	for (int i = 0; i < 3; i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}