// 2023/06/20 12:18:07
#include <iostream>
using namespace std;

long long dp[100000];

long long fib(size_t num)
{
    if (num <= 2)
        return 1;
    else if (dp[num] != 0)
        return dp[num];
    else
        return dp[num] =  fib(num - 1) + fib(num - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char32_t i = 4147483648;
    
    const char str[] = "你好";
    cout << i << '\n';
    cout << str << '\n';
    cout << fib(40000) << '\n';

    cout << flush;
    return 0;
}