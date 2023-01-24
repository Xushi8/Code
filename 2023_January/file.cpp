#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    cout << "Hello world" << endl;
    int a  = 19;
    const char* str  = "1243534221";
    a = atoi(str);
    cout << a << endl;
    a = 10;
    string str1;
    str1 = to_string(a);
    a = 5;
    str = "65567869";
    cout << a << endl;

    return 0;
}