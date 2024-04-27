#include <iterator>
#include <vector>
using namespace std;

template <typename T>
void func(T&& tmp)
{
	static_assert(is_same_v<decltype(std::forward<T>(tmp).begin()), decltype(T().begin())>);
}

int main()
{
	vector<int> tmp;
	func(std::move(tmp));

	return 0;
}