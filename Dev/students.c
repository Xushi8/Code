#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stu
{
    int id;
    char name[20];
    struct Stu* next;
};

void insert_stu(struct Stu* header)
{
    struct Stu* tmp = malloc(sizeof(struct Stu));
    if(tmp == NULL)
    {
        puts("�ڴ濪��ʧ��");
        return;
    }
    puts("������ѧ�ź�����");
    scanf("%d %s", &tmp->id, tmp->name);
    int ch;
    while((ch = getchar()) != '\n')
    {
        continue;
    }
    tmp->next = header->next;
    header->next = tmp;
}
void print_stu(struct Stu* header)
{
    struct Stu* p = header->next;
    while(p != NULL)
    {
        printf("%d %s\n", p->id, p->name);
        p = p->next;
    }
}

void search_stu_name(struct Stu* header)
{
    if(header->next == NULL)
    {
        puts("û��ѧ��");
        return;
    }
    struct Stu* p = header->next;
    puts("������ѧ������");
    char name[20];
    scanf("%s", name);
    int ch;
    while((ch = getchar()) != '\n')
    {
        continue;
    }
    while(p != NULL)
    {
        if(strcmp(p->name, name) == 0)
        {
            printf("�ҵ���,id��%d\n", p->id);
            return;
        }

        p = p->next;
    }
    puts("û�ҵ�");
}

void search_stu_id(struct Stu* header)
{

    if(header->next == NULL)
    {
        puts("û��ѧ��");
        return;
    }
    puts("������Ҫ���ҵ�ѧ��id");
    int id;
    scanf("%d", &id);
    struct Stu* p = header->next;
    while(p != NULL)
    {
        if(p->id == id)
        {
            printf("�ҵ���,������%s\n", p->name);
            return;
        }

        p = p->next;
    }
    puts("û�ҵ�");
}

void delete_stu_name(struct Stu* header)
{
    struct Stu* p = header->next;
    struct Stu* previous = header;
    puts("������Ҫɾ��������");
    char name[20];
    scanf("%s", name);
    int ch;
    while((ch = getchar()) != '\n')
    {
        continue;
    }
    while(p != NULL)
    {
        if(strcmp(p->name, name) == 0)
        {
            previous->next = p->next;
            puts("ɾ���ɹ�");
            free(p);
            break;
        }
        else
        {
            previous = p;
            p = p->next;
        }
    }
}

void delete_stu_id(struct Stu* header)
{
    struct Stu* p = header->next;
    struct Stu* previous = header;
    puts("������Ҫɾ����id");
    int id;
    scanf("%d", &id);
    int ch;
    while((ch = getchar()) != '\n')
    {
        continue;
    }
    while(p != NULL)
    {
        if(p->id == id)
        {
            previous->next = p->next;
            puts("ɾ���ɹ�");
            free(p);
            break;
        }
        else
        {
            previous = p;
            p = p->next;
        }
    }
}

void save_stu(struct Stu* header)
{
    struct Stu* p = header->next;
    FILE* fp = fopen("student.data", "w");
    while(p != NULL)
    {
        fprintf(fp, "%d%s", p->id, p->name);
        p = p->next;
    }
    fclose(fp);
}

void read_stu(struct Stu* header)
{

    int size = sizeof(struct Stu);
    FILE* fp = fopen("student.data", "r");
    struct Stu* p;
    p = (struct Stu*)malloc(size);
    header->next = p;
    int count = 0;
    while(1)
    {
        struct Stu* tmp = (struct Stu*)malloc(size);
        int ret = fscanf(fp, "%d%s", &tmp->id,tmp->name);
        if(ret == 2)
        {
            p->next = tmp;
            p = tmp;
            count++;
        }
        else
        {
            free(tmp);
            break;
        }
    }
    if(count == 0)
    {
        header->next = NULL;
        free(p);
    }
    else
    {
        p->next = NULL;
    }
    fclose(fp);
}

int main()
{
    struct Stu* header = (struct Stu*)malloc(sizeof(struct Stu));
    header->next = NULL;
    read_stu(header);
    print_stu(header);
    int i;
    for(i=0; i<3; i++)
    {
        insert_stu(header);
    }
    print_stu(header);
    //search_stu_name(header);
    //search_stu_id(header);
    //delete_stu_name(header);
    //delete_stu_id(header);
    //print_stu(header);
    save_stu(header);
    return 0;
}

