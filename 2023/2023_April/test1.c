#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }

    system("pause");
    return 0;
}