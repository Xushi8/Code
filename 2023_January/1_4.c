#include<stdio.h>
#include<stdlib.h>
#include<string.h>

func(int a, int b)
{
    return ((b - a + 1) * (a + b))/2;
}
int main()
{
    int i, j, k;
    int m;
    int ret = func(297, 328);
    scanf("%d", &m);
    for (i = 1; i < m; i++)
    {
        for (j = i + 1; j < m; j += 10)
        {
            if ((ret = func(i, j)) < m)
            {
                continue;
            }
            else
            {
                j -= 10;
                break;
            }
        }

        for (k = j; k < m; k++)
        {
            if ((ret = func(i, k)) == m)
            {
                printf("%d %d\n", i, k);
                break;
            }
            else if ((ret = func(i, k)) > m)
            {
                break;
            }
        }
    }

    return 0;
}