// 2023/05/04 15:15:37
#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 100000000;
int arr[SIZE + 5];
void output()
{
    ofstream ofs;
    ofs.open("read.out", ios::out | ios::binary);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[j] = rand() * rand();
        }
        ofs.write((char*)arr, SIZE * 4);
    }
    ofs.close();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    output();
    
    cout << flush;
    system("pause");
    return 0;
}