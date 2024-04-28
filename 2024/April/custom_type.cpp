#include <fmt/core.h>

struct point2d
{
	int x;
	int y;
	point2d(int x_, int y_) :
		x(x_), y(y_) {}
};

template <>
struct fmt::formatter<point2d>
{
	constexpr fmt::format_parse_context::iterator
	parse(fmt::format_parse_context& ctx)
	{
		auto it = ctx.begin();
		return ++it;
	}

	fmt::format_context::iterator
	format(point2d val, fmt::format_context& ctx)
	{
		return fmt::format_to(ctx.out(), "x = {} | y = {}", val.x, val.y);
	}
};

std::string s = fmt::format("Position is {}", point2d{7, 9});
// s = "Position is (7,9)"

int main()
{
	fmt::print("{}\n", s);
}