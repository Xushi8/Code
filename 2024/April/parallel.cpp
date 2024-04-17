// 2024/04/16 20:20:17
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
#include <execution>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using u64 = uint64_t;
constexpr int N = 1000005;

size_t func(vector<u64> const& a)
{
	return count_if(std::execution::par_unseq, a.begin(), a.end(), [](u64 x)
		{
			return x % 2 == 0;
		});
}

size_t func1(vector<u64> const& a)
{
	return count_if(a.begin(), a.end(), [](u64 x)
		{
			return x % 2 == 0;
		});
}

void print(vector<u64> const& a)
{
	for (size_t i = 10000000; i < 100000000; i += 10000000)
	{
		cout << a[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	size_t n;
	ifstream ifs("test.in");
	ifs >> n;
	vector<u64> a(n);
	for (auto& x : a)
	{
		ifs >> x;
	}

	cout << "sort begin" << endl;

	// sort(a.begin(), a.end());
	// sort(std::execution::par, a.begin(), a.end());
	// print(a);

	// cout << func(a) << endl;
	// cout << func1(a) << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}