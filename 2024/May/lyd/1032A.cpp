// 2024/05/17 10:49:55
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

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 200005;

int bit[N];
int query(int i)
{
	int ans = 0;
	for (; i; i -= i & -i)
	{
		ans += bit[i];
    }
	return ans;
}

void add(int i, int x)
{
	for (; i < N; i += i & -i)
	{
		bit[i] += x;
    }
}

void clear()
{
	memset(bit, 0, sizeof(bit));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<i64> left(n + 1), right(n + 1);
	clear();
	for (int i = 1; i <= n; i++)
	{
		left[i] = (i - 1) - query(a[i] - 1);
		add(a[i], 1);
	}
	clear();
	for (int i = n; i >= 1; i--)
	{
		right[i] = (n - i) - query(a[i] - 1);
        add(a[i], 1);
    }

	i64 ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += left[i] * right[i];
	}
	cout << ans << ' ';


	clear();
	for (int i = 1; i <= n; i++)
	{
		left[i] = query(a[i] - 1);
        add(a[i], 1);
	}

	clear();
	for (int i = n; i >= 1; i--)
	{
		right[i] = query(a[i] - 1);
        add(a[i], 1);
	}

	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += left[i] * right[i];
	}
	cout << ans << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}