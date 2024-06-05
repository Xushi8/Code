#include <string>
using namespace std;

template <typename T>
struct uninitialized_allocator : public std::allocator<T>
{
	void construct(T* p)
	{
		new (p) T;
    }
};

int main()
{
	std::basic_string<char, std::char_traits<char>, uninitialized_allocator<char>> s;

}