// 2024/04/12 13:29:45
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

	size_t n;
	cin >> n;
	vector<string> a(n);
	for (auto& x : a)
		cin >> x;

	array<int, 10> dp;
	dp.fill(0);

	for (auto const& s : a)
	{
		int x = s.front() - '0', y = s.back() - '0';
		dp[y] = max(dp[y], dp[x] + 1);
	}

	cout << n - *max_element(dp.begin(), dp.end()) << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}