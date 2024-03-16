#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <math.h>
#include <stack>
#include <fstream>
#include <bitset>
#include <numeric>
using namespace std;
typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define N 1000005

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n, 0);
	int index, tallest;
	cin >> index >> tallest;
	int m;
	cin >> m;
	set<pii> st;
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		if (l > r)
			swap(r, l);
		if (st.count(make_pair(l, r)) == 1)
		{
			continue;
		}
		st.insert(make_pair(l, r));
		a[l + 1]--;
		a[r]++;
	}

	for (int i = 1; i < n; i++)
	{
		a[i] += a[i - 1];
	}

	int t_max = *max_element(a.begin(), a.end());
	int tmp = 0;
	while (t_max + tmp < tallest)
	{
		tmp++;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] + tmp << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}