#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// bool cmp(int a, int b)
// {
//     return a > b;
// }

// class Person
// {
// public:
//     bool my_compare(int a, int b)
//     {
//         return a > b;
//     }
// };

// int main()
// {
//     vector<int> v;
//     v.push_back(33);
//     v.push_back(34);
//     v.push_back(18);
//     v.push_back(54);

//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;

//     sort(v.begin(), v.end(), cmp);

//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;

//     return 0;
// }

// int main()
// {
//     bool a = 1;
//     bool b = -3;
//     cout << b - 5;
//     b -= 5;
//     cout << b - 5;


//     return 0;
// }


class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

// int main()
// {
//     vector<Person> v;
//     v.push_back(Person("zhangsan", 88));
//     v.push_back(Person("李四", 45));

//     for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << "姓名: " << it->name << " 年龄: " << it->age << endl;
//     }

//     return 0;
// }