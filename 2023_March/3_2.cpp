#include "3_2.h"
using namespace std;

ostream& operator << (ostream& out, Person& p)
{
    cout << "姓名: " << p.name << " 年龄: " << p.age;
    return out;
}

istream& operator >> (istream& in, Person& p)
{
    cin >> p.name >> p.age;
    return in;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Person p1, p2;
    p1.age = 23;
    strcpy(p1.name, "sfdds");
    cout << p1 << endl;
    cin >> p2;
    cout << p2 << endl; 

    system("pause");
    return 0;
}