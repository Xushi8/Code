#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tt = 8;
    int sum = 0;
    while (tt--)
    {
        int tmp;
        scanf("%d", &tmp);
        if (!(tmp & 1))
        {
            sum += tmp;
        }
    }
    printf("%d", sum);

    system("pause");
    return 0;
}