#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<fstream>
using std::string;

class Person
{
public:
    Person();

    Person(const Person& p);

    Person(const int& age, const string& name);

    Person(const string& name, const int& age);

    int age;
    string name;
};

bool cmp_person(const Person& p1, const Person& p2);


