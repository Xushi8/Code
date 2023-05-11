#include<bits/stdc++.h>
using namespace std;

int** func(int* a)
{
    return &a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    stack<uint64_t> s;
    cout << UINT64_MAX << endl;

    int a = 10;
    
    int** b = func(&a);
    int* p1 = &a;
    int** p2 = &p1;
    cout << p2 << endl << b << endl;

    system("pause");
    return 0;
}