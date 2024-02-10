#include <iostream>
#include <memory>
#include <fmt/format.h>
#include <string>
#include <utility>
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

int main()
{
	A a;
	a.p = make_unique<string>("skldalj");
	A b = a;
	A c = std::move(a);

	return 0;
}