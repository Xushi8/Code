// // 2023/07/16 11:03:53
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// #include <bitset>
// #include <fstream>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

// ofstream ofs;


// bool is_power_of_two1(uint64_t n)
// {
//     if (n == 0)
//         return false;

//     n &= n - 1;
//     if (n)
//         return false;
//     return true;
// }

// void test1()
// {
//     for (uint64_t i = 0; i < 10000000; i++)
//     {
//         ofs << i << ' ' << is_power_of_two1(i) << '\n';
//     }
// }

// bool is_power_of_two2(uint64_t n)
// {
//     return (n != 0) && ((n & -n) == n);
// }

// void test2()
// {
//     for (uint64_t i = 0; i < 10000000; i++)
//     {
//         ofs << i << ' ' << is_power_of_two2(i) << '\n';
//     }
// }

// bool is_power_of_two3(uint64_t n)
// {
//     return __builtin_popcountll(n) == 1;
// }

// void test3()
// {
//     for (uint64_t i = 0; i < 10000000; i++)
//     {
//         ofs << i << ' ' << is_power_of_two3(i) << '\n';
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     ofs.open("test.data");

//     time_t begin = clock();

//     test1();
//     // test2();
//     // test3();

//     time_t end = clock();

//     cout << (double)(end - begin) / CLOCKS_PER_SEC << '\n';


//     cout << endl;
//     return 0;
// }


// 2023/07/30 22:13:10
#ifndef DEBUG
#pragma GCC optimize(2)
#endif
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;


constexpr ll fibonacci(const ll n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fibonacci(50) << '\n';
    
    cout << endl;
    return 0;
}