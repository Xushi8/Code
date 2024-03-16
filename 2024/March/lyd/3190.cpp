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

struct A
{
	int first, second, id;
};

bool cmp(A x, A y)
{
	return x.first < y.first;
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
		int x, y;
		cin >> x >> y;
		a[i] = {x, y, i};
	}

	sort(a.begin(), a.end(), cmp);
	priority_queue<pii, vector<pii>, greater<pii> > que;
	int cnt = 0;
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		if (!que.empty())
		{
			pii p = que.top();
			que.pop();
			int x = p.first, y = p.second;
			if (x >= a[i].first)
			{
				que.push({x, y});
				que.push({a[i].second, ++cnt});
				ans[a[i].id] = cnt;
			}
			else
			{
				que.push({a[i].second, y});
				ans[a[i].id] = y;
			}
		}
		else
		{
			que.push({a[i].second, ++cnt});
			ans[a[i].id] = cnt;
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << '\n';
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}