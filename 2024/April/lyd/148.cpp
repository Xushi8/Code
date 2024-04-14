// 2024/04/14 09:14:11
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
	priority_queue<int, vector<int>, greater<>> que;
	while (n--)
	{
		int x;
		cin >> x;
		que.emplace(x);
	}

	int ans = 0;
	while (que.size() >= 2)
	{
		auto x = que.top();
		que.pop();
		auto y = que.top();
		que.pop();
		ans += x + y;
		que.emplace(x + y);
	}
	cout << ans << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}