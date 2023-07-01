// 2023/06/03 23:56:06
#include <bits/stdc++.h>
using namespace std;

void print_uint128(__uint128_t num)
{
    if (num / 10)
    {
        print_uint128(num / 10);
    }
    cout.put((char)(num % 10 + '0'));
}

ostream& operator << (ostream& out, __uint128_t num)
{
    print_uint128(num);
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand((unsigned)time(nullptr));
    unsigned long long n = 449749848967864967;
    __uint128_t sum = 0;
    
    cout << sum << endl;
    sum = 0;
    for (unsigned long long i = 0; i < n; i++)
    {
        sum += i;
    }
    
    cout << sum << endl;

    cout << endl;
    return 0;
}