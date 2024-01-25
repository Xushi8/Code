// 2024/01/24 16:47:43
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
#include <memory>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

struct free_deleter
{
    void operator()(void* p)
    {
        free(p);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    int n = 200000;
    ofstream ofs("test.in", ios::out | ios::binary);
    ofs << t << '\n';
    ofs << n << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << rand() << ' ';
    }

    // int* p = (int*)malloc(sizeof(int));
    // unique_ptr<int, free_deleter> up(p);
    vector<unique_ptr<int>> vec;
    vec.emplace_back(make_unique<int>(5));
    vec.emplace_back(make_unique<int>(10));
    for (auto const& x : vec)
    {
        cout << *x << endl;
    }

    cout << vec.size() << endl;
    auto p = move(vec.back());
    cout << vec.size() << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}