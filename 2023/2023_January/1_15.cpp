#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


template<typename T>
void my_swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "a = " << a << " b = " << b << '\n';
    my_swap(a, b);
    cout << "a = " << a << " b = " << b << '\n';
    double c, d;
    cin >> c >> d;
    cout << "c = " << c << " d = " << d << '\n';
    my_swap(c, d);
    cout << "c = " << c << " d = " << d << '\n';

    return 0;
}