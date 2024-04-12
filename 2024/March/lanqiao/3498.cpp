// 2024/04/12 10:08:00
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	constexpr double target = 11625907.5798;

	constexpr int N = 23333333;
	for (int i = 0; i < N / 2 + 1; i++)
	{
		double p0 = 1.0 * i / N;
		double p1 = 1 - p0;
		double ans = -p0 * log2(p0) * i - p1 * log2(p1) * (N - i);
		if (abs(target - ans) < 1e-4)
		{
			cout << ans << ' ' << i << endl;
        }
	}

#ifdef LOCAL
	cerr
		<< "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}