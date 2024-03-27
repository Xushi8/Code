// 2024/03/27 13:41:17
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

	int n;
	cin >> n;
	vector<pair<string, int>> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		string x;
		int y;
		cin >> x >> y;
		a[i] = {x, y};
		sum += y;
	}

	sum /= n;
	sum /= 2;
	cout << sum << ' ';
	string name;
	int minn = N;
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i].second - sum) < minn)
		{
			minn = abs(a[i].second - sum);
			name = a[i].first;
		}
	}
	cout << name << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}