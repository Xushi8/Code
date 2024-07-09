#include <pthread.h>
#include <thread>
#include <vector>
#include <random>
#include <fmt/format.h>
using fmt::print;

pthread_mutex_t adaptive_mutex;

constexpr static size_t N = 1000000;
std::vector<size_t> vec;

int main()
{
	// pthread_mutexattr_t attr;
	// pthread_mutexattr_init(&attr);
	// pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ADAPTIVE_NP);
	// pthread_mutex_init(&adaptive_mutex, &attr);
	// pthread_mutexattr_destroy(&attr);

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<size_t> uni(0, SIZE_MAX);

	std::vector<std::thread> threads;
	vec.reserve(12 * N);
	for (size_t thread_num = 0; thread_num < 12; ++thread_num)
	{
		threads.emplace_back([&]()
			{
				for (size_t i = 0; i < N; ++i)
				{
					pthread_mutex_lock(&adaptive_mutex);
					vec.emplace_back(uni(rng));
					pthread_mutex_unlock(&adaptive_mutex);
					using namespace std::chrono_literals;
				}
			});
	}

	for (auto& t : threads)
	{
		t.join();
	}

	pthread_mutex_destroy(&adaptive_mutex);

	for (size_t i = 0; i < N; i += N / 3)
	{
		print("{}\n", vec[i]);
    }

	return 0;
}
