// 2023/08/01 12:01:34
#ifndef LOCAL
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
#include <memory>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

void print(const string& s)
{
    cout << "左值";
    cout << s << endl;
}

void print(string&& s)
{
    cout << "右值";
    cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //     print("引用");
    //     string s("引用");
    //     print(s);

    // #ifdef  __linux__
    //     cout << "YES\n";
    // #endif

    // unique_ptr<string> p1(new string("hi"));
    // unique_ptr<string> p2(p1.release()); // 将p1置为空，返回指针
    // cout << *p2 << endl;
    // unique_ptr<string> p3(new string("hello,world"));
    // p2.reset(p3.release()); // reset释放了p2原来指向的内存 然后令p2指向p3所指向的对象，然后release()将p3置为空
    // // cout << *p3 << endl; // 输出的都是hi
    // // cout << *p1 << endl; // p1已经被释放了，没有了
    // cout << *p2 << endl;


//     shared_ptr<int> p(new int(42));
//     int* q = p.get();
//     {
//         // 两个独立的shared_ptr指向相同的内存
//         shared_ptr<int>(q);
//         // 离开作用域就会释放
// }
//     int foo = *q; // 最后未定义

    auto p = new int(3);
    cout << *p << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}