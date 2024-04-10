// 2024/04/10 14:00:05
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

void print(int t1, int t2)
{
	int h1, m1, s1, h2, m2, s2;
	h1 = t1 / 3600;
	m1 = t1 % 3600 / 60;
	s1 = t1 % 60;
	h2 = t2 / 3600;
	m2 = t2 % 3600 / 60;
	s2 = t2 % 60;

	printf("%02d:%02d:%02d - %02d:%02d:%02d\n", h1, m1, s1, h2, m2, s2);
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		int h1, m1, s1, h2, m2, s2;
		scanf("%d:%d:%d - %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		a[i] = {h1 * 3600 + m1 * 60 + s1, h2 * 3600 + m2 * 60 + s2};
	}

	sort(a.begin(), a.end());
	int last = 0;
	for (auto [x, y] : a)
	{
		if (x != last)
		{
			print(last, x);
		}
		last = y;
	}

	if (last != 3600 * 24 - 1)
	{
		print(last, 3600 * 24 - 1);
	}

	return 0;
}