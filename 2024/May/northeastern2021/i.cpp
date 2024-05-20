// 2024/05/17 13:26:06
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
	{
		cin >> x;
    }
	vector<int> prices = {7, 27, 41, 49, 63, 78, 108};
	int sum = 0;
	for (auto x : a)
	{
		sum += prices[x - 1];
	}
	if (sum >= 120)
		sum -= 50;
	else if (sum >= 89)
		sum -= 30;
	else if (sum >= 69)
		sum -= 15;
	cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		solve();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}