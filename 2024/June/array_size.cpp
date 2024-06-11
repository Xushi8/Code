#include <fmt/core.h>
#include <fmt/format.h>
using fmt::print;
using namespace std;

template <typename T, size_t N>
constexpr size_t array_size([[maybe_unused]] T (&val)[N])
{
	print("{}\n", fmt::ptr(val));
	print("{}\n", fmt::ptr(val + 1));
	print("{}\n", fmt::ptr(val + N));
	return N;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	print("arr: {}\n", array_size(arr));
}