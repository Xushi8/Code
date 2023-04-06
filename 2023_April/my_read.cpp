#include <bits/stdc++.h>
using namespace std;

const int max_n = 10000000;
const int max_s = 60 * 1024 * 1024;
char buf[max_s];
int numbers[max_n];

void read()
{
    int len = (int)fread(buf, 1, max_s, stdin);
    buf[len] = '\0';
    int i;
    numbers[i = 0] = 0;
    for (char* p = buf; *p && p - buf < len; p++)
    {
        if (*p == ' ')
            numbers[++i] = 0;
        else
            numbers[i] = numbers[i] * 10 + *p - '0';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("data.in", "rb", stdin);
    int begin = clock();
    read();
    int end = clock();
    cout << (double)(end - begin) / 1000.0;

    cout << flush;
    system("pause");
    return 0;
}