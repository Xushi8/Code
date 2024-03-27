// 2024/03/27 13:38:21
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

	int a, b;
	cin >> a >> b;
	int x, y, z;
	cin >> x >> y >> z;
	int tot = x + y + z;
	if (a > b && tot < 3)
		cout << "The winner is a: " << a << " + " << 3 - tot;
	else if (a < b && tot > 0)
		cout << "The winner is b: " << b << " + " << tot;
	else
	{
		if (tot == 0)
		{
			cout << "The winner is a: " << a << " + " << 3 - tot;
		}
		else
		{
			cout << "The winner is b: " << b << " + " << tot;
		}
    }

#ifdef LOCAL
			cerr
			 << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}