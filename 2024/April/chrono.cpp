#include <fmt/core.h>
#include <chrono>
#include <tbb/tick_count.h>
#include <fmt/chrono.h>
#include <iostream>
#include <fmt/ostream.h>
#include <fmt/format.h>
#include <string>
using fmt::format;
using fmt::print;
using namespace std::chrono_literals;

struct A
{
	int x, y;
	friend std::ostream& operator<<(std::ostream& os, A const& val)
	{
		os << val.x << ' ' << val.y;
		return os;
	}
};

struct point2d
{
	int x;
	int y;
	point2d(int x_, int y_) :
		x(x_), y(y_) {}
	friend std::ostream& operator<<(std::ostream& os, point2d const& p)
	{
		return os << '(' << p.x << ',' << p.y << ')';
	}
};


int main()
{
	auto duration = 1s + 3min;
	auto seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
	print("181s is {}ns\n", seconds.count());

	print("{}ns\n", std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());

	auto t = std::chrono::steady_clock::now().time_since_epoch();
	print("{}ns\n", t.count());

	print("{}\n", std::chrono::system_clock::now());

	// A a;
	// print("{}\n", a);
	// auto s = format("{}\n", a);
	std::string s = fmt::format("Position is {}", point2d{7, 9});

	return 0;
}