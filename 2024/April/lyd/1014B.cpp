// 2024/04/29 17:01:38
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
constexpr int N = 9;

int row[N], col[N], cell[N][N];
char s[N * N + 1];

int ones[1 << N], mp[1 << N];


int lowbit(int x)
{
	return x & -x;
}

int get(int x, int y)
{
	return row[x] & col[y] & cell[x / 3][y / 3];
}

void draw(int x, int y, int t, bool is_set)
{
	if (is_set)
	{
		s[x * N + y] = t + '1';
	}
	else
	{
		s[x * N + y] = '.';
	}

	int v = 1 << t;
	if (!is_set)
	{
		v = -v;
	}

	row[x] -= v;
	col[y] -= v;
	cell[x / 3][y / 3] -= v;
}

int init()
{
	int cnt = 0;
	int S = (1 << N) - 1;
	fill(row, row + N, S);
	fill(col, col + N, S);
	fill(cell[0], cell[0] + N, S);

	for (int i = 0, k = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++, k++)
		{   
			if (s[k] != '.')
			{
				draw(i, j, s[k] - '1', true);
			}
			else
			{
				cnt++;
			}
		}
	}
	return cnt;
}

bool dfs(int cnt)
{
	if (cnt == 0)
		return true;

	int minn = 1e9;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (s[i * N + j] == '.')
			{
				int S = get(i, j);
				if (ones[S] < minn)
				{
					minn = ones[S];
					x = i, y = j;
				}
			}
		}
	}

	for (int S = get(x, y); S != 0; S -= lowbit(S))
	{
		int t = mp[lowbit(S)];

		draw(x, y, t, true);

		if (dfs(cnt - 1))
			return true;

		draw(x, y, t, false);
	}

	return false;
}

void solve()
{
	int k = init();
	dfs(k);
	cout << s << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < N; i++)
	{
		mp[1 << i] = i;
	}
	
	for (int i = 0; i < (1 << N); i++)
	{
		ones[i] = __builtin_popcount(i);
	}

	while (cin >> s && s[0] != 'e')
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}