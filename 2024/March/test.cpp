#include <fmt/core.h>
using namespace fmt;

int main()
{
	for (size_t i = 0; i < 1000000; i++)
	{
		print("{}\n", i);
    }
    
	return 0;
}