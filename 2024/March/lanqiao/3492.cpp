// 2024/04/12 09:50:15
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[100];
	for (size_t i = 0; i < 100; i++)
	{
		cin >> a[i];
	}

	int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	set<tuple<int, int>> st;
	auto solve = [&](int index)
	{
		for (int i = index; i < 100; i++)
		{
			for (int j = i + 1; j < 100; j++)
			{
				for (int k = j + 1; k < 100; k++)
				{
					for (int l = k + 1; l < 100; l++)
					{
						int m = a[i] * 10 + a[j];
						int d = a[k] * 10 + a[l];
						if (1 <= m && m <= 12)
						{
							if (1 <= d && d <= days[m])
							{
								st.emplace(m, d);
							}
						}
					}
				}
			}
		}
	};

	for (size_t i = 0; i < 100; i++)
	{
		if (a[i] == 2)
		{
			for (size_t j = i + 1; j < 100; j++)
			{
				if (a[j] == 0)
				{
					for (size_t k = j + 1; k < 100; k++)
					{
						if (a[k] == 2)
						{
							for (size_t l = k + 1; l < 100; l++)
							{
								if (a[l] == 3)
								{
									solve(l + 1);
								}
							}
						}
					}
				}
			}
		}
	}

	cout << st.size() << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}