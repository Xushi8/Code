// // #include <iostream>
// // #include <algorithm>
// // #include <utility>
// // #include <format>
// // #include <memory>
// // #include <vector>
// // #include <cstring>
// // using namespace std;

// // int add(int a, int b)
// // {
// //     return a + b;
// // }

// // void func1(vector<int>& arr, int n)
// // {
// //     int* a = arr.data();
// //     a = std::assume_aligned<16>(a);
// //     n = n / 16 * 16;
// // #pragma omp simd
// //     for (int i = 0; i < n; i++)
// //     {
// //         a[i] = 0;
// //     }
// // }

// // void func2(int* a)
// // {
// //     memset(a, 0, 1024 * 4);
// // }

// // int main() {
// //     // int sum = add(1, 2);
// //     // std::cout << sum << std::endl;
// //     // std::cout << std::format("{} {} {}", 34, 234, 234432) << '\n';

// //     // cout << (make_pair(1, 5) > make_pair(1, (int)1e9 + 5) ? "YES\n" : "NO\n");

// //     return 0;
// // }


// #include <iostream>
// #include <memory>
// #include <queue>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>
// using namespace std;

// static size_t	s_my_int_count = 0;
// const  int		MAX_LOOP_ = 3000000;

// const int      NORMAL_FLAG = 0x12ff0101;
// const int	   MY_INT_FLAG = 0x12ff0102;

// void* operator new(std::size_t size)//重写new操作符为的是统计我们关心的内存分配
// {
//     int addLen = sizeof(size_t);
//     void* p = std::malloc(addLen + 4 + size);

//     if (!p)
//         throw std::bad_alloc();

//     memcpy(p, &size, addLen);//标志实际长度
//     memcpy((char*)p + addLen, &NORMAL_FLAG, 4);//标志类型，普通---0x12ff0101, 我自己的int---0x12ff0102, 我自己的char[]---0x12ff0103
//     return ((char*)p + addLen + 4);
// }

// void* operator new(std::size_t size, int flag)// 对应于调用 “new(MY_INT_FLAG) int” 这样所有我们关心的内存多可以被监视
// {
//     int addLen = sizeof(size_t);
//     void* p = std::malloc(addLen + 4 + size);

//     if (!p)
//         throw std::bad_alloc();

//     if (flag == MY_INT_FLAG) {
//         s_my_int_count++;//统计关心的内存申请次数
//     }

//     memcpy(p, &size, addLen);//标志实际长度
//     memcpy((char*)p + addLen, &flag, 4);//放置标志位，标志类型，普通---0x12ff0101, 我自己的int---0x12ff0102, 我自己的char[]---0x12ff0103
//     return ((char*)p + addLen + 4);
// }

// void operator delete(void* q) throw()
// {
//     void* p;
//     int addLen = sizeof(size_t);
//     p = (char*)q - addLen - 4;//还原原来的指针位置，p是真正的系统malloc出来的指针
//     int flag;
//     memcpy(&flag, (char*)p + addLen, 4);//得到标志位

//     if (flag == MY_INT_FLAG) {//统计关心的内存释放次数
//         s_my_int_count--;
//     }

//     if (p)
//         std::free(p);
// }

// int main() {
//     queue<int*>  intQueue;
//     int count = 0;

//     count = 0;

//     cout << "before push " << s_my_int_count << " int allocated" << endl;
//     long long  start = clock();
//     for (int i = 0; i < MAX_LOOP_; i++)
//     {
//         int* p = new(MY_INT_FLAG) int;
//         intQueue.push(p);
//     }
//     cout << "after push " << s_my_int_count << " int allocated" << endl;
//     while (!intQueue.empty()) {
//         int* p = intQueue.front();
//         intQueue.pop();
//         delete p;//注意需要手动释放
//         count++;
//     }
//     cout << "after pop " << s_my_int_count << " int allocated" << endl;
//     cout << "===================raw int ptr for " << count << ' ' << clock() - start << endl;


//     unique_ptr<int> q(new int);
//     unique_ptr<int> r = move(q);// 编译正确，r（q） 和 r = q则编译失败，因为unique_ptr已经不允许使用“拷贝构造函数”

//     queue<unique_ptr<int>> intUniQueue;//因为unique_ptr没有“拷贝构造函数”  copy-constructor
//     //所以push（）的参数不能是“左值”，左值会调用“拷贝构造函数”
//     //只能是“右值”,右值则会调用“移动构造函数” move-constructor，  
//     //std::move()函数可以强制将左值转化成为右值

//     count = 0;
//     start = clock();
//     cout << "before push " << s_my_int_count << " int allocated" << endl;
//     for (int i = 0; i < MAX_LOOP_; i++)
//     {
//         unique_ptr<int> p(new(MY_INT_FLAG) int);
//         intUniQueue.push(std::move(p));//因为p不是“右值”，所以我们需要“显式”的调用move将p强制转为右值。
//     }
//     cout << "after push " << s_my_int_count << " int allocated" << endl;
//     while (!intUniQueue.empty()) {
//         unique_ptr<int> p = std::move(intUniQueue.front());//queue.front() 是一个左值引用，即queue.front()=2 合法。
//         intUniQueue.pop();
//         count++;
//     }
//     cout << "after pop " << s_my_int_count << " int allocated" << endl;
//     cout << "===================int unique  ptr for " << count << ' ' << clock() - start << endl;

//     queue<shared_ptr<int>> intSharedQueue;
//     count = 0;
//     start = clock();
//     cout << "before push " << s_my_int_count << " int allocated" << endl;
//     for (int i = 0; i < MAX_LOOP_; i++)
//     {
//         shared_ptr<int> p(new(MY_INT_FLAG) int);
//         intSharedQueue.push(p);
//     }
//     cout << "after push " << s_my_int_count << " int allocated" << endl;
//     while (!intSharedQueue.empty()) {
//         auto p = intSharedQueue.front();
//         intSharedQueue.pop();
//         count++;
//     }
//     cout << "after pop " << s_my_int_count << " int allocated" << endl;
//     cout << "===================int shared ptr for " << count << ' ' << clock() - start << endl;

//     return 0;
// }

// /*
// 智能指针省去了我们释放指针的精力，但是也需要一定的开销。unique_ptr 的开销相对于shared_ptr要小很多。
// 如果一个资源每个时刻都只要有一个支配者，我们还是优先使用unique_ptr吧，效率会高很多。
// before push 0 int allocated
// after push 3000000 int allocated
// after pop 0 int allocated
// ===================raw int ptr for 3000000      5375
// before push 0 int allocated
// after push 3000000 int allocated
// after pop 0 int allocated
// ===================int unique  ptr for 3000000  7313
// before push 0 int allocated
// after push 3000000 int allocated
// after pop 0 int allocated
// ===================int shared ptr for 3000000   11171
// 请按任意键继续. . .
// */


// 2023/09/14 20:06:51
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}