// 2023/06/06 21:14:40
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

unsigned long long func(unsigned long long a, unsigned long long n)
{
    return (a + n / a * a) * (n / a) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned long long n, a, b;
    cin >> n >> a >> b;
    unsigned long long sum = n * (n + 1) / 2;

    unsigned long long yue = __gcd(a, b);
    unsigned long long bei = a * b / yue;

    sum -= ::func(a, n);
    sum -= ::func(b, n);
    sum += ::func(bei, n);


    
    print_uint128(sum);

    cout << endl;
    return 0;
}