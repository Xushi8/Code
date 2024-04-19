#include <iostream>
#include <fstream>
#include <format>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string_view>

namespace schedule_test
{
using std::ifstream;
using std::cout;
using std::format;
using std::sort;
using std::string;
using std::vector;
using std::string_view;

struct process
{
	process() = default;
	process(process const&) = delete;
	process& operator=(process const&) = delete;
	process(process&&) noexcept = default;
	process& operator=(process&&) noexcept = default;

	size_t pid;
	process* next;
	uint32_t need_time;
	int32_t priority;
	uint32_t cpu_time;
	uint32_t finish_time;
	char status;
};

void print_process(process* head, size_t round)
{
	vector<process*> vec;
	process* p = head;
	while (p != nullptr)
	{
		vec.emplace_back(p);
		p = p->next;
	}

	sort(vec.begin(), vec.end(), [](process* x, process* y)
		{
			return x->pid < y->pid;
		});

	cout << format("CPUTIME:{}\n", round);
	for (auto ptr : vec)
	{
		cout << format("P{}\t{}\t{}\t{}\t", ptr->pid, ptr->cpu_time, ptr->need_time, ptr->priority);
		if (ptr->status == 'R')
			cout << "ready\n";
		else if (ptr->status == 'W')
			cout << "working\n";
		else
			cout << "finish\n";
	}
	cout << '\n';
}

void delete_process(process* head)
{
	process* now = head;
	while (now != nullptr)
	{
		process* tmp = now;
		now = now->next;
		delete tmp;
    }
}

void run()
{
	// 输入
	ifstream ifs("process.in");
	process* head = new process{};
	char ch;
	ifs >> ch >> head->pid >> head->need_time >> head->priority;
	head->status = 'R';
	for (size_t i = 1; i < 5; i++)
	{
		process* tmp = new process{};
		ifs >> ch >> tmp->pid >> tmp->need_time >> tmp->priority;
		tmp->status = 'R';

		process* p = head;
		process* pre = nullptr;
		while (p->next != nullptr && tmp->priority <= p->priority)
		{
			pre = p;
			p = p->next;;
		}

		if (tmp->priority > p->priority)
		{
			if (pre == nullptr) // 比头结点优先级还高
			{
				tmp->next = head;
				head = tmp;
			}
			else
			{
				tmp->next = p;
				pre->next = tmp;
            }
		}
		else
		{
			p->next = tmp;
        }
	}

	size_t round = 0;
	print_process(head, round++);

	while (head->status != 'F')
	{
		head->priority--;
		head->cpu_time++;
		head->need_time--;
		head->status = 'W';
		if (head->need_time == 0) // 已结束, 将其放到末尾
		{
			head->status = 'F';
			head->finish_time = round;
			process* tmp = head;
			head = head->next;
			process* p = head;
			while (p->next != nullptr)
				p = p->next;
			p->next = tmp;
		}

		print_process(head, round++);
		if (head->status != 'F')
			head->status = 'R';
		
		if (head->next->status != 'F' && head->priority < head->next->priority) // 更新后头结点优先级小于第二的, 更新
		{
			process* tmp = head;
			head = head->next;
			process* p = head;
			while (p->next != nullptr && p->next->status != 'F' && p->next->priority > tmp->priority)
				p = p->next;
			tmp->next = p->next;
			p->next = tmp;
		}

    }


	delete_process(head);
}

} // namespace schedule_test

int main()
{
	schedule_test::run();
	return 0;
}