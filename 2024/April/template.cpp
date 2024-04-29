#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
using namespace std;
using fmt::print;

// template <typename T, typename... Ts>
// void push_back(std::vector<T>& v, Ts&&... values)
// {
// 	(v.push_back(std::forward<Ts>(values)), ...);
// }

// 反向push
template <typename T, typename... Ts>
void push_back(std::vector<T>& v, Ts&&... values)
{
	(..., v.push_back(std::forward<Ts>(values)));
}

int main()
{
	vector<int> v;
	push_back(v, 4, 5, 6, 7, 8, 9, 10);
	print("{}\n", v);
}