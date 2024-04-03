// 2024/04/03 18:32:36
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

	double x, z;
	int y;
	cin >> x >> y >> z;

	double val;
	if (y == 0)
	{
		val = x * 2.455;
	}
	else
	{
		val = x * 1.26;
	}

	cout << setprecision(2) << fixed;

	cout << val << ' ';
	if (z > val)
		cout << "^_^";
	else
		cout << "T_T";

#ifdef LOCAL
			cerr
			 << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}