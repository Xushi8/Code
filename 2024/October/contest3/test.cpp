#include <list>

int main()
{
    std::list<int> l{1, 2};
    auto it1 = l.begin();
    auto it2 = --l.end();
    return &*it1 < &*it2;
}