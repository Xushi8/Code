// 2024/04/06 14:10:19
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cin.ignore(111, '\n');
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		getline(cin, a[i]);
	}

	string ans = "Wo AK le";
	for (int i = 0; i < n; i++)
	{
		auto s = a[i];
		if (s.find("easy") != -1 || s.find("qiandao") != -1)
		{
			continue;
		}
		if (m == 0)
		{
			ans = s;
		}
		m--;
	}

	cout << ans << endl;


#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}