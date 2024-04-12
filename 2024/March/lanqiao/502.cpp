// 2024/04/09 16:13:39
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
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x >= 60)
			a++;
		if (x >= 85)
			b++;
	}

	double ansa, ansb;
	ansa = 100.0 * a / n;
	ansb = 100.0 * b / n;
	cout << setprecision(0) << fixed << ansa << '%' << endl << ansb << '%' << endl;
	
#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}