#include "2_18.h"
using namespace std;

Person::Person()
{
    this->age = 0;
    this->name = '\0';
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
Person::Person(const string& name_, const int& age_)
{
    this->name = name_;
    this->age = age_;
}

void show_vector_person(const vector<Person>& p)
{
    for (vector<Person>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << "年龄: " << it->age << " 姓名: " << it->name << '\n';
    }
    cout << endl;
}

void show_list_person(const list<Person>& p)
{
    for (list<Person>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << "年龄: " << it->age << " 姓名: " << it->name << '\n';
    }
    cout << endl;
}

bool cmp_person(const Person& p1, const Person& p2)
{
    return p1.age < p2.age;
}

int main()
{
    // Person p1(10, "张三");
    // Person p2(40, "私立");
    // Person p3(23, "李四");
    // Person p4(22, "王五");
    // Person p5(28, "张柳");
    // Person p6(11, "李琦");
    // vector<Person> person;
    // person.push_back(p1);
    // person.push_back(p2);
    // person.push_back(p3);
    // person.push_back(p4);
    // person.push_back(p5);
    // person.push_back(p6);
    // show_vector_person(person);
    // sort(person.begin(), person.end(), cmp_person);
    // show_vector_person(person);
    
    // list<Person> tmp;
    // tmp.push_back(p1);
    // tmp.push_back(p2);
    // tmp.push_back(p3);
    // tmp.push_back(p4);
    // tmp.push_back(p5);
    // tmp.push_back(p6);

    // show_list_person(tmp);
    // tmp.sort(cmp_person);
    // show_list_person(tmp);

    // ofstream ofs;
    // ofs.open("size_t.out", ios::out);
    // if (!ofs.is_open())
    // {
    //     perror("ofs");
    //     return 1;
    // }
    
    // cout << sizeof(size_t) << endl;
    // for (size_t i = 0; i < LLONG_MAX; i+=100000000000000)
    // {
    //     ofs << i << '\n';
    // }
    // ofs.close();

    __uint128_t tmp;
    scanf("%i128u", &tmp);
    printf("%i128u", tmp);

    return 0;
}