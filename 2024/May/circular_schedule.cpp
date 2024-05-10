#include <string>
#include <cstddef>
#include <fstream>
#include <vector>
#include <fmt/format.h>
#include <algorithm>

using std::string;
using std::ifstream;
using std::vector;
using fmt::print;
using std::sort;

struct process
{
	string name;
	process* next = nullptr;
	size_t require_time;
	size_t cpu_time = 0;
	char status = 'R';
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

void print(process* no_erase_head, process* erase_head)
{
	vector<process*> arr;
	process* p;
	p = no_erase_head;
	if (p != nullptr)
	{
		while (1)
		{
			arr.emplace_back(p);
			p = p->next;
			if (p == no_erase_head)
				break;
		}
	}

	p = erase_head;
	if (p != nullptr)
	{
		while (1)
		{
			arr.emplace_back(p);
			p = p->next;
			if (p == erase_head || p == nullptr)
				break;
		}
	}

	sort(arr.begin(), arr.end(), [](process* x, process* y)
		{
			return x->name < y->name;
		});

	static size_t CPU_TIME = 0;
	print("CPU_TIME: {}. choose: {}.\n", CPU_TIME++, no_erase_head->name);
	print("NAME CPUTIME REQUIRETIME\n");
	for (process* val : arr)
	{
		print(" {}\t{}\t{}\n", val->name, val->cpu_time, val->require_time);
	}

	print("\n");
}

int main()
{
	ifstream ifs("circular_schedule.in");
	process* no_erase_head = nullptr;
	process* erase_head = nullptr;

	for (int i = 0; i < 5; i++)
	{
		process* tmp = new process;
		ifs >> tmp->name >> tmp->require_time;
		no_erase_head = push_back(no_erase_head, tmp);

		if (i == 5 - 1)
		{
			tmp->next = no_erase_head;
		}
	}

	while (1)
	{
		no_erase_head->cpu_time++;
		print(no_erase_head, erase_head);
		if (no_erase_head->cpu_time == no_erase_head->require_time)
		{
			if (no_erase_head->next == no_erase_head)
			{
				no_erase_head = nullptr;
				break;
			}

			process* tmp = no_erase_head;
			no_erase_head = no_erase_head->next;
			process* p = no_erase_head;
			while (p->next != tmp)
			{
				p = p->next;
			}
			p->next = no_erase_head;
			erase_head = push_back(erase_head, tmp);
		}
		else
		{
			no_erase_head = no_erase_head->next;
        }
	}

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

	for (process* val : arr)
	{
		delete val;
    }

	return 0;
}
