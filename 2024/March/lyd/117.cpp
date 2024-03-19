// 2024/03/19 15:36:57
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
#include <thread>
using namespace std;
using namespace std::chrono_literals;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<deque<pii>, 14> a;
	map<char, int> mp = {{'0', 10}, {'A', 1}, {'J', 11}, {'Q', 12}, {'K', 13}};

	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char ch;
			cin >> ch;
			auto it = mp.find(ch);
			if (it != mp.end())
				a[i].emplace_back(it->second, 0);
			else
				a[i].emplace_back(ch - '0', 0);
		}
	}

	int cnt[14] = {0};
	for (int life = 0; life < 4; life++)
	{
		auto [x, y] = a[13].front();
		a[13].pop_front();
		cnt[x]++;
		int nex = x;
		a[nex].emplace_front(x, 1);
		while (1)
		{
			auto [nx, ny] = a[nex].back();
			a[nex].pop_back();
			if (nx == 13)
				break;

			if (ny == 0)
				cnt[nx]++;
			nex = nx;
			a[nex].emplace_front(nx, 1);
		}
	}

	int ans = 0;
	for (int i = 1; i < 13; i++)
	{
		if (cnt[i] == 4)
			ans++;
	}
	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}