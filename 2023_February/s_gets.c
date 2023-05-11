#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* s_gets(char* const src, int num)
{
    char* ret_val = fgets(src, num, stdin);
    if (ret_val == NULL)
    {
        perror("s_gets");
        return NULL;
    }
    
    int i = 0;
    while (src[i] != '\0')
    {
        if (src[i] == '\n')
        {
            src[i] = '\0';
            break;
        }
        i++;
    }
    return ret_val;
}
int main()
{
    char str[10];
    char* tmp = s_gets(str, 10);
    
    puts(str);

    system("pause");
    return 0;
}