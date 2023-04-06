#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ofstream ofs;
    ofs.open("data.in", ios::out);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10000000; i++)
    {
        ofs << rand() * 9997 << ' ';
    }
    ofs.close();

    cout << flush;
    system("pause");
    return 0;
}