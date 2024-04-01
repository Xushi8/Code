#include <memory>
#include <iostream>
#include <vector>
#include <mutex>
#include <shared_mutex>
using namespace std;

constexpr size_t N = 1e8;

int main()
{
	int* p = new int[N];

	uninitialized_value_construct_n(p, N);
	uninitialized_default_construct_n(p, N);

	vector<int> a(1000, 0x3f3f3f3f);
	a.erase(a.begin(), a.end());

	pair<int, int> b;

	std::shared_mutex s;
	shared_lock lock1(s);
	std::mutex t[3];
	// std::lock(s, t[0], t[1], t[2]);
	// s.unlock();
	// t[0].unlock();
	// t[1].unlock();
	// t[2].unlock();

	std::scoped_lock lock(t[0], t[1], t[2]);

	return 0;
}