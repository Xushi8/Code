#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int arr[4];
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch)) arr[0]++;
        else if (isalnum(ch)) arr[1]++;
        else if (ch == ' ') arr[2]++;
        else arr[3]++;
    }

    for (int i = 0; i < 4; i++) printf("%d ", arr[i]);

    system("pause");
    return 0;
}