#include<iostream>
#include<fstream>
using namespace std;

ofstream ofs;

void move(int n, char a, char b, char c)//中间的是工具, 最后的是dest
{
    if (n == 0) return;
    
    move(n - 1, a, c, b);
    ofs << a << "->" << c << '\n';
    move(n - 1, b, a, c);
}

int main()
{
    ofs.open("hannuota.out", ios::out);
    int n;
    cin >> n;
    char a, b, c;
    a = 'A', b = 'B', c = 'C';
    move(n, a, b, c);
    ofs.close();

    return 0;
}