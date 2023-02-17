#include<bits/stdc++.h>
using namespace std;


const int SIZE = 10000;
int ar[SIZE];
int main()
{
    ofstream ofs;
    ofs.open("2.17.out", ios::out | ios::binary);
    for (int i = 0; i < SIZE; i++)
    {
        ar[i] = rand();
        ofs << ar[i] << ' ';
    }
    ofs << endl;
    ofs.close();

    
    system("pause");
    return 0;
}