#include <condition_variable>
#include <fmt/format.h>
#include <mutex>
#include <queue>
#include <tbb/parallel_for.h>
#include <tbb/parallel_for_each.h>
#include <tbb/tick_count.h>
#include <thread>
using namespace std;

mutex mtx;
condition_variable cv;
bool finish;
queue<int> que;

void producer()
{
	finish = false;
	for (size_t i = 0; i < 1000; i++)
	{
		lock_guard<mutex> lg(mtx);
		que.emplace(i);
		cv.notify_one();
	}
	finish = true;
	cv.notify_all();
}

void consumer(int id)
{
	while (1)
	{
		int gift;
		unique_lock<mutex> lg(mtx);
		cv.wait(lg, []()
			{
				return !que.empty() || finish;
			});
		if (que.empty())
		{
			break;
		}

		gift = que.front();
		que.pop();
		lg.unlock();
		fmt::print("{:<2} get gift {:<4}\n", id, gift);
	}
}

int main()
{
	thread t(producer);

	vector<thread> thread_pool;
	for (int i = 0; i < 16; i++)
	{
		thread_pool.emplace_back(consumer, i);
	}

	t.join();
	for (auto& x : thread_pool)
	{
		x.join();
	}

	constexpr size_t n = 1000;
	vector<double> a(n);

	tbb::parallel_for(tbb::blocked_range<size_t>(0, n), [&](tbb::blocked_range<size_t> r)
		{
			for (size_t i = r.begin(); i != r.end(); i++)
			{
				a[i] = sin(a[i]);
			}
		});

	tbb::parallel_for_each(a.begin(), a.end(), [](double& x)
		{
			x = sin(x);
		});

	vector<vector<double>> b(n, vector<double>(n));

	tbb::parallel_for_each(b.begin(), b.end(), [](vector<double>& c)
		{
			tbb::parallel_for_each(c.begin(), c.end(), [](double& x)
				{
					x = sin(x);
				});
		});

	auto begin = tbb::tick_count::now();
	auto end = tbb::tick_count::now();
	fmt::print("Time elapsed: {}s\n", (end - begin).seconds());

	return 0;
}
