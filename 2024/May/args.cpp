#include <fmt/format.h>
using fmt::print;


int main(int argc, char* argv[])
{
	print("{}\n", argc - 1);
	for (int i = 1; i < argc; i++)
	{
		print("{}\n", argv[i]);
    }
}