#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char *s_gets(char * st, int n)
{
    char* ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
            i++;
        }
        
        if (st[i] == '\n')
        {
            st[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}
struct books
{
    char name[20];
    char author[20];
    double price;
};
int main()
{
    struct books book[10];
    int count = 0;
    int index,filecount;
    FILE* fp = fopen("data.d", "a+b");
    int size = sizeof(struct books);
    rewind(fp);
    while(count<10 && fread(&book, size, 1, fp) == 1)
    {
        if(count == 0)
        {
            puts("当前的书:");
        }
        printf("%-s\t%-s\t%.2lf\n",book[count].name, book[count].author, book[count].price);
        count++;
    }

    filecount = count;
    if(count == 10)
    {
        puts("文件已满");
        return 0;
    }

    puts("请输入书名");
    while(count<10 && s_gets(book[count].name, 20) !=  NULL && book[count].name[0] != '\0')
    {
        puts("请输入作者");
        s_gets(book[count].author, 20);
        puts("请输入价格");
        scanf("%lf", &book[count].price);
        count++;
        while(getchar() != '\n')
        {
            continue;
        }
        if(count<10)
        {
            puts("请输入下一本书的书名");
        }
    }

    if(count>0)
    {
        puts("下面是书籍名单");
        for(index=0; index<count; index++)
        {
            printf("%-s\t%-s\t%.2lf\n",book[index].name, book[index].author, book[index].price);
        }
        fwrite(&book[filecount], size, count-filecount, fp);
    }
    else
    {
        puts("没有书");
    }
    fclose(fp);

    return 0;
}


