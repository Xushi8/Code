// #include <mimalloc-new-delete.h>
#include <vector>
#include <iostream>
#include <fmt/core.h>
using fmt::print;
using namespace std;

void no_use(vector<int> const& a) noexcept;

int main()
{
	size_t n;
	cin >> n;
	vector<int> a(n);
	no_use(a);
}
