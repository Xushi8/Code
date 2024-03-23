// 2024/03/23 18:59:37
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

	// cout << 111111 / 13 << endl;

	int n;
	cin >> n;
	int x = 1;
	int cnt = 1;
	while (x < n)
	{
		x = x * 10 + 1;
		cnt++;
    }

	while (1)
	{
		cout << x / n;
		x %= n;
		if (x == 0)
			break;
		while (x < n)
		{
			x = x * 10 + 1;
			cnt++;
		}
	}

	cout << ' ' << cnt << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}