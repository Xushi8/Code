#include <string>
#include <cstddef>
#include <fstream>
#include <vector>
#include <algorithm>
#include <fmt/format.h>
#include <string_view>

using std::string;
using std::ifstream;
using std::vector;
using std::sort;
using fmt::print;
using std::string_view;

struct process
{
	string name;
	process* next;
	size_t need_time;
	size_t cpu_time;
	size_t round_time = size_t(-1);
	int priority;
	char status;
};

process* push_back(process* head, process* val)
{
	if (head == nullptr)
	{
		val->next = nullptr;
		return val;
	}

	process* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = val;
	val->next = nullptr;
	return head;
}

// 按照优先级进行插入
process* insert(process* head, process* val)
{
	if (head == nullptr)
	{
		val->next = nullptr;
		return val;
	}

	process* pre = nullptr;
	process* p = head;
	while (p != nullptr)
	{
		if (val->priority > p->priority)
		{
			break;
		}

		pre = p;
		p = p->next;
	}

	if (pre == nullptr)
	{
		head = val;
		val->next = p;
	}
	else
	{
		val->next = p;
		pre->next = val;
	}

	return head;
}

// 从给定的队头中删除给定的元素, 返回新的队头
process* erase(process* head, process* val)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	process* p = head;
	process* pre = nullptr;
	while (p != nullptr)
	{
		if (p == val)
		{
			if (pre != nullptr)
			{
				pre->next = p->next;
			}
			else
			{
				head = p->next;
			}

			break;
		}
		pre = p;
		p = p->next;
	}

	return head;
}

string_view transform(char ch)
{
	if (ch == 'R')
		return "ready";
	else if (ch == 'W')
		return "working";
	else
		return "finish";
}

void print(process* no_erase_head, process* erase_head)
{
	vector<process*> arr;
	process* p;
	p = no_erase_head;
	while (p != nullptr)
	{
		arr.emplace_back(p);
		p = p->next;
	}

	p = erase_head;
	while (p != nullptr)
	{
		arr.emplace_back(p);
		p = p->next;
	}

	sort(arr.begin(), arr.end(), [](process* x, process* y)
		{
			return x->name < y->name;
		});

	static size_t CPU_TIME = 0;
	print("CPUTIME: {}\n", CPU_TIME++);
	print("NAME CPUTIME NEEDTIME PRIORITY\tSTATE\n");
	for (process* val : arr)
	{
		print(" {}\t{}\t{}\t{}\t{}\n", val->name, val->cpu_time, val->need_time, val->priority, transform(val->status));

		if (val->status == 'F' && val->round_time == size_t(-1)) [[unlikely]]
		{
			val->round_time = CPU_TIME;
		}
	}
	print("\n");
}

int main()
{
	ifstream ifs("process.in");
	process* no_erase_head = nullptr;
	for (int i = 0; i < 5; i++)
	{
		process* tmp = new process;
		ifs >> tmp->name >> tmp->need_time >> tmp->priority;
		tmp->status = 'R';
		tmp->cpu_time = 0;
		no_erase_head = insert(no_erase_head, tmp);
	}

	process* erase_head = nullptr;
	print(no_erase_head, erase_head);

	while (no_erase_head != nullptr)
	{
		no_erase_head->cpu_time++;
		no_erase_head->need_time--;
		no_erase_head->priority--;
		if (no_erase_head->need_time == 0)
		{
			no_erase_head->status = 'F';
		}
		else
		{
			no_erase_head->status = 'W';
		}

		print(no_erase_head, erase_head);

		if (no_erase_head->need_time == 0)
		{
			no_erase_head->status = 'F';
			process* tmp = no_erase_head;
			no_erase_head = erase(no_erase_head, tmp);
			erase_head = push_back(erase_head, tmp);
		}
		else
		{
			no_erase_head->status = 'R';

			process* pre = no_erase_head;
			process* p = no_erase_head->next;
			while (p != nullptr)
			{
				if (p->priority > no_erase_head->priority)
				{
					pre = p;
					p = p->next;
				}
				else
				{
					break;
				}
			}

			if (pre != no_erase_head) // 更新了队头
			{
				process* tmp = no_erase_head;
				no_erase_head = no_erase_head->next;
				tmp->next = p;
				pre->next = tmp;
			}
		}
	}

	vector<process*> arr;
	process* p = erase_head;
	while (p != nullptr)
	{
		arr.emplace_back(p);
		p = p->next;
	}

	sort(arr.begin(), arr.end(), [](process* x, process* y)
		{
			return x->name < y->name;
		});

	print("NAME RoundTime WaitingTime\n");
	for (process* val : arr)
	{
		print("{}\t{}\t{}\n", val->name, val->round_time, val->round_time - val->cpu_time);
	}



	return 0;
}