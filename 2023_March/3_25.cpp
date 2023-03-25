#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream ofs;
    ofs.open("test.out", ios::out);
    int begin = clock();
    for (int i = 0; i < SIZE; i++)
    {
        // if (rand() & 1) ofs << 1 << ' ';
        // else ofs << 0 << ' ';

        if (rand() % 2 == 1) ofs << 1 << ' ';
        else ofs << 0 << ' ';
    }
    int end = clock();
    cout << (double)(end - begin) / 1000.;
    ofs.close();

    cout << flush;
    system("pause");
    return 0;
}