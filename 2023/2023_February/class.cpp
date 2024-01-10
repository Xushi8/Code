#include "class.h"
using namespace std;




Person::Person()
{
    this->age = 0;
    
}

Person::Person(const Person& p)
{
    this->age = p.age;
    this->name = p.name;
}

Person::Person(const int& age_, const string& name_)
{
    this->age = age_;
    this->name = name_;
}

Person::~Person()
{
    
}

void Person::show_person()
{
    cout << "年龄: " << this->age << " 姓名: " << this->name << endl;
}

void test01()
{
    Person p1;
    p1.age = 10;
    p1.name = "张三";
    Person p2(p1);
    p1.show_person();
    p2.show_person();
    Person p3(30, "李四");
    p3.show_person();
}

int main()
{
    test01();
    
    system("pause");
    return 0;
}