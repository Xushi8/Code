#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    ofstream ofs("in.txt");

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> uni_x(-1000000, 1000000), uni_y(0, 2);

    constexpr i64 n = 50000;
    ofs << n << '\n';
    for (i64 i = 0; i < n; i++) {
        ofs << uni_x(rng) << ' ' << uni_y(rng) << '\n';
    }

    cout << n * n * log2(n) << '\n';
}