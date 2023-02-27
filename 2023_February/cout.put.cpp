#include<bits/stdc++.h>
using namespace std;

int tt = 100000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int begin = clock();
    while (tt--)
    {
        cout.put('a');
        //cout << "d\n";
        cout.put('d');
        //cout.put('\n');
    }
    int end = clock();
    cout << '\n' << (end - begin) / 1000.0 << endl;

    system("pause");
    return 0;
}