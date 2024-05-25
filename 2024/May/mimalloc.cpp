#include <mimalloc-new-delete.h>
#include <vector>
using namespace std;

void no_use(vector<int> const& a) noexcept;

void funcccc(size_t n, const int val)
{
	vector<int> a(n, val);
	no_use(a);
}
