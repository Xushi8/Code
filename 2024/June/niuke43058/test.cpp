#include <climits>
#include <fmt/core.h>

using namespace std;

int main()
{
	int x = INT_MAX;
	x++;
	fmt::print("{}\n", x);
	return x;
}