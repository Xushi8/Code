#include<bits/stdc++.h>
using std::string;

class Person
{
public:
    Person();
    Person(const Person& p);
    Person(const int& age, const string& name);
    ~Person();

    void show_person();

    int age;
    string name;
};