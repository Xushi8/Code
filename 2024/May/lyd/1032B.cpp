// 2024/05/17 11:34:56
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
constexpr int N = 1000005;

int bit[N];

void add(int i, int x)
{
	for (; i < N; i += i & -i)
	{
		bit[i] += x;
    }
}

int sum(int i)
{
	int res = 0;
	for (; i > 0; i -= i & -i)
	{
		res += bit[i];
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while (m--)
	{
		char op;
		cin >> op;
		if (op == 'Q')
		{
			int i;
			cin >> i;
			cout << sum(i) + a[i - 1] << '\n';
		}
		else
		{
			int l, r, x;
			cin >> l >> r >> x;
			add(l, x);
			add(r + 1, -x);
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}