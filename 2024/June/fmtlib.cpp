#include <string>
#include <fmt/core.h>
using namespace std;

struct person
{
	string name;
	int age;
	double salary;
	double height;
	int id;
};

template <>
struct fmt::formatter<person>
{
	constexpr auto parse(auto&& ctx)
	{
		return ctx.begin();
	}

	constexpr auto format(person const& p, auto&& ctx)
	{
		return format_to(ctx.out(), "name: {}, age: {}, salary: {}, height: {}, id: {}", p.name, p.age, p.salary, p.height, p.id);
	}
};

int main()
{
	person p;
	p.name = "力扣撒旦教拉萨决定了";
	fmt::print("{}, {}\n", p, 7);
}