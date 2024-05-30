#include <iostream>
#include <memory>
#include <fmt/format.h>
#include <string>
#include <utility>
#include <algorithm>
#include <execution>
using namespace std;

struct A
{
	unique_ptr<string> p;
	A() = default;
	A(A const& that)
	{
		p = make_unique<string>(*that.p);
	}
	A(A&& that) = default;

	A& operator=(A const& that)
	{
		if (this != &that) [[likely]]
		{
			p = nullptr;
			p = make_unique<string>(*that.p);
		}
		return *this;
	}

	A& operator=(A&& that) = default;
};

struct free_deleter
{
	void operator()(void* p) const noexcept
	{
		free(p);
	}
};

struct fclose_deleter
{
	void operator()(FILE* p) const noexcept
	{
		fclose(p);
	}
};



int main()
{
	A a;
	a.p = make_unique<string>("skldalj");
	A b = a;
	A c = std::move(a);

	int* x = static_cast<int*>(malloc(sizeof(int)));
	std::unique_ptr<int, free_deleter> p(x);
	FILE* fp = fopen("in.txt", "aw");
	if (!fp)
	{
		fmt::print("打开文件失败\n");
	}
	std::unique_ptr<FILE, fclose_deleter> p1(fp);
	fmt::print(p1.get(), "lasdkj\n");

	auto p2 = make_unique_for_overwrite<int>();

	int arr[100] = {0};
	sort(std::execution::par_unseq, arr, arr + 100);

	return 0;
}