#include <fmt/core.h>
#include <vector>
#include <span>
using namespace std;
using fmt::print;

template<typename T>
void func(T&& x)
{
	print("int&&\n");
}

void f4(vector<int>&)
{
	print("vector<int>&\n");
}
void f4(span<int>)
{
	print("span<int>\n");
}

void g3(int n)
{
	vector<int> v(n);
	f4(v);			  // 传递引用，保留所有权
	f4(span<int>{v}); // 传递视图，保留所有权
}

int main()
{
	int x = 19;
	func(x);
	g3(5);
}