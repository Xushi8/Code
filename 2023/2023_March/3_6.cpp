#include<bits/stdc++.h>
using namespace std;

template<typename T>
inline void my_swap(T& a, T& b)
{
    T tmp(a);
    a = b;
    b = tmp;
}

typedef struct User
{
    int age;
    string name;
    User* next;
}User;

ostream& operator << (ostream& out, User& u)
{
    cout << u.age << ' ' << u.name;
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // int ch;
    // ch = 1;
    // switch (ch)
    // {
    // case 1:
    //     ch = 2;
    //     break;
    // case 2:
    //     ch = 3;
    //     continue;
    // case 3:
        
    // }

    // auto i = 10;
    // printf("%lld", i);

    // int a, b;
    // cin >> a >> b;
    // my_swap(a, b);
    // cout << a << b << endl;

    User a;
    a.age = 10;
    cout << a << endl;;

    system("pause");
    return 0;
}