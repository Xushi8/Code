// 2024/05/17 18:14:14
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
#include <random>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	ofstream ofs("/home/tom/Documents/Code/in.txt");
	ofs << "1\n";
	int n, m, q;
	n = 100000;
	m = 100000;
	q = 200000;
	ofs << n << ' ' << m << ' ' << q << '\n';
	set<pii> st;

	mt19937 rng(random_device{}());
	uniform_int_distribution<int> r1(1, n), r2(1, 10000);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		u = r1(rng);
		v = r1(rng);
		if (st.count({u, v}) || st.count({v, u}))
		{
			i--;
			continue;
		}
		ofs << u << ' ' << v << ' ' << r2(rng) << '\n';
	}

	for (int i = 0; i < q; i++)
	{
		ofs << r2(rng) << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}