// 2023:04:16 20:42:48
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ifstream ifs1, ifs2;
    ifs1.open("binary1.out", ios::in);
    ifs2.open("binary2.out", ios::in | ios::binary);
    double a, b;
    // ifs1 >> a;
    // ifs2 >> b;
    // cout << a << endl;
    // cout << b << endl;
    // cout << 2983123.787 << endl;

    int begin = clock();
    while (ifs1 >> a)
    {
        cout << a << '\n';
    }
    int end = clock();
    cout << (end - begin) / 1000.0 << endl;
    begin = clock();
    while (ifs2 >> b)
    {
        cout << b << '\n';
    }
    end = clock();
    cout << (end - begin) / 1000.0 << endl;
    ifs1.close();
    ifs2.close();

    cout << flush;
    system("pause");
    return 0;
}