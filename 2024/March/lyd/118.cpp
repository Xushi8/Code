// 2024/03/19 16:28:14
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

vector<string> s;
int siz[N];

void print(int deep, int x)
{
	if (deep == 1)
	{
		s[x] += 'X';
		return;
	}

	print(deep - 1, x);
	for (int i = 0; i < siz[deep - 1]; i++)
	{
		s[x + i].append(siz[deep - 1], ' ');
	}
	print(deep - 1, x);

	for (int i = siz[deep - 1]; i < 2 * siz[deep - 1]; i++)
	{
		s[x + i].append(siz[deep - 1], ' ');
	}
	print(deep - 1, x + siz[deep - 1]);
	for (int i = siz[deep - 1]; i < 2 * siz[deep - 1]; i++)
	{
		s[x + i].append(siz[deep - 1], ' ');
	}

	print(deep - 1, x + 2 * siz[deep - 1]);
	for (int i = 2 * siz[deep - 1]; i < 3 * siz[deep - 1]; i++)
	{
		s[x + i].append(siz[deep - 1], ' ');
	}
	print(deep - 1, x + 2 * siz[deep - 1]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	siz[1] = 1;
	for (int i = 2; i < N; i++)
	{
		siz[i] = 3 * siz[i - 1];
	}
	int n;
	while (cin >> n && n != -1)
	{
		s.resize(siz[n]);
		print(n, 0);
		for (auto const& x : s)
		{
			cout << x << '\n';
		}
		cout << '-' << '\n';
		s.clear();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}