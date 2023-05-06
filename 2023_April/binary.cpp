// 2023:04:16 20:30:50
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ofstream ofs1, ofs2;
    ofs1.open("binary1.out", ios::out);
    ofs2.open("binary2.out", ios::out | ios::binary);
    int begin = clock();
    for (double i = 1.0; i < 3824531.12721; i += 1.0)
    {
        ofs1 << i << ' ';
    }
    int end = clock();
    cout << (end - begin) / 1000.0 << endl;
    begin = clock();
    for (double i = 1.0; i < 3824261.12721; i += 1.0)
        ofs2 << i << ' ';
    end = clock();
    cout << (end - begin) / 1000.0 << endl;

    ofs1.close();
    ofs2.close();
    
    cout << flush;
    system("pause");
    return 0;
}