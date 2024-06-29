#include <fmt/core.h>
#include <vector>
#include <set>
#include <chrono>
#include <cstdint>
using namespace std;

using i64 = int64_t;

template <typename F, typename... Ts>
[[gnu::always_inline]] inline constexpr auto func(F&& f, Ts&&... ts)
{
	return f(std::forward<Ts>(ts)...);
}

[[gnu::always_inline]] inline i64 f1(i64 x)
{
	return x ^ std::chrono::system_clock::now().time_since_epoch().count();
}

inline i64 f2()
{
	return std::chrono::system_clock::now().time_since_epoch().count();
}

int main()
{
	// vector<int> arr = {1, 4, 2, 8, 5, 1, 7, 4};
	// set<int> visited;
	// auto dfs = [&](auto&& self, int index) -> void
	// {
	// 	if (visited.find(index) == visited.end())
	// 	{
	// 		visited.insert(index);
	// 		fmt::print("{}\n", index);
	// 		int next = arr[index];
	// 		self(self, next);
	// 	}
	// };
	// dfs(dfs, 0);

	fmt::print("{}\n", func(f1, 1));
	fmt::print("{}\n", func(f2));
}