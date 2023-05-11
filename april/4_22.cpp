#include <bits/stdc++.h>
using namespace std;

inline __int128_t read() {
    __int128_t x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128_t x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main(void) {
    __int128_t a = read();
    __int128_t b = read();
    print(a + b);
    cout << endl;
    cout << sizeof(__int128_t) << endl;
    return 0;
}