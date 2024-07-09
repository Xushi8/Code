#include <optional>
#include <utility>
#include <iostream>
#include <fmt/format.h>
using fmt::print;

template <typename... Ts>
auto func(Ts&&... ts)
{
	return (0 + ... + std::forward<Ts>(ts));
}

struct A
{
	int x = 10;
};

int main()
{
	int a;
	std::cin >> a;
	print("{}\n", std::is_trivial_v<A>);

	return func(a, 12, 2, 3, 4);
}