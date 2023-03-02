#include<bits/stdc++.h>
using std::ostream;
using std::istream;


const int MAX_NAME = 30;

class Person
{
public:
    int age;
    
    char name[MAX_NAME];
};

ostream& operator << (ostream& out, Person& p);

istream& operator >> (istream& in, Person& p);