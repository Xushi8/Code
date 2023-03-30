#include <stdio.h>
#include <stdlib.h>
int ans[10000];

inline int read()
{
    int x = 0;
    int f = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch = '-') f = -1;
    }
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
    }
    return x * f;
}

int main()
{
    int n, m;
    scanf("%d,%d", &m, &n);
    if (m <= 0 || m > 9999 || n <= 0 || n > 9999)
    {
        printf("error");
        return 0;
    }
    
    if (m > n)
    {
        int tmp = n;
        n = m;
        m = tmp;
    }

    int tot = 0;
    for (int i = m; i <= n; i++)
    {
        int sum = i;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0) sum += j;
        }
        if (sum == 2 * i) ans[tot++] = i;
    }

    if (tot != 0)
    {
        for (int i = 0; i < tot; i++)
        {
            printf("%d,", ans[i]);
        }
    }
    else
    {
        printf("error");
    }


    system("pause");
    return 0;
}