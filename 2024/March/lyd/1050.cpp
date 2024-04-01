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
	vector<vector<int> > a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	int ans = -1e9;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp(n, 0);
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				tmp[k] += a[j][k];
			}
			int now = 0;
			for (int k = 0; k < n; k++)
			{
				if (now >= 0)
					now += tmp[k];
				else
					now = tmp[k];
				ans = max(ans, now);
			}
		}
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}