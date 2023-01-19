#include<iostream>
#include<string>
#include<algorithm>
#include<list>

using namespace std;

// bool cmp(double a, double b)
// {
//     return a > b;
// }

// int main()
// {
//     double arr[10];
//     for (int i = 0; i < 10; i++)
//     {
//         arr[i] = rand() % 100 + 3.6;
//     }

//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << ' ';
//     }
//     cout << endl;

//     sort(arr, arr + 10, cmp);
    
//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << ' ';
//     }
//     cout << endl;

//     return 0;
// }

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    string name;
    int age;
    int height;//单位: 厘米
};

void print_person(list<Person>& person)
{
    for (list<Person>::iterator it = person.begin(); it != person.end();it++)
    {
        cout << "姓名: " << it->name << " 年龄: " << it->age << " 身高: " << it->height << '\n';
    }
    cout << '\n';
}

bool cmp(Person& a, Person& b)
{
    // if (a.age == b.age)
    // {
    //     return a.height < b.height;
    // }
    // else
    // {
    //     return a.age < b.age;
    // }

    return a.age == b.age ? a.height < b.height : a.age < b.age;
}

int main()
{
    Person p1("张飞", 33, 180);
    Person p2("关羽", 39, 190);
    Person p3("刘备", 33, 182);
    Person p4("曹操", 32, 170);
    Person p5("赵云", 15, 176);
    Person p6("孙权", 33, 176);
    list<Person> person;
    person.push_back(p1);
    person.push_back(p2);
    person.push_back(p3);
    person.push_back(p4);
    person.push_back(p5);
    person.push_back(p6);
    print_person(person);

    //按年龄升序
    person.sort(cmp);

    print_person(person);
    

    return 0;
}