// 2024/05/14 09:18:11
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
constexpr int N = 1000005;

struct A
{
	int x;
	A() = default;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	// array<int, 1000000> a;
	// for (auto x : a)
	// {
	// 	cout << x << '\n';
	// }

	array<A, 1000000> a;
	for (auto x : a)
	{
		cout << x.x << '\n';
	}

	vector<int> b{};
	b.push_back(3);
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}