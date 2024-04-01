// 2024/04/01 15:08:47
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

ll factorial(int n)
{
	ll res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cout << factorial(2 * n) / (factorial(n) * factorial(n + 1));

#ifdef LOCAL
					cerr
		 << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}