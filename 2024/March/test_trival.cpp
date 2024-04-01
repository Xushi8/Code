#include <type_traits>
#include <fmt/core.h>
using fmt::print;
using namespace std;

struct A
{
	int x;
};

struct B
{
	B() = default;
	~B() {}
	int x;
};

struct C
{
	C() {}
	int x;
};

struct D
{
    D();
	int x;
};

D::D() = default;

int main()
{
	print("A is_trival: {}\n", is_trivial<A>::value);
	print("A is_trivially_default_constructible: {}\n", is_trivially_default_constructible<A>::value);
	print("A is_trivially_destructible: {}\n", is_trivially_destructible<A>::value);
	print("B is_trival: {}\n", is_trivial<B>::value);
	print("B is_trivially_default_constructible: {}\n", is_trivially_default_constructible<B>::value);
	print("B is_trivially_destructible: {}\n", is_trivially_destructible<B>::value);
	print("C is_trival: {}\n", is_trivial<C>::value);
	print("C is_trivially_default_constructible: {}\n", is_trivially_default_constructible<C>::value);
	print("C is_trivially_destructible: {}\n", is_trivially_destructible<C>::value);
	print("D is_trival: {}\n", is_trivial<D>::value);
	print("D is_trivially_default_constructible: {}\n", is_trivially_default_constructible<D>::value);
	print("D is_trivially_destructible: {}\n", is_trivially_destructible<D>::value);

	return 0;
}