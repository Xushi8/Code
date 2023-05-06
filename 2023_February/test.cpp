#include<bits/stdc++.h>
using namespace std;


int* func()
{
    int a = 10;
    int* b = &a;
    return b;
}
int main()
{
    int* p = func();
    cout << 9 << flush;
    cout << *p << endl;

    system("pause");
    return 0;
}