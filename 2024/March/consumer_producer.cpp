#include <fmt/core.h>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <cstddef>
#include <atomic>
#include <vector>

namespace thread_test
{
using fmt::print;
using fmt::format;
using std::jthread;
using std::mutex;
using std::queue;
using std::condition_variable;
using std::scoped_lock;
using std::unique_lock;
using std::vector;

constexpr size_t max_size = 100;
constexpr size_t produce_num = 100000;
size_t thread_num;
std::atomic<size_t> over_thread_num = 0;
queue<size_t> container;
bool over = false;
condition_variable cv_producer, cv_consumer;
mutex mtx;

void producer(size_t id)
{
	for (size_t i = 0; i < produce_num; i++)
	{
		size_t container_size;
		{
			unique_lock<mutex> lock(mtx);
			cv_producer.wait(lock, [&]()
				{
					return container.size() < max_size;
				});
			container.emplace(i);
			container_size = container.size();
		}
		cv_consumer.notify_one();
		print("Thread {:<3} push {:<6}; Container size: {:<3}\n", id, i, container_size);
		if (container_size > max_size)
		{
			throw std::runtime_error("Container overflow!!!");
		}
	}

	if (++over_thread_num == thread_num)
	{
		print("Produce over.\n");
		over = true;
		cv_consumer.notify_all();
	}
}

void consumer(size_t id)
{
	while (1)
	{
		size_t gift;
		size_t container_size;
		{
			unique_lock<mutex> lock(mtx);
			cv_consumer.wait(lock, [&]()
				{
					return !container.empty() || over;
				});
			if (container.empty())
				break;
			gift = container.front();
			container.pop();
			container_size = container.size();
		}
		cv_producer.notify_one();
		print("Thread {:<3} get  {:<6}; Container size: {:<3}\n", id, gift, container_size);
		if (container_size > max_size)
		{
			throw std::runtime_error("Container overflow!!!");
		}
	}
}

void test()
{
	thread_num = std::thread::hardware_concurrency();
	vector<jthread> producers, consumers;
	for (size_t i = 0; i < thread_num; i++)
	{
		producers.emplace_back(producer, i);
		consumers.emplace_back(consumer, i);
	}
}
} // namespace thread_test

int main()
{
	thread_test::test();

	return 0;
}