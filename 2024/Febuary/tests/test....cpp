#include <fmt/format.h>
using namespace fmt;
using namespace std;

template <typename... Ts>
auto func(Ts... ts)
{
	(print("{} ", ts), ..., print("\n"));
}

int main()
{
	func(1, 2, 3);
	fmt::print("{}\n", __cplusplus);
}