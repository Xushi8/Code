#include <fmt/format.h>
#include <atomic>
#include <mutex>
#include <boost/thread/mutex.hpp>
using namespace std;

atomic<size_t> val1 = 0;
size_t val2 = 0;
mutex mtx1;
boost::mutex mtx2;
recursive_mutex mtx3;

void func1(const size_t n) noexcept
{
	for (size_t i = 0; i < n; i++)
	{
		val1++;
	}
}

void func2(const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		scoped_lock lock(mtx1);
		val2++;
	}
}