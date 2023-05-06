// 2023/05/04 14:40:45
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100000000;
int arr[SIZE + 5];
char buff[5 * SIZE + 5];

void output()
{
    ofstream ofs;
    ofs.open("read.out", ios::out | ios::binary);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < SIZE; i++)
        {
            arr[j] = rand();
        }
        ofs << arr;
    }
    
    ofs.close();
}

void input()
{
    FILE* fp = fopen("read.out", "rb");
    int len = (int)fread(buff, 1, 5 * SIZE, fp);
    int i = 0;
    arr[0] = 0;
    for (char* p = buff; *p && p - buff < len; p++)
    {
        if (*p == ' ')
            arr[++i] = 0;
        else
            arr[i] = arr[i] * 10 + *p - '0';
    }
    
}

int main()
{
    output();

    cout << endl;
    return 0;
}