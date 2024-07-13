#include <fmt/core.h>
#include <functional>
#include <cstdint>
using namespace std;
using fmt::print;

using i64 = int64_t;

template <typename F>
concept CallableWithIntAndReturn = requires(F&& f) {
	{ f() } -> std::same_as<void>;
};

template <CallableWithIntAndReturn F>
void func(F&& f)
{
	f();
}

template <typename F, typename... Ts>
auto func1(F&& f, Ts&&... ts)
	requires requires { { f(int{}) } -> std::convertible_to<int>; }
{
	print("{}\n", f(std::forward<Ts>(ts)...));
}

// template <typename F, typename... Ts>
// [[gnu::always_inline]] inline constexpr auto func(F&& f, Ts&&... ts)
// {
// 	return f(std::forward<Ts>(ts)...);
// }

// [[gnu::always_inline]] inline i64 f1(i64 x)
// {
// 	return x ^ std::chrono::system_clock::now().time_since_epoch().count();
// }

// inline i64 f2()
// {
// 	return std::chrono::system_clock::now().time_since_epoch().count();
// }

// struct A
// {
// 	int va, vb;
// 	// A() noexcept = default;
// 	A(int x = -1) noexcept :
// 		va(x) {}
// };

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

	// print("{}\n", func(f1, 1));
	// print("{}\n", func(f2));

	// for (size_t i = 0; i < 100000000; i++)
	// {
	// 	A a{};
	// 	print("{} {}\n", a.va, a.vb);
	// }

	func([]()
		{
			print("1\n");
		});
	func(std::bind([](int x)
		{
			print("{}\n", x);
		},
		10));

	func1([](int x) -> int
		{
			return x;
		},
		87879);
}