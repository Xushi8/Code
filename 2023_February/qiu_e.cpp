#include<bits/stdc++.h>
using namespace std;
int n, m;


int main()
{
    long double e = 1.0;
    int tmp = 1;
    for (int i = 2; i < 35; i++)
    {
        e += 1.0 / (double)tmp;
        tmp *= i;
        //if (1.0 / (double)tmp < 1e-18) break;
    }
    printf("%.18Lf\n", e);

    system("pause");
    return 0;
}