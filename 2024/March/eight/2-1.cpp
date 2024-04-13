// 2024/04/13 19:25:44
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

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;

	deque<int> A, B;
	vector<deque<int>> ans;
	for (auto x : a)
	{
		if (A.empty() || x < A.back())
		{
			A.emplace_back(x);
		}
		else
		{
			if (B.empty() || x > B.back())
			{
				B.emplace_back(x);
			}
			else
			{
				ans.emplace_back(std::move(A));
				A.clear();
				while (!B.empty() && B.back() > x)
				{
					A.emplace_back(B.back());
					B.pop_back();
				}
				A.emplace_back(x);
			}
		}
	}

	ans.emplace_back(std::move(A));
	ans.emplace_back(std::move(B));
	size_t maxx = 0;
	for (auto const& x : ans)
	{
		maxx = max(maxx, x.size());
	}

	cout << ans.size() << ' ' << maxx << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}