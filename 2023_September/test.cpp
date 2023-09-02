#include <iostream>
#include <algorithm>
#include <utility>
#include <format>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    // int sum = add(1, 2);
    // std::cout << sum << std::endl;
    // std::cout << std::format("{} {} {}", 34, 234, 234432) << '\n';

    cout << (make_pair(1, 5) > make_pair(1, (int)1e9 + 5) ? "YES\n" : "NO\n");

    return 0;
}
