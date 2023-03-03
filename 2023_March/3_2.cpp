#include<bits/stdc++.h>
using std::ostream;
using std::istream;


const int MAX_NAME = 30;

class Person
{
public:

    friend ostream& operator<< (ostream& out, Person p);

    Person operator ++ (int)
    {
        Person tmp = *this;
        age++;
        return tmp;
    }

    Person& operator ++ ()
    {
        age++;
        return *this;
    }

    int age;



    char name[MAX_NAME];
};

istream& operator >> (istream& in, Person& p);
using namespace std;

ostream& operator << (ostream& out, Person p)
{
    cout << "姓名: " << p.name << " 年龄: " << p.age;
    return out;
}

istream& operator >> (istream& in, Person p)
{
    cin >> p.name >> p.age;
    return in;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Person p1;
    p1.age = 6;
    strcpy(p1.name, "dfdsffd");
    int begin, end;
    begin = clock();
    for (int i = 0; i < 1000000; i++)
        cout << ++p1 << '\n';
    end = clock();
    cout << (end - begin) / 1000.0 << endl;
    system("pause");
    begin = clock();
    for (int i = 0; i < 1000000; i++)
    cout << p1++ << '\n';
    end = clock();
    cout << (end - begin) / 1000.0;
    cout << endl;


    system("pause");
    return 0;
}