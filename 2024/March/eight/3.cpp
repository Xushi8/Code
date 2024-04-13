// 2024/04/13 18:56:55
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

	int n, m, k;
	string x;
	cin >> n >> x >> m >> k;
	if (k == n)
		cout << "mei you mai " << x << " de";
	else if (k == m)
		cout << "kan dao le mai " << x << " de";
	else
		cout << "wang le zhao mai " << x << " de";

#ifdef LOCAL
			cerr
			 << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}