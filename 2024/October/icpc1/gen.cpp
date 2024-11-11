#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> uni(0);
    constexpr size_t n = 2e5;
    ofstream ofs("in.txt");
    ofs << 1 << '\n';
    ofs << n << '\n';
    for(size_t i = 0; i < n; i++) {
        ofs << uni(rng) << ' ';
    }
}