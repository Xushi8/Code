#include <fmt/format.h>
using namespace std;
using fmt::print;

struct A
{
    int* p;

    A() :
        p()
    {
    }

    A(A&&) = delete;
};

int main()
{
    A a;
    // A b = a;
    // A c = std::move(a);
    A d;
    // d = a;
    // d = std::move(a);
}