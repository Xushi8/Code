#include<iostream>
#include<string>


using namespace std;

class Student
{
public:

    string name;
    int age;

    void setAge(int _age)
    {
        age = _age;
    }
};

int main()
{
    Student s;
    s.age = 10;
    cout << s.age << "\n";
    s.setAge(17);
    cout << s.age << "\n";
    cout << sizeof(s.name) << "\n";
    string s1;
    cout << sizeof(s1) << '\n';
    cout<<sizeof(s1)<<endl;
    return 0;
}