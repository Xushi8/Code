#include <cstddef>
#include <vector>
#include <fstream>
#include <string>
#include <fmt/format.h>

using std::vector;
using std::ifstream;
using std::string;
using fmt::print;

struct page
{
	size_t id;
	bool in_memory;
	size_t memmory_num;
	size_t disk_num;

	static constexpr size_t block_size = 128;
};

int main()
{
	vector<page> pages = {
		{0, 1, 5, 11},
		{1, 1, 8, 12},
		{2, 1, 9, 13},
		{3, 1, 1, 21},
		{4, 0, static_cast<size_t>(-1), 22},
		{5, 0, static_cast<size_t>(-1), 22},
		{6, 0, static_cast<size_t>(-1), 121}};

	ifstream ifs("page.in");
	string option;
	size_t page_num, offset;
	while (ifs >> option >> page_num >> offset)
	{
		if (pages[page_num].in_memory)
		{   
			// print("{}\n", pages[page_num].memmory_num * 128 + offset);
			print("{}\n", (pages[page_num].memmory_num << 7) | offset);
		}
		else
		{
			print("*{}\n", page_num);
        }
    }

	return 0;
}