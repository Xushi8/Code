#include <bits/stdc++.h>
using namespace std;

const int max_num = (int)1e7;
const int max_s = 60 * 1024 * 1024;
int numbers[max_num];
char buf[max_s];

void read()
{
    int len = (int)fread(buf, 1, max_s, stdin);
    buf[len] = '\0';
    int i = 0;
    numbers[0] = 0;
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

    read();

    cout << flush;

    return 0;
}