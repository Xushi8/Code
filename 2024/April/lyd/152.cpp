// 2024/04/15 18:37:11
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
constexpr int N = 10005;

char b[N][N];
int a[N][N];
int L[N], R[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
        }
	}

	for (int j = 0; j < m; j++)
	{
		if (b[0][j] == 'F')
			a[0][j] = 1;
		else
			a[0][j] = 0;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 'F')
				a[i][j] = a[i - 1][j] + 1;
			else
				a[i][j] = 0;
        }
	}

	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		stack<int> stk;
		for (int j = 0; j < m; j++)
		{
			while (!stk.empty() && a[i][stk.top()] >= a[i][j])
				stk.pop();
			L[j] = stk.empty() ? -1 : stk.top();
			stk.emplace(j);
		}
		stack<int>().swap(stk);
		for (int j = m - 1; j >= 0; j--)
		{
			while (!stk.empty() && a[i][stk.top()] >= a[i][j])
				stk.pop();
			R[j] = stk.empty() ? m : stk.top();
			stk.emplace(j);
		}

		for (int j = 0; j < m; j++)
		{
			ans = max(ans, 1LL * a[i][j] * (R[j] - L[j] - 1));
        }
	}

	cout << ans * 3 << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}