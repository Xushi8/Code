#include <fmt/core.h>
#include <mutex>
#include <memory>
#include <mimalloc-new-delete.h>
using namespace std;
using fmt::print;

struct free_deleter
{
	constexpr void operator()(void* p) noexcept
	{
		free(p);
	}
};

int main()
{
	mutex mtx;
	// scoped_lock lock(mtx);
	lock_guard lock(mtx, adopt_lock);
	unique_ptr<int, free_deleter> ptr((int*)malloc(sizeof(int)));
	print("{}\n", sizeof(ptr));
}