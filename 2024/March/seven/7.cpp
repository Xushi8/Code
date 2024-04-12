// 2024/04/10 13:16:18
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

	ll n, m, q;
	cin >> n >> m >> q;
	set<int> a, b;
	while (q--)
	{
		int op, x;
		cin >> op >> x;
		if (op == 0)
			a.emplace(x);
		else
			b.emplace(x);
	}

	ll ans = n * m - m * a.size() - n * b.size() + a.size() * b.size();
	cout << ans << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}