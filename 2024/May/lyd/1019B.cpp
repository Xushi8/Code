// 2024/04/29 16:27:43
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

void my_sort(size_t l, size_t r, vector<int>& a, vector<int>& tmp, int& cnt)
{
	if (l >= r - 1)
		return;
	size_t mid = (l + r) / 2;
	size_t p = l, q = mid;
	size_t tot = l;
	while (p < mid && q < r)
	{
		if (p == mid || (q < r && a[q] < a[p]))
			tmp[tot++] = a[q++], cnt += mid - p;
		else
			tmp[tot++] = a[p++];
	}
	for (size_t i = l; i < r; i++)
	{
		a[i] = tmp[i];
	}
}

int merge_sort(vector<int>& a)
{
	vector<int> tmp(a.size());
	int cnt = 0;
	my_sort(0, a.size(), a, tmp, cnt);
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[3][3];
	vector<int> tmp;
	int x, y;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char ch;
			cin >> ch;
			if (ch != 'x')
				a[i][j] = ch - '0', tmp.emplace_back(ch - '0');
			else
				a[i][j] = 0, x = i, y = j;
		}
	}

	vector<int> t = {1, 2, 3, 4, 5, 6, 7, 8};
	if (merge_sort(tmp) % 2 != merge_sort(t) % 2)
	{
		cout << "unsolvable\n";
	}
	else
	{
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}