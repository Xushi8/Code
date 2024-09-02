#include <boost/container/vector.hpp>
using namespace boost::container;

struct A
{
    int x{};
    int y{};
};

vector<A> func()
{
    vector<A> a(1000000);
    return a;
}