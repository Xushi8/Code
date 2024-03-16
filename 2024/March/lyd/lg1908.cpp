// 2024/03/15 10:39:54
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
	// cerr << l << ' ' << mid << ' ' << r << endl;
	merge_sort(a, l, mid, tmp, ans);
	merge_sort(a, mid, r, tmp, ans);
	int x = l, y = mid;
	int tot = l;
	while (tot < r)
	{
		if (y == r || (x < mid &&  a[x] <= a[y]))
		{
			tmp[tot++] = a[x++];
		}
		else
		{
			tmp[tot++] = a[y++];
			ans += mid - x;
        }
	}

	for (int i = l; i < r; i++)
		a[i] = tmp[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	ll ans = 0;
	vector<int> tmp(n);
	merge_sort(a, 0, n, tmp, ans);
    cout << ans << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}