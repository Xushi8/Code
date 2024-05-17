#include <unordered_set>
#include <fmt/core.h>
using fmt::print;
using namespace std;

template <typename T, typename U>
struct hash<pair<T, U>>
{
	size_t operator()(pair<T, U> const& val) const noexcept
	{
		return std::hash<T>()(val.first) ^ std::hash<U>()(val.second);
    }
};

int main()
{
	unordered_set<pair<int, int>> st;

	st.emplace(1, 1);
	st.emplace(2, 2);
	st.emplace(1, 1);
	for (auto const& [x, y] : st)
		print("{} {}\n", x, y);
}