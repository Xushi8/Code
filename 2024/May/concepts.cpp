#include <vector>
#include <fmt/core.h>
#include <concepts>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
using fmt::print;

template <typename T>
concept has_iterator = requires(T&& v) {
	v.begin();
	v.end();
};

template <typename T>
requires has_iterator<T>
void func(T&& val)
{
	for (auto const& x : val)
	{
		print("{} ", x);
	}
	print("\n");
}

int main()
{
	vector<int> a(4, 8);
	func(a);

	auto it = a.begin();
	advance(it, 5);
}