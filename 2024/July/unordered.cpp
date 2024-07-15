#include <boost/unordered/unordered_flat_set.hpp>
#include <cstdint>
#include <fmt/format.h>
using fmt::print;

using i64 = int64_t;

static size_t cnt = 0;

void* operator new(std::size_t size)
{
	++cnt;				 // 每次分配内存时增加计数器
	return malloc(size); // 实际上分配内存的地方，这里使用了 malloc 函数
}

int main()
{
	srand(time(nullptr));
	boost::unordered::unordered_flat_set<i64> st(1 << 20);
	print("{}\n", cnt);

	constexpr size_t n = 1 << 20;
	for (size_t i = 0; i < n; i++)
	{
		st.emplace(rand());
	}
	print("{} {}\n", st.size(), cnt);
}