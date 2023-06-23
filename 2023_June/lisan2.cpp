#include <iostream>
const int inf = 0x3f3f3f3f; // 无穷, 表示不可知
inline int func();

int main() {
    ::std::ios::sync_with_stdio(false);
    ::std::cin.tie(0);

    ::std::cout << func() << '\n';

    ::std::cout << ::std::flush;
    return 0;
}

inline int func() {
    int p, q, r, s;
    r = 0;
    p = q = s = inf;
    int cnt = 0;
    while (p == inf) {
        if (cnt++ == 4) {
            return inf;
        }
        if (q != inf) { // 这里忽略了p != inf 
            p = 1;
            if ((!p | !q) != 1) {
                p = 0;
            }
            ::std::cout << "公式: !p | !q. \tq -> p, p: " << p << '\n';
        }
        if (s != inf && r == inf)
        {
            r = 1;
            if (((!s) | r) != 1)
            {
                r = 0;
            }
            ::std::cout << "公式: !s | r. \ts -> r, r: " << r << '\n';
        }
        if (r != inf && s == inf)
        {
            s = 1;
            if (((!s) | r) != 1)
            {
                s = 0;
            }
            ::std::cout << "公式: !s | r. \tr -> s, s: " << s << '\n';
        }
        if (s != inf && q == inf) {
            q = 1;
            if ((s | q) != 1) {
                q = 0;
            }
            ::std::cout << "公式:  s |  q. \ts -> q, q: " << q << '\n';
        }
        if (q != inf && s == inf) {
            s = 1;
            if ((s | q) != 1) {
                s = 0;
            }
            ::std::cout << "公式:  s |  q. \tq -> s, s: " << s << '\n';
        }
    }
    return p;
}



