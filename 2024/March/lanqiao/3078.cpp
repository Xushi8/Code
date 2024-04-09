// 2024/04/09 14:08:14
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
map<int, string> mp = {
	{0, "绿"},
	{1, "蓝"},
	{2, "白"},
	{3, "红"},
	{4, "黄"},
	{5, "橙"},
};

void debug(array<array<int, 4>, 6> a)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cerr << mp[a[i][j]];
		}
		cerr << '\n';
	}
	cerr << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	array<array<int, 4>, 6> arr;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = i;
		}
	}

	for (auto ch : s)
	{
		if (ch == 'x')
		{
			// 2 3 4 5      2 3
			int px = arr[5][2], py = arr[5][3];
			swap(arr[2][2], px);
			swap(arr[2][3], py);

			swap(arr[3][2], px);
			swap(arr[3][3], py);

			swap(arr[4][2], px);
			swap(arr[4][3], py);

			swap(arr[5][2], px);
			swap(arr[5][3], py);



			px = arr[0][0];
			swap(px, arr[0][1]);
			swap(px, arr[0][3]);
			swap(px, arr[0][2]);
			swap(px, arr[0][0]);

			px = arr[1][1];
			swap(px, arr[1][0]);
			swap(px, arr[1][2]);
			swap(px, arr[1][3]);
			swap(px, arr[1][1]);
		}
		else if (ch == 'y')
		{
			// 0 2 1 4     1 3
			int px = arr[4][2], py = arr[4][0];
			swap(arr[0][1], px);
			swap(arr[0][3], py);

			swap(arr[2][1], px);
			swap(arr[2][3], py);

			swap(arr[1][1], px);
			swap(arr[1][3], py);

			swap(arr[4][2], px);
			swap(arr[4][0], py);

			px = arr[3][0];
			swap(px, arr[3][1]);
			swap(px, arr[3][3]);
			swap(px, arr[3][2]);
			swap(px, arr[3][0]);

			px = arr[5][1];
			swap(px, arr[5][0]);
			swap(px, arr[5][2]);
			swap(px, arr[5][3]);
			swap(px, arr[5][1]);
		}
		else
		{
			// 5 1 3 0    0 1
			int px = arr[0][0], py = arr[0][1];
			swap(arr[5][1], px);
			swap(arr[5][3], py);

			swap(arr[1][3], px);
			swap(arr[1][2], py);

			swap(arr[3][2], px);
			swap(arr[3][0], py);

			swap(arr[0][0], px);
			swap(arr[0][1], py);

			px = arr[2][0];
			swap(px, arr[2][1]);
			swap(px, arr[2][3]);
			swap(px, arr[2][2]);
			swap(px, arr[2][0]);

			px = arr[4][1];
			swap(px, arr[4][0]);
			swap(px, arr[4][2]);
			swap(px, arr[4][3]);
			swap(px, arr[4][1]);
		}

		// debug(arr);
	}

	array<int, 3> ans = {
		arr[0][1],
		arr[3][2],
		arr[2][3],
	};
	for (int i = 0; i < 3; i++)
	{
		cout << mp[ans[i]];
	}
	cout << '\n';

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}