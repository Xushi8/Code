#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

ofstream ofs;
bool b[100], c[100], d[100];
int a[100];
int n, count;

void print()
{
    count++;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if (j == a[i]) ofs << '+';
            else ofs << '-';
        }
        ofs << '\n';
    }
    ofs << '\n';
}

void dfs(int i)
{
    int j;
    for (j = 1; j <= n;j++)
    {
        if (i + j <= n && i - j >= 1)
        {
            if (b[j] && c[i + j] && d[i - j])
            {
                a[i] = j;
                b[j] = false;
                c[i + j] = false;
                d[i - j] = false;
            }
        }
        else if (i + j > n)
        {
            if (b[j] && d[i - j])
            {
                a[i] = j;
                b[j] = false;
                d[i - j] = false;
            }
        }
        else if (i - j < 1)
        {
            if (b[j] && c[i + j])
            {
                a[i] = j;
                b[j] = false;
                c[i + j] = false;
            }
        }

        if (i < n) dfs(i + 1);
        else print();

        if (i + j <= n && i - j >= 1)
        {
            if (b[j] && c[i + j] && d[i - j])
            {
                b[j] = true;
                c[i + j] = true;
                d[i - j] = true;
            }
        }
        else if (i + j > n)
        {
            if (b[j] && d[i - j])
            {
                b[j] = true;
                d[i - j] = true;
            }
        }
        else if (i - j < 1)
        {
            if (b[j] && c[i + j])
            {
                b[j] = true;
                c[i + j] = true;
            }
        }
    }
}
int main()
{
    ofs.open("queen.out", ios::out);
    memset(b, true, sizeof(b));
    memset(c, true, sizeof(c));
    memset(d, true, sizeof(d));
    cin >> n;
    dfs(1);
    ofs << count;
    ofs.close();

    return 0;
}