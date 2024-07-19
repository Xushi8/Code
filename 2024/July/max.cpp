#include <algorithm>
#include <fmt/format.h>
#include <vector>
using namespace std;
using fmt::print;

int main()
{
	vector<int> a{1, -3, -7, 8, 12, -14};
	print("{}\n", *max_element(a.begin(), a.end(), [](auto const& l, auto const& r)
					  {
						  return l < r;
					  }));
}