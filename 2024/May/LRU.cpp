#include <string>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <list>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>


using fmt::print;
using std::list;
using std::unordered_map;
using std::ifstream;
using std::string;
using std::vector;

struct page
{
	size_t id;
	bool in_memory;
	bool is_modified;
	size_t memmory_num;
	size_t disk_num;

	static constexpr size_t block_size = 128;
};

int main()
{
	ifstream ifs("page.in");

	vector<page> pages = {
		{0, 1, false, 5, 11},
		{1, 1, false, 8, 12},
		{2, 1, false, 9, 13},
		{3, 1, false, 1, 21},
		{4, 0, false, static_cast<size_t>(-1), 22},
		{5, 0, false, static_cast<size_t>(-1), 22},
		{6, 0, false, static_cast<size_t>(-1), 121}};

	// 存储所有在主存中的页的id, 按修改顺序递减排列
	list<size_t> in_memory = {3, 2, 1, 0};
	// 以哈希的方式存主存内各页的指针
	unordered_map<size_t, list<size_t>::iterator> hash_in_memory;
	for (auto it = in_memory.begin(); it != in_memory.end(); it++)
	{
		hash_in_memory.emplace(*it, it);
	}

	string op;
	size_t page_num, offset;
	while (ifs >> op >> page_num >> offset)
	{
		if (pages[page_num].in_memory)
		{
			// 将访问的页放到最新的位置
			auto it = hash_in_memory[page_num];
			in_memory.erase(it);
			in_memory.emplace_front(page_num);
			hash_in_memory[page_num] = in_memory.begin();
			
			if (op == "存")
			{
				pages[page_num].is_modified = true;
			}
			print("{}\n", (pages[page_num].memmory_num << 7) | offset);
		}
		else
		{
			// 移除最久未使用的页
			size_t erase_num = in_memory.back();
			in_memory.pop_back();
			hash_in_memory.erase(erase_num);
			pages[erase_num].in_memory = false;

			if (pages[erase_num].is_modified)
			{
				print("OUT {}\n", erase_num);
			}
			else
			{
				print("IN {}\n", page_num);
			}
			pages[erase_num].is_modified = false;

			// 将新的页添加到最新的位置
			pages[page_num].in_memory = true;
			in_memory.emplace_front(page_num);
			hash_in_memory.emplace(page_num, in_memory.begin());
			std::swap(pages[page_num].memmory_num, pages[erase_num].memmory_num);
		}

		// print(stderr, "{}\n", in_memory);
	}

	return 0;
}