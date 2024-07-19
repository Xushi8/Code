#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

int main()
{
	std::vector<int> arr{10, 2, 10, 2};
	auto it = std::max_element(arr.begin(), arr.end());
	int val = *it;
	// arr.erase(std::remove(arr.begin(), arr.end(), *it), arr.end());
	// arr.erase(std::remove(arr.begin(), arr.end(), val), arr.end());
	arr.erase(std::remove(arr.begin(), arr.end(), std::decay_t<decltype(*it)>(*it)), arr.end());
	for (auto x : arr)
	{
		std::cout << x << ' ';
    }
}