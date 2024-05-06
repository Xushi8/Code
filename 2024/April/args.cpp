#include <fmt/core.h>
using fmt::print;

int main(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		print("{} {}\n", i, argv[i]);
    }
    
	return 0;
}