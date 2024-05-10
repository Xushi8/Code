// 2024/05/10 12:59:32
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
#include <fmt/core.h>
using fmt::print;
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
constexpr int N = 1000005;

struct A
{
	A() :
		a()
	{
		print("A()\n");
	}

	A(initializer_list<int> const& t) :
		a(t.begin(), t.end())
	{
        print("initializer_list\n");
	}

	A(A&& that) noexcept :
		a(std::move(that.a))
	{
		print("A(A&&)\n");
	}

	A& operator=(A&& that) noexcept
	{
		print("operator=A(&&)\n");
		a = std::move(that.a);
		return *this;
	}

	A(A const& that) noexcept :
		a(that.a)
	{
		print("A(A const&)\n");
	}

	A& operator=(A const& that) noexcept
	{
		print("operator=A(const&)\n");
		a = std::move(that.a);
		return *this;
	}

	vector<int> a;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<A> arr;
	A x;
	print("emplace_back begin\n");
	arr.emplace_back(x);

	arr.emplace_back(initializer_list<int>{1, 2, 3});

	print("emplace_back over\n");

	arr.push_back(x);

	arr.push_back({1, 2, 3});

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}