#include<bits/stdc++.h>
using namespace std;
#include<conio.h>
int n, m;


template<typename T>
void my_swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char arr[10] = "12345";
    reverse(arr, arr + 5);
    cout << arr << endl;
    int a = 10;
    int b = 14;
    cout << a << ' ' << b << endl;
    my_swap(a, b);
    cout << a << ' ' << b << endl;
    double c = 9.9;
    double d = 1.1;
    cout << c << ' ' << d << endl;
    my_swap(c, d);
    cout << c << ' ' << d << endl;
    cout << "发热剂" << endl;

    int begin = clock();
    long long tmp = 1;
    for (int i = 0; i < 100000000; i++)
    {
        tmp *= 2;
        if (tmp > (long long)2e63) tmp = 1;
    }
    int end = clock();
    cout << (double)(end - begin) / 1000.0 << endl;
    begin = clock();
    tmp = 1;
    for (int i = 0; i < 100000000; i++)
    {
        tmp <<= 1;
    }
    end = clock();
    cout << (double)(end - begin) / 1000.0 << endl;


    getch();
    //system("pause");
    return 0;
}