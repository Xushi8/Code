// 2023/04/28 11:01:23
#include <bits/stdc++.h>
using namespace std;

class Stu
{
public:
    void shwo_a();
    Stu(const Stu& s)
    {
        cout << "kaobei" << endl;
        _a = s._a;
        _b = s._b;
    }

    Stu& operator=(const Stu& s)
    {
        cout << "=haochongzai" << endl;
        _a = s._a;
        _b = s._b;
        return *this;
    }

    Stu()
    {

    }
    Stu(int a, char b)
    {
        _a = a;
        _b = b;
    }
    int _a;
    char _b;
};

void Stu::shwo_a()
{
    cout << this->_a << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Stu a(3, '4');
    Stu b(a);
    Stu c = a;

    cout << endl;
    return 0;
}