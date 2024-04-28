#include <fmt/core.h>
#include <memory>
using fmt::print;
using namespace std;

void func(shared_ptr<int> p)
{
	print("{}\n", p.use_count());
}

int main()
{
	// auto p = make_shared<int>(4);
	// func(p);


}