#include <condition_variable>
#include <fmt/format.h>
#include <mutex>
#include <queue>
#include <tbb/parallel_for.h>
#include <tbb/parallel_for_each.h>
#include <tbb/blocked_range2d.h>
#include <tbb/tick_count.h>
#include <tbb/blocked_range.h>
#include <thread>
using namespace std;

mutex mtx;
condition_variable cv;
bool finish;
queue<size_t> que;



void producer()
{
	finish = false;
	for (size_t i = 0; i < 10000000000; i++)
	{
		{
			lock_guard<mutex> lg(mtx);
			que.emplace(i);
		}
		cv.notify_one();
	}
	finish = true;
	cv.notify_all();
}

void consumer(unsigned int id)
{
	while (1)
	{
		size_t gift;
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
	for (unsigned int i = 0; i < std::thread::hardware_concurrency(); i++)
	{
		thread_pool.emplace_back(consumer, i);
	}

	t.join();
	for (auto& x : thread_pool)
	{
		x.join();
	}

	constexpr size_t n = 1000;
	vector<double> a(n, 3980.324);

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

	tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n), [&](tbb::blocked_range2d<size_t> const& r)
		{
			for (size_t i = 0; i < r.rows().size(); i++)
			{
				for (size_t j = 0; j < r.cols().size(); j++)
				{
					b[i][j] = sin(b[i][j]);
				}
			}
		});

	auto begin = tbb::tick_count::now();
	auto end = tbb::tick_count::now();
	fmt::print("Time elapsed: {}s\n", (end - begin).seconds());

	return 0;
}
