// 2024/03/15 11:01:57
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

void merge_sort(vector<int>& a, int l, int r, vector<int>& tmp, ll& ans)
{
	if (l >= r - 1)
		return;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid, tmp, ans);
	merge_sort(a, mid, r, tmp, ans);
	int tot = l;
	int p = l, q = mid;
	while (tot < r)
	{
		if (q == r || (p < mid && a[p] <= a[q]))
			tmp[tot++] = a[p++];
		else
			tmp[tot++] = a[q++], ans += mid - p;
	}
	for (int i = l; i < r; i++)
	{
		a[i] = tmp[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n && n != 0)
	{
		if (n == 1)
		{
			cout << "TAK" << '\n';
			continue;
		}

		vector<vector<int>> a(n, vector<int>(n));
		auto b = a;
		vector<int> ta(n * n - 1);
		vector<int> tb(n * n - 1);
		int tot = 0;
		int bx, by, ex, ey;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				ta[tot++] = a[i][j];
				if (a[i][j] == 0)
					tot--, bx = i, by = j;
			}
		}
		tot = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> b[i][j];
				tb[tot++] = b[i][j];
				if (b[i][j] == 0)
					tot--, ex = i, ey = j;
			}
		}

		ll t1 = 0, t2 = 0;
		vector<int> tmp(n * n);
		merge_sort(ta, 0, n * n, tmp, t1);
		merge_sort(tb, 0, n * n, tmp, t2);
		cout << (t1 % 2 == t2 % 2 ? "TAK" : "NIE") << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}