#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60 * 1024 * 1024;

const int MAXN = 10000000;

int numbers[MAXN];
char buf[MAXS];
void analyse(char* buf, int len = MAXS)
{
    int i;
    numbers[i = 0] = 0;
    for (char* p = buf;*p && p - buf < len;p++)
        if (*p == ' ')
            numbers[++i] = 0;
        else
            numbers[i] = numbers[i] * 10 + *p - '0';
}

void fread_analyse()
{
    freopen("data.out", "rb", stdin);
    int len = (int)fread(buf, 1, MAXS, stdin);
    buf[len] = '\0';
    analyse(buf, len);
}

inline int read()
{
    int x = 0, f = 1;
    int ch;
    while ((ch = cin.get()) > '9' || ch < '0')
    {
        if (ch == '-') f = -1;
    }
    if (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
    }
    while ((ch = cin.get()) >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
    }
    return x * f;
}

void my_read()
{
    freopen("data.out", "rb", stdin);
    for (int i = 0; i < 10000000; i++)
    {
        numbers[i] = read();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int begin = clock();
    fread_analyse();
    // my_read();
    int end = clock();
    cout << (double)(end - begin) / 1000.0 << '\n';


    cout << flush;
    system("pause");
    return 0;
}