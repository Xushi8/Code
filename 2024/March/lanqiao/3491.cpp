// 2024/04/12 18:37:31
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
constexpr int N = 100000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		stack<int> stk;
		int j = i;
		while (j)
		{
			stk.emplace(j % 10);
			j /= 10;
		}
		if (stk.size() % 2 == 0)
		{
			int cnt = stk.size() / 2;
            int a = 0, b = 0;
			while (cnt--)
			{
				a += stk.top(); stk.pop();
			}
			while (!stk.empty())
			{
				b += stk.top(); stk.pop();
			}
			if (a == b)
				ans++;
        }
	}
	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}