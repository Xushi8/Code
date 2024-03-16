// 2024/03/15 18:11:19
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

__attribute__((always_inline)) void flip(array<bitset<5>, 5>& bits, size_t x, size_t y)
{
	bits[x][y].flip();
	for (size_t i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (0 <= tx && tx < 5 && 0 <= ty && ty < 5)
		{
			bits[tx][ty].flip();
		}
	}
}

void solve()
{
	array<bitset<5>, 5> bits;
	for (size_t i = 0; i < 5; i++)
	{
		cin >> bits[i];
	}
	int ans = N;
	for (size_t i = 0; i < (1 << 5); i++)
	{
		auto tmp = bits;
		int cnt = 0;
		for (size_t j = 0; j < 5; j++)
		{
			if ((i >> j) & 1)
			{
				// tmp[0][j].flip();
				flip(tmp, 0, j);
				cnt++;
			}
		}
		for (size_t j = 1; j < 5; j++)
		{
			for (size_t k = 0; k < 5; k++)
			{
				if (tmp[j - 1][k] == 0)
				{
					flip(tmp, j, k);
					cnt++;
				}
			}
		}
		if (tmp[4].count() == 5)
		{
			ans = min(ans, cnt);
		}
	}
	cout << (ans <= 6 ? ans : -1) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
	}
#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}