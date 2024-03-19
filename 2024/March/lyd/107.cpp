// 2024/03/18 20:46:57
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
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> tmp(n);
		ll ans = 0;
		merge_sort(a, 0, n, tmp, ans);
		cout << ans << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}