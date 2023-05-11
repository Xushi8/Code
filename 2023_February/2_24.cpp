#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int begin, end;
    begin = clock();
    for (int i = 0; i < n; i++)
    {
        cout << n << '\n';
    }
    cout << endl;
    end = clock();
    cout << "用时: " << (end - begin) / 1000.0 << endl;
    ofstream ofs;
    ofs.open("print.out", ios::out);
    begin = clock();
    for (int i = 0; i < n; i++)
    {
        ofs << n << '\n';
    }
    ofs << endl;
    end = clock();
    cout << "用时: " << (end - begin) / 1000.0 << endl;
    ofs.close();

    system("pause");
    return 0;
}