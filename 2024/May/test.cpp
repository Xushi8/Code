#include <fmt/core.h>
using fmt::print;

struct A
{
	A()
	{
		print("Default construct\n");
	}

	A(int val) :
		m_val(val)
	{
		print("Copy construct\n");
	}

	int get() const
	{
		return m_val;
    }

	int m_val;
};

extern A a;

int main()
{
	print("{}\n", a.get());
}