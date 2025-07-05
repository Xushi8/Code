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