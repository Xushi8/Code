// 2023/05/06 19:28:44
#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual void speak() const
    {
        cout << "speak" << endl;
    }
};

class Cat :public Animal
{
public:
    void speak() const
    {
        cout << "cat" << endl;
    }
};

void test(const Animal& a)
{
    a.speak();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Cat a;
    a.speak();
    test(a);

    cout << endl;
    return 0;
}