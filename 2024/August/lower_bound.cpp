#include <algorithm>
#include <list>
#include <fmt/format.h>
#include <numeric>
#include <vector>
using fmt::print;

template <typename It, typename T>
It lower_bound(It first, It last, T val)
{
    if constexpr (requires {{last - first} -> std::convertible_to<ssize_t>; })
    {
        print("random_access_iterator\n");
    }
    else
    {
        print("forward inerator\n");
    }

    return first;
}

int main()
{
    std::list<int> a{1, 2, 3, 4, 5};
    std::vector<int> b{1, 2, 3, 4, 5};
    auto it = ::lower_bound(a.begin(), a.end(), 3);
    print("{}\n", *it);
    auto it1 = ::lower_bound(b.begin(), b.end(), 3);
    print("{}\n", *it1);
    int c[5] = {1, 2, 3, 4, 5};
    auto it2 = ::lower_bound(std::begin(c), std::end(c), 3);
    print("{}\n", *it2);
}