#include<iostream>
#include<ctime>
using namespace std;

// uint64_t fib(int n)
// {
//     if (n <= 2) return 1;
//     else return fib(n - 1) + fib(n - 2);
// }
// int main()
// {
//     int begin = clock();
//     int n;
//     cin >> n;
//     uint64_t ans = fib(n);
//     int end = clock();
//     cout << ans << endl;
//     cout << (double)(end - begin) / 1000.0 << endl;
//     system("pause");

//     return 0;
// }

// uint64_t fib[500];
// uint64_t better_fib(int n)
// {
//     if (n <= 2) return 1;
//     if (fib[n] != 0) return fib[n];

//     return fib[n] = better_fib(n - 1) + better_fib(n - 2);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int begin = clock();
//     uint64_t ans = better_fib(n);
//     int end = clock();
//     cout << ans << '\n';
//     cout << (double)(end - begin) / 1000.0 << endl;

//     system("pause");
//     return 0;
// }

// void func(int n)
// {
//     func(n - 1);
// }
// int main()
// {
//     func(100);
    
//     system("pause");
//     return 0;
// }