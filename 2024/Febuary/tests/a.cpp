#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>
#include <random>
using namespace std;

int main() {
	size_t n;
	cin >> n;
	vector<int> a(n);
	random_device rd;
	mt19937 rng(rd());
	std::generate(std::execution::par_unseq, a.begin(), a.end(), rng);
	cout << *std::max_element(std::execution::par_unseq, a.begin(), a.end()) << endl;
    // std::ranges::generate(a, rng);
    // cout << *std::ranges::max_element(a) << endl;

    return 0;
}
