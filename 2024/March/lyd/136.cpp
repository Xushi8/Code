// 2024/04/02 17:50:39
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
constexpr int MOD = 133331;

int H(array<int, 6> const& arr)
{
	int sum = 0, mul = 1;
	for (int i = 0; i < 6; i++)
	{
		sum = (sum + arr[i]) % MOD;
		mul = (1LL * mul * arr[i]) % MOD;
	}
	return (sum + mul) % MOD;
}

bool equal(array<int, 6> const& a, array<int, 6> const& b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			bool eq = 1;
			for (int k = 0; k < 6; k++)
			{
				if (a[(i + k) % 6] != b[(j + k) % 6])
					eq = 0;
			}
			if (eq)
				return true;
			eq = 1;
			for (int k = 0; k < 6; k++)
			{
				if (a[(i + k) % 6] != b[(j - k + 6) % 6])
					eq = 0;
			}
			if (eq)
				return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<int, vector<array<int, 6>>> mp;
	bool flag = 0;
	while (n--)
	{
		array<int, 6> a;
		for (int i = 0; i < 6; i++)
		{
			cin >> a[i];
		}

		int val = H(a);
		auto& arr = mp[val];
		if (!arr.empty())
		{
			for (auto const& b : arr)
			{
				if (equal(a, b))
				{
					flag = 1;
				}
			}
		}
		arr.emplace_back(std::move(a));
	}

	cout << (flag ? "Twin snowflakes found." : "No two snowflakes are alike.") << '\n';

#ifdef LOCAL
	cerr
		<< "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}