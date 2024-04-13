// 2024/04/13 19:13:02
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

	int n0, n1, n;
	cin >> n0 >> n1 >> n;
	int ans = -1;
	int minn = N;
	for (int i = 1; i < n - 1; i++)
	{
		int a = i, b = n - i;
		if (a == 0 || b == 0)
			continue;
		if (n0 % a != 0 || n1 % b != 0)
			continue;
		if (n0 / a == 1 || n1 / b == 1)
			continue;
		int na = n0 / a;
		int nb = n1 / b;
		if (abs(na - nb) < minn)
		{
			minn = abs(na - nb);
			ans = i;
        }
	}

	if (ans == -1)
		cout << "No Solution";
	else
		cout << ans << ' ' << n - ans << endl;

#ifdef LOCAL
			cerr
			 << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}