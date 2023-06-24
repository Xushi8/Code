// 2023/06/24 16:30:42
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = (ll)(1e9 + 7);
const int N = 100005;

class Noncopyable {
public:
    Noncopyable(int i_) : i(i_) {
        cout << "构造" << endl;
    }
    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator= (const Noncopyable&) = delete;
    int i;
};

Noncopyable func() {
    return { 10 };
}

int main() {
    auto a = func();
}