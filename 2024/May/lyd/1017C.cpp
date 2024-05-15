// 2024/05/15 16:37:59
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

constexpr int dx[4] = {0, 0, -1, 1};
constexpr int dy[4] = {-1, 1, 0, 0};
constexpr char pa[5] = "wens";

struct A
{
	int x, y;
	string path;
};

void solve(int n, int m)
{
	static int tt = 1;
	cout << "Maze #" << tt++ << '\n';

	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	auto valid = [&](int x, int y)
	{
		return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#';
	};

	

	int bx, by, sx, sy, ex, ey;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'B')
				bx = i, by = j;
			else if (a[i][j] == 'T')
				ex = i, ey = j;
			else if (a[i][j] == 'S')
				sx = i, sy = j;
		}
	}


	cout << "Impossible.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m && (n || m))
	{
		solve(n, m);
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}