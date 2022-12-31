#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <windows.h>

#define ADMINISTRATOR_CODE "123456"

#define MAX_USER_NAME 19

#define MAX_ONER_NAME 15

#define MAX_LODGER 15

#define MAX_CODE 19

#define MAX_ADDRESS 20

#define MAX_TELEPHONE 13

#define MAX_FACILITY_NAME 20

#define MAX_FACILITY_CONDITION 10

#define MAX_BUS_NAME 10

#define MAX_DEPARTURE MAX_FACILITY_NAME

#define MAX_DESTINATION MAX_FACILITY_NAME

#define BUS_CAPACITY 30

#define COLOR1 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x7A);

#define COLOR2 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0C);

#define COLOR3 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x6C);

time_t ti;

struct User
{
    char user_name[MAX_USER_NAME];//�û���
    char code[MAX_CODE];//����
    char oner_name[MAX_ONER_NAME];//��ʵ����
    char tele[MAX_TELEPHONE];//�绰
    struct User* next;
};
struct User* user_head;

struct House
{
    char oner_name[MAX_ONER_NAME];//����
    char addr[MAX_ADDRESS];//��ַ
    char lodger[MAX_LODGER];//��¼ס��
    struct House* next;
};
struct House* house_head;

struct Facility
{
    char facility_name[MAX_FACILITY_NAME];
    char facility_condition[MAX_FACILITY_CONDITION];
    char user_name[MAX_USER_NAME];
    struct Facility* next;
};
struct Facility* facility_head;

struct Bus
{
    char bus_name[MAX_BUS_NAME];
    char departure[MAX_DEPARTURE];
    char destination[MAX_DESTINATION];
    struct Bus* next;
};
struct Bus* bus_head;

char* s_gets(char* st, int n);//��ȡһ���ַ���,���Ϊ\0������\n\0

void begin_menu(void);//��ʼ�˵�

void init_head_all(void);

void init_user_head(void);//��ʼ���û�ͷ���

void init_house_head(void);//��ʼ������ͷ���

void init_facility_head(void);//��ʼ����ʩͷ���

void init_bus_head(void);//��ʼ���೵ͷ���

void read_all(void);

void read_user(void);//¼���û���Ϣ

void read_house(void);//¼�뷿����Ϣ

void read_facility(void);//¼��������ʩ

void read_bus(void);//¼��೵

void user_menu(void);

void users(void);

struct User* sign_in_user(void);

void buy_house(struct User* p);

void rent_house(struct User* p);

void modify_user(struct User* p);

int duplicate_user(char user_name[]);

int delete_user(struct User* p);

void delete_house(void);

void delete_facility(void);

void delete_bus(void);

void sell_house(struct User* p);

void stop_rent_house(struct User* p);

void print_user_house(struct User* p);

void new_user(void);//�û�����ͷ�巨

void new_house(void);//�������β�巨

void new_facility(void);//������ʩ����β�巨

void new_bus(void);//�೵����β�巨

struct User* search_user(char user_name[]);

struct House* search_house(char house_addr[]);

struct Facility* search_facility(char facility_name[]);

struct Bus* search_bus(char bus_name[]);

void book_facility(struct User* p);

void book_bus(struct User* p);

void use_facility(struct User* p);

void use_bus(struct User* p);

int use_facility_duplicate(struct User* p);

void stop_book_facility(struct User* p);

void stop_use_facility(struct User* p);

void administrator(void);

int sign_in_administrator(void);

void print_user(void);

void print_house(void);

void print_facility(void);

void print_bus(void);

void save_all(void);

void save_user(void);

void save_house(void);

void save_facility(void);

void save_bus(void);

void colorchange(void);

int main(void)
{
    colorchange();
    begin_menu();
    init_head_all();
    read_all();
    int input;
    do
    {
        scanf("%d", &input);
        getchar();
        switch(input)
        {
            case 1:
                users();
                break;
            case 2:
                new_user();
                break;
            case 3:
                administrator();
                break;
            case 0:
                save_all();
                break;
            default:
                puts("�������,����������");
                break;
        }
    }while(input);

    return 0;
}

char* s_gets(char* st, int n)
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

void begin_menu(void)
{
   COLOR1 puts("��ѡ����Ĳ���:");
   COLOR2 puts("0.�˳�������");
   COLOR3 puts("1.��¼�˻�");
   COLOR1 puts("2.�����µ��˻�");
   COLOR2 puts("3.��¼����Ա�û�");
}

void init_head_all(void)
{
    init_user_head();
    init_house_head();
    init_facility_head();
    init_bus_head();
}

void init_user_head(void)
{
    user_head = (struct User*)malloc(sizeof(struct User));
    user_head->next = NULL;
}

void init_house_head(void)
{
    house_head = (struct House*)malloc(sizeof(struct House));
    house_head->next = NULL;
}

void init_facility_head(void)
{
    facility_head = (struct Facility*)malloc(sizeof(struct Facility));
    facility_head->next = NULL;
}

void init_bus_head(void)
{
    bus_head = (struct Bus*)malloc(sizeof(struct Bus));
    bus_head->next = NULL;
}

void read_all(void)
{
    read_user();
    read_house();
    read_facility();
    read_bus();
}

void read_user(void)
{
    int size = sizeof(struct User);
    FILE* fp = fopen("user.data", "rb");
    if(fp == NULL)
    {
        return;
    }

    struct User* p;
    p = user_head;
    while(1)
    {
        struct User* tmp = (struct User*)malloc(size);
        int ret = fscanf(fp, "%s\t%s\t%s\t%s\n",
                            tmp->user_name,
                            tmp->code,
                            tmp->oner_name,
                            tmp->tele);
        if(ret == 4)
        {
            p->next = tmp;
            p = tmp;
        }
        else
        {
            free(tmp);
            break;
        }
    }

    p->next = NULL;
    fclose(fp);
}

void read_house(void)
{
    int size = sizeof(struct House);
    FILE* fp = fopen("house.data", "rb");
    if(fp == NULL)
    {
        return;
    }

    struct House* p;
    p = house_head;
    while(1)
    {
        struct House* tmp = (struct House*)malloc(size);
        int ret = fscanf(fp, "%s\t%s\t%s",
                        tmp->addr,
                        tmp->oner_name,
                        tmp->lodger);

        if(ret == 3)
        {
            p->next = tmp;
            p = tmp;
        }
        else
        {
            free(tmp);
            break;
        }


    }

    p->next = NULL;
    fclose(fp);
}

void read_facility(void)
{
    int size = sizeof(struct Facility);
    FILE* fp = fopen("facility.data", "rb");
    if(fp == NULL)
    {
        return;
    }

    struct Facility* p = facility_head;
    while(1)
    {
        struct Facility* tmp = (struct Facility*)malloc(size);
        int ret = fscanf(fp, "%s\t%s\t%s",
                        tmp->facility_name,
                        tmp->facility_condition,
                        tmp->user_name);

        if(ret == 3)
        {
            p->next = tmp;
            p = tmp;
        }
        else
        {
            free(tmp);
            break;
        }


    }

    p->next = NULL;
    fclose(fp);
}

void read_bus(void)
{
    int size = sizeof(struct Bus);
    FILE* fp = fopen("bus.data", "rb");
    if(fp == NULL)
    {
        return;
    }

    struct Bus* p = bus_head;
    while(1)
    {
        struct Bus* tmp = (struct Bus*)malloc(size);
        int ret = fscanf(fp, "%s\t%s\t%s",
                                            tmp->bus_name,
                                            tmp->departure,
                                            tmp->destination);

        if(ret == 3)
        {
            p->next = tmp;
            p = p->next;
        }
        else
        {
            free(tmp);
            break;
        }
    }

    p->next = NULL;
    fclose(fp);
}

//ͷ�巨
void new_user(void)
{
    system("cls");
    struct User* p = (struct User*)malloc(sizeof(struct User));
    if(p == NULL)
    {
        perror("new_user");
        return;
    }

    puts("�����벻����16λ���û���");
    p->user_name[MAX_USER_NAME-1] = 'h';//������滻��Ϊ�˲����һλ�Ƿ�Ϊ\0(���û�������16λ)
    s_gets(p->user_name, MAX_USER_NAME);
    while(1)
    {
        while(p->user_name[MAX_USER_NAME-1] == '\0')
        {
            puts("���ȹ���,����������");
            p->user_name[MAX_USER_NAME-1] = 'h';
            s_gets(p->user_name, MAX_USER_NAME);
        }

        int ret = duplicate_user(p->user_name);
        if(ret == 1)
        {
            puts("�û������ظ�,����������");
            s_gets(p->user_name, MAX_USER_NAME);
        }
        else
        {
            break;
        }
    }

    puts("�����벻����16λ������");
    p->code[MAX_CODE-1] = 'h';//ͬ��
    s_gets(p->code, MAX_CODE);
    while(p->code[MAX_CODE-1] == '\0')
    {
        puts("���ȹ���,����������");
        p->code[MAX_CODE-1] = 'h';
        s_gets(p->code, MAX_CODE);
    }

    puts("��������������");
    s_gets(p->oner_name, MAX_ONER_NAME);

    puts("������绰");
    s_gets(p->tele, MAX_TELEPHONE);

    p->next = user_head->next;
    user_head->next = p;

    puts("���ӳɹ�!");
    Sleep(1000);
    system("cls");
    begin_menu();
}

//β�巨
void new_house(void)
{
    system("cls");
    struct House* p = house_head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    int size = sizeof(struct House);
    while(1)
    {
        struct House* tmp = (struct House*)malloc(size);

        puts("�����뷿���ַ,���Ҫ�˳���ֱ�Ӱ��س�");
        s_gets(tmp->addr, MAX_ADDRESS);
        if(tmp->addr[0] == '\0')
        {
            system("cls");
            free(tmp);
            return;
        }

        strcpy(tmp->oner_name, "��");
        strcpy(tmp->lodger, "��");

        p->next = tmp;
        p = p->next;
        p->next = NULL;

    }
}

//β�巨
void new_facility(void)
{
    system("cls");
    struct Facility* p = facility_head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    int size = sizeof(struct Facility);
    while(1)
    {
        struct Facility* tmp = (struct Facility*)malloc(size);

        puts("������������ʩ������\n���Ҫ�˳���ֱ�Ӱ��س�");
        s_gets(tmp->facility_name, MAX_FACILITY_NAME);
        if(tmp->facility_name[0] == '\0')
        {
            system("cls");
            free(tmp);
            return;
        }

        strcpy(tmp->facility_condition, "����");
        strcpy(tmp->user_name, "��");

        p->next = tmp;
        p = p->next;
        p->next = NULL;
    }
}

//β�巨
void new_bus(void)
{
    system("cls");
    struct Bus* p = bus_head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    int size = sizeof(struct Bus);
    print_house();
    print_facility();
    while(1)
    {
        struct Bus* tmp = (struct Bus*)malloc(sizeof(struct Bus));
        puts("������೵�����\n���Ҫ�˳���ֱ�Ӱ��س�");
        s_gets(tmp->bus_name, MAX_BUS_NAME);
        if(tmp->bus_name[0] == '\0')
        {
            system("cls");
            free(tmp);
            return;
        }

        puts("��ѡ��ʼ��վ");
        s_gets(tmp->departure, MAX_DEPARTURE);
        puts("��ѡ���յ�վ");
        s_gets(tmp->destination, MAX_DESTINATION);

        p->next = tmp;
        p = p->next;
        p->next = NULL;
    }
}

void users(void)
{
    system("cls");
    struct User* p = sign_in_user();
    int input;
    do
    {
        user_menu();
        scanf("%d", &input);
        getchar();
        switch(input)
        {
            case 0:
                break;
            case 1:
                buy_house(p);
                break;
            case 2:
                rent_house(p);
                break;
            case 3:
                modify_user(p);
                break;
            case 4:
                sell_house(p);
                break;
            case 5:
                stop_rent_house(p);
                break;
            case 6:
                print_user_house(p);
                system("pause");
                system("cls");
                break;
            case 7:
                input = delete_user(p);
                break;
            case 8:
                book_facility(p);
                break;
            case 9:
                use_facility(p);
                break;
            case 10:
                print_facility();
                system("pause");
                system("cls");
                break;
            case 11:
                stop_book_facility(p);
                break;
            case 12:
                stop_use_facility(p);
                break;
            case 13:
                book_bus(p);
                break;
            case 14:
                use_bus(p);
                break;
            default :
                puts("�������,����������");
                break;
        }
    }while(input);

    system("cls");
    begin_menu();
}

void user_menu(void)
{
    puts("��ѡ����Ĳ���");
    puts("0.�˳��û�");
    puts("1.��");
    puts("2.�ⷿ/��ס");
    puts("3.�޸��û���Ϣ");
    puts("4.����");
    puts("5.ֹͣ��ס");
    puts("6.��ӡ�Լ����еķ���");
    puts("7.ע���û�");
    puts("8.ԤԼ������ʩ");
    puts("9.ʹ��������ʩ");
    puts("10.��ӡ����������ʩ");
    puts("11.ȡ��ԤԼ������ʩ");
    puts("12.ȡ��ʹ��������ʩ");
    puts("13.Ԥ���೵");
    puts("14.ʹ�ð೵");
}

struct User* sign_in_user(void)
{
    puts("����������û���");
    char user_name[MAX_USER_NAME];
    char user_code[MAX_CODE];
    s_gets(user_name, MAX_USER_NAME);
    struct User* p;
    while(1)
    {
        p = search_user(user_name);
        if(p == NULL)
        {
            puts("û�и��û���,����������");
            s_gets(user_name, MAX_USER_NAME);
        }
        else
        {
            break;
        }
    }

    puts("����������");
    while(1)
    {
        s_gets(user_code, MAX_CODE);
        if(strcmp(user_code, p->code) != 0)
        {
            puts("�������,����������");
        }
        else
        {
            break;
        }
    }
    puts("��½�ɹ�!");
    Sleep(1000);
    system("cls");
    return p;
}

struct User* search_user(char user_name[])
{
    struct User* p = user_head->next;
    while(p != NULL)
    {
        if(strcmp(p->user_name, user_name) == 0)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

struct House* search_house(char house_addr[])
{
    struct House* p = house_head->next;
    while(p != NULL)
    {
        if(strcmp(house_addr, p->addr) == 0)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

struct Facility* search_facility(char facility_name[])
{
    struct Facility* p = facility_head->next;
    while(p != NULL)
    {
        if(strcmp(facility_name, p->facility_name) == 0)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

struct Bus* search_bus(char bus_name[])
{
    struct Bus* p = bus_head->next;
    while(p != NULL)
    {
        if(strcmp(bus_name, p->bus_name) == 0)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }

    return NULL;
}

void book_facility(struct User* p)
{
    system("cls");
    print_facility();
    puts("��������ҪԤԼ����Ŀ����");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("û�и���ʩ");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->user_name, "��") == 0)
    {
        puts("ԤԼ�ɹ�!");
        strcpy(ptr->user_name, p->oner_name);
        strcpy(ptr->facility_condition, "ԤԼ��");
        Sleep(1000);
        system("cls");
        return;
    }
    else if(strcmp(ptr->user_name, p->oner_name) == 0)
    {
        puts("����ʩ�ѱ���ʹ��");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("����ʩ�ѱ�ռ��");
        system("pause");
        system("cls");
        return;
    }
}

void book_bus(struct User* p)
{
    system("cls");
    print_bus();
    puts("��������ҪԤ���İ೵���\n���Ҫ�˳���ֱ�Ӱ��س�");
    char bus_name[MAX_BUS_NAME];
    s_gets(bus_name, MAX_BUS_NAME);
    if(bus_name[0] == '\0')
    {
        return;
    }

    struct Bus* ptr = search_bus(bus_name);
    if(ptr == NULL)
    {
        puts("û�иð೵");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("Ԥ���ɹ�!");
        Sleep(1000);
        system("cls");
        return;
    }
}

void use_facility(struct User* p)
{
    system("cls");
    print_facility();
    puts("��������Ҫʹ�õ���Ŀ����");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("û�и���ʩ");
        system("pause");
        system("cls");
        return;
    }

    int ret = use_facility_duplicate(p);
    if(ret == 1)
    {
        puts("���Ѿ���ʹ��һ����ʩ");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->user_name, "��") == 0)
    {
        puts("ʹ�óɹ�!");
        strcpy(ptr->user_name, p->oner_name);
        strcpy(ptr->facility_condition, "ʹ����");
        Sleep(1000);
        system("cls");
        return;
    }
    else if(strcmp(ptr->user_name, p->oner_name) == 0 &&
            strcmp(ptr->facility_condition, "ԤԼ��") == 0)
    {
        puts("ʹ�óɹ�!");
        strcpy(ptr->facility_condition, "ʹ����");
        Sleep(1000);
        system("cls");
        return;
    }
    else if(strcmp(ptr->user_name, p->oner_name) == 0 &&
            strcmp(ptr->facility_condition, "ʹ����") == 0)
    {
        puts("���Ѿ���ʹ�ø���ʩ");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("����ʩ�ѱ�ռ��");
        system("pause");
        system("cls");
        return;
    }
}

void use_bus(struct User* p)
{
    print_bus();
    puts("��������Ҫʹ�õİ೵���\n���Ҫ�˳���ֱ�Ӱ��س�");
    char bus_name[MAX_BUS_NAME];
    s_gets(bus_name, MAX_BUS_NAME);
    if(bus_name[0] == '\0')
    {
        return;
    }

    struct Bus* ptr = search_bus(bus_name);
    if(ptr == NULL)
    {
        puts("û�иð೵");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("ʹ�óɹ�!");
        Sleep(1000);
        system("cls");
        return;
    }
}

int use_facility_duplicate(struct User* p)
{
    struct Facility* ptr = facility_head->next;
    while(ptr != NULL)
    {
        if(strcmp(ptr->user_name, p->oner_name) == 0)
        {
            return 1;
        }

        ptr = ptr->next;
    }

    return 0;
}

void stop_book_facility(struct User* p)
{
    print_facility();
    puts("������Ҫȡ��Ԥ������ʩ����");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("û�и���ʩ");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->facility_condition, "ԤԼ��") == 0 &&
       strcmp(ptr->user_name, p->oner_name) == 0)
    {
        puts("ȡ��ԤԼ�ɹ�!");
        strcpy(ptr->facility_condition, "����");
        strcpy(ptr->user_name, "��");
        Sleep(1000);
        system("cls");
        return;
    }
    else
    {
        puts("ȡ��ʧ��");
        system("pause");
        system("cls");
        return;
    }
}

void stop_use_facility(struct User* p)
{
    print_facility();
    puts("������Ҫȡ��ʹ�õ���ʩ����");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("û�и���ʩ");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->facility_condition, "ʹ����") == 0 &&
       strcmp(ptr->user_name, p->oner_name) == 0)
    {
        puts("ȡ��ʹ�óɹ�!");
        strcpy(ptr->facility_condition, "����");
        strcpy(ptr->user_name, "��");
        Sleep(1000);
        system("cls");
        return;
    }
    else
    {
        puts("ȡ��ʧ��");
        system("pause");
        system("cls");
        return;
    }
}

void buy_house(struct User* p)
{
    print_house();
    puts("��ѡ����Ҫ��ķ�\n�˳���ֱ�Ӱ��س�");
    char house_addr[MAX_ADDRESS];
    struct House* ptr;
    while(1)
    {
        s_gets(house_addr, MAX_ADDRESS);
        if(house_addr[0] == '\0')
        {
            system("cls");
            return;
        }

        ptr = search_house(house_addr);
        if(ptr == NULL)
        {
            puts("û�д˷���,����������");
            continue;
        }
        else
        {
            if(strcmp(ptr->oner_name, "��") == 0)
            {
                puts("����ɹ�!");
                strcpy(ptr->oner_name, p->oner_name);
                Sleep(1000);
                system("cls");
                break;
            }
            else
            {
                puts("�÷�����������,�뻻һ������");
                continue;
            }
        }
    }
}

void rent_house(struct User* p)
{
    print_house();
    puts("��������Ҫ��ķ���,���Ҫ�˳���ֱ�Ӱ��س�");
    char house_addr[MAX_ADDRESS];
    struct House* ptr;
    while(1)
    {
        s_gets(house_addr, MAX_ADDRESS);
        if(house_addr[0] == '\0')
        {
            system("cls");
            return;
        }

        ptr = search_house(house_addr);
        if(ptr == NULL)
        {
            puts("û�д˷���,����������");
            continue;
        }
        else
        {
            if(strcmp(ptr->oner_name, "��") == 0)
            {
                puts("�÷���������,����������");
                continue;
            }
            else if(strcmp(ptr->lodger, "��") != 0)
            {
                puts("�÷��������˾�ס,����������");
                continue;
            }
            else
            {
                puts("��ס�ɹ�!");
                strcpy(ptr->lodger, p->oner_name);
                Sleep(1000);
                system("cls");
                break;
            }
        }
    }
}

void modify_user(struct User* p)
{
    system("cls");
    printf("%-16s\t%-16s\t%-5s\t%-11s\n", "�û���", "����", "����", "�绰");
    printf("%-16s\t%-16s\t%-5s\t%-11s\n", p->user_name, p->code, p->oner_name, p->tele);
    puts("��ѡ����Ҫ�޸ĵĵط�");
    puts("0.�˳�");
    puts("1.�û���");
    puts("2.����");
    puts("3.����");
    puts("4.�绰");
    while(1)
    {
        int input;
        scanf("%d", &input);
        getchar();
        switch(input)
        {
            case 0:
                system("cls");
                return;
            case 1:
                puts("�������޸ĺ���û���,������16λ");
                p->user_name[MAX_USER_NAME-1] = 'h';//������滻��Ϊ�˲����һλ�Ƿ�Ϊ\0(���û�������16λ)
                s_gets(p->user_name, MAX_USER_NAME);
                while(1)
                {
                    while(p->user_name[MAX_USER_NAME-1] == '\0')
                    {
                        puts("���ȹ���,����������");
                        p->user_name[MAX_USER_NAME-1] = 'h';
                        s_gets(p->user_name, MAX_USER_NAME);
                    }

                    int ret = duplicate_user(p->user_name);
                    if(ret == 1)
                    {
                        puts("�û������ظ�,����������");
                        s_gets(p->user_name, MAX_USER_NAME);
                    }
                    else
                    {
                        break;
                    }
                }
                puts("�޸ĳɹ�!");
                Sleep(1000);
                system("cls");
                return;
            case 2:
                puts("�������޸ĺ������,������16λ");
                p->code[MAX_CODE-1] = 'h';//ͬ��
                s_gets(p->code, MAX_CODE);
                while(p->code[MAX_CODE-1] == '\0')
                {
                    puts("���ȹ���,����������");
                    p->code[MAX_CODE-1] = 'h';
                    s_gets(p->code, MAX_CODE);
                }
                puts("�޸ĳɹ�!");
                Sleep(1000);
                system("cls");
                return;
            case 3:
                puts("�������޸ĺ������");
                s_gets(p->oner_name, MAX_ONER_NAME);
                puts("�޸ĳɹ�!");
                Sleep(1000);
                system("cls");
                return;
            case 4:
                puts("�������޸ĺ�ĵ绰");
                s_gets(p->tele, MAX_TELEPHONE);
                puts("�޸ĳɹ�!");
                Sleep(1000);
                system("cls");
                return;
            default :
                puts("�������,����������");
                break;
        }
    }
}

int duplicate_user(char user_name[])
{
    struct User* p = user_head->next;
    while(p != NULL)
    {
        if(strcmp(p->user_name, user_name) == 0)
        {
            return 1;
        }

        p = p->next;
    }

    return 0;
}

void sell_house(struct User* p)
{
    system("cls");
    puts("����������еķ���");
    print_user_house(p);
    puts("��ѡ����Ҫ�����ķ���\n���Ҫ�˳���ֱ�Ӱ��س�");
    char house_name[MAX_ADDRESS];
    s_gets(house_name, MAX_ADDRESS);
    if(house_name[0] == '\0')
    {
        return;
    }

    struct House* ptr = house_head->next;
    while(ptr != NULL)
    {
        if(strcmp(ptr->addr, house_name) == 0)
        {
            strcpy(ptr->oner_name, "��");
            strcpy(ptr->lodger, "��");
            puts("�����ɹ�!");
            Sleep(1000);
            system("cls");
            return;
        }
        else
        {
            ptr = ptr->next;
        }
    }

    puts("δ�ҵ��÷���!");
    system("pause");
    system("cls");
}

void stop_rent_house(struct User* p)
{
    system("cls");
    puts("����������ס�ķ���");
    print_user_house(p);
    puts("��ѡ����ֹͣ��ס�ķ���\n���Ҫ�˳���ֱ�Ӱ��س�");
    char house_name[MAX_ADDRESS];
    s_gets(house_name, MAX_ADDRESS);
    if(house_name[0] == '\0')
    {
        system("cls");
        return;
    }

    struct House* ptr = house_head->next;
    while(ptr != NULL)
    {
        if(strcmp(ptr->lodger, p->oner_name) == 0)
        {
            strcpy(ptr->lodger, "��");
            puts("�����ɹ�!");
            Sleep(1000);
            system("cls");
            return;
        }

        ptr = ptr->next;
    }

    puts("ִ��ʧ��");
    system("pause");
    system("cls");
    return;
}

void print_user_house(struct User* p)
{
    system("cls");
    struct House* ptr = house_head->next;
    printf("%-8s\t%-5s\t%-5s\n", "���ݵ�ַ", "����", "ס��");
    while(ptr != NULL)
    {
        if(strcmp(ptr->oner_name, p->oner_name) == 0)
        {
            printf("%-8s\t%-5s\t%-5s\n", ptr->addr, ptr->oner_name, ptr->lodger);
        }

        ptr = ptr->next;
    }

}

int delete_user(struct User* p)
{
    system("cls");
    puts("��ȷ��Ҫע�����û���?\nȷ�ϰ�1,ȡ����0");
    int input;
    while(1)
    {
        scanf("%d", &input);
        getchar();
        if(input == 1)
        {
            if(user_head->next == p)
            {
                //ȥ�����ڴ��û������������Ϣ
                //����
                struct House* tmp = house_head->next;
                {
                    while(tmp != NULL)
                    {
                        if(strcmp(tmp->oner_name, p->oner_name) == 0)
                        {
                            strcpy(tmp->oner_name, "��");
                            strcpy(tmp->lodger, "��");//��ͱ�ǿ�Ƹϳ�
                        }
                        else if(strcmp(tmp->lodger, p->oner_name) == 0)
                        {
                            strcpy(tmp->lodger, "��");
                        }

                        tmp = tmp->next;
                    }
                }

                //������ʩ
                struct Facility* ret = facility_head->next;
                while(ret != NULL)
                {
                    if(strcmp(ret->user_name, p->oner_name) == 0)
                    {
                        strcpy(ret->facility_condition, "����");
                        strcpy(ret->user_name, "��");
                    }

                    ret = ret->next;
                }

                user_head->next = p->next;
                free(p);
            }
            else
            {
                struct User* ptr = user_head->next;
                //ʹptrΪp��ǰһ��
                while(ptr->next != p)
                {
                    ptr = ptr->next;
                }
                //ȥ�����ڴ��û������������Ϣ
                //����
                struct House* tmp = house_head->next;
                {
                    while(tmp != NULL)
                    {
                        if(strcmp(tmp->oner_name, p->oner_name) == 0)
                        {
                            strcpy(tmp->oner_name, "��");
                            strcpy(tmp->lodger, "��");//��ͱ�ǿ�Ƹϳ�
                        }
                        else if(strcmp(tmp->lodger, p->oner_name) == 0)
                        {
                            strcpy(tmp->lodger, "��");
                        }

                        tmp = tmp->next;
                    }
                }

                //������ʩ
                struct Facility* ret = facility_head->next;
                while(ret != NULL)
                {
                    if(strcmp(ret->user_name, p->oner_name) == 0)
                    {
                        strcpy(ret->facility_condition, "����");
                        strcpy(ret->user_name, "��");
                    }

                    ret = ret->next;
                }

                ptr->next = p->next;
                free(p);
            }
            puts("ע���ɹ�!");
            Sleep(1000);
            system("cls");
            return 0;//���ﷵ��ֵΪ0�����û�����input = 0,ֱ���˳�
        }
        else
        {
            system("cls");
            return 1;
        }
    }
}

void delete_house(void)
{
    struct House* previous = house_head;
    struct House* p = house_head->next;
    print_house();
    puts("��������Ҫɾ���ķ����ַ");
    char addr[MAX_ADDRESS];
    s_gets(addr, MAX_ADDRESS);

    while(p != NULL)
    {
        if(strcmp(p->addr, addr) == 0)
        {
            puts("ɾ���ɹ�!");
            previous->next = p->next;
            free(p);
            Sleep(1000);
            system("cls");
            return;
        }

        previous = previous->next;
        p = p->next;
    }

    puts("û�и÷���");
    system("pause");
    system("cls");
}

void delete_facility(void)
{
    print_facility();
    struct Facility* previous = facility_head;//previousΪp��ǰһ��
    struct Facility* p = facility_head->next;
    puts("��������Ҫɾ������ʩ����");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    while(p != NULL)
    {
        if(strcmp(p->facility_name, facility_name) == 0)
        {
            previous->next = p->next;
            free(p);
            puts("ɾ���ɹ�!");
            Sleep(1000);
            system("cls");
            return;
        }
        else
        {
            previous = previous->next;
            p = p->next;
        }
    }

    puts("δ�ҵ�����ʩ");
    system("pause");
    system("cls");
}

void delete_bus(void)
{
    print_bus();
    puts("��ѡ����Ҫɾ���İ೵���");
    char bus_name[MAX_BUS_NAME];
    s_gets(bus_name, MAX_BUS_NAME);
    struct Bus* previous = bus_head;
    struct Bus* p = bus_head->next;
    while(p != NULL)
    {
        if(strcmp(p->bus_name, bus_name) == 0)
        {
            previous->next = p->next;
            free(p);
            puts("ɾ���ɹ�!");
            Sleep(1000);
            system("cls");
            return;
        }

        previous = previous->next;
        p = p->next;
    }

    puts("δ�ҵ��ð೵");
    system("pause");
    system("cls");

}

void print_user(void)
{
    system("cls");
    struct User* p = user_head->next;

    if(p == NULL)
    {
        puts("û���û�");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-16s\t%-16s\t%-6s\t%-12s\n",
                                            "�û���",
                                            "����",
                                            "����",
                                            "�绰");
    }

    while(p != NULL)
    {
        printf("%-16s\t%-16s\t%-6s\t%-12s\n",   p->user_name,
                                                p->code,
                                                p->oner_name,
                                                p->tele);
        p = p->next;
    }

    system("pause");
}

void print_house(void)
{
    system("cls");
    struct House* p = house_head->next;
    if(p == NULL)
    {
        puts("û�з���");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-12s\t%-5s\t%-5s\n",
                                            "�����ַ",
                                            "����",
                                            "ס��");
    }

    while(p != NULL)
    {
        printf("%-12s\t%-5s\t%-5s\n",
                                    p->addr,
                                    p->oner_name,
                                    p->lodger);
        p = p->next;
    }
}

void print_facility(void)
{
    system("cls");
    struct Facility* p = facility_head->next;
    if(p == NULL)
    {
        puts("û��������ʩ");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-10s\t%-8s\t%-8s\n",
                                            "��ʩ����",
                                            "��ʩ״̬",
                                            "ʹ���û�");
    }

    while(p != NULL)
    {
        printf("%-10s\t%-8s\t%-8s\n",
                                            p->facility_name,
                                            p->facility_condition,
                                            p->user_name);

        p = p->next;
    }
}

void print_bus(void)
{
    system("cls");
    struct Bus* p = bus_head->next;
    if(p == NULL)
    {
        puts("û�а೵");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-8s\t%-10s\t%-10s\n",
                                            "�೵���",
                                            "����վ",
                                            "�յ�վ");
    }

    while(p != NULL)
    {
        printf("%-8s\t%-10s\t%-10s\n",
                                            p->bus_name,
                                            p->departure,
                                            p->destination);

        p = p->next;
    }
}

void administrator_menu(void)
{
    puts("��ѡ����Ĳ���:");
    puts("1.��������");
    puts("2.��ӡ���з�����Ϣ");
    puts("3.��ӡ�����û���Ϣ");
    puts("4.����������ʩ");
    puts("5.��ӡ����������ʩ��Ϣ");
    puts("6.ɾ��������ʩ");
    puts("7.�����೵");
    puts("8.ɾ���೵");
    puts("9.��ӡ�೵");
    puts("10.ɾ������");
    puts("0.�˳�����Ա�˻�");
}

void administrator(void)
{
    system("cls");
    if(sign_in_administrator() == 0)
    {
        return;
    }

    int input;
    do
    {
        administrator_menu();
        scanf("%d", &input);
        getchar();
        switch(input)
        {
            case 1:
                new_house();
                break;
            case 2:
                print_house();
                system("pause");
                system("cls");
                break;
            case 3:
                print_user();
                system("cls");
                break;
            case 4:
                new_facility();
                break;
            case 5:
                print_facility();
                system("pause");
                system("cls");
                break;
            case 6:
                delete_facility();
                break;
            case 7:
                new_bus();
                break;
            case 8:
                delete_bus();
                break;
            case 9:
                print_bus();
                system("pause");
                system("cls");
                break;
            case 10:
                delete_house();
                break;
            case 0:
                system("cls");
                break;
            default:
                puts("�������,����������");
                break;
        }
    }while(input);

    begin_menu();
}

int sign_in_administrator(void)
{
    system("cls");
    puts("����������\n���Ҫ�˳���ֱ������س�");
    char code[10];
    while(1)
    {
        s_gets(code, 10);
        if(strcmp(ADMINISTRATOR_CODE, code) == 0)
        {
            puts("��½�ɹ�!");
            Sleep(1000);
            system("cls");
            return 1;
        }
        else if(!(code[0]-'0'))
        {
            puts("-----------------------");
            return 0;
        }
        else
        {
            puts("�������,����������");
        }
    }
}

void save_all(void)
{
    save_user();
    save_house();
    save_facility();
    save_bus();
}

void save_user(void)
{

    struct User* p = user_head->next;

    FILE* fp = fopen("user.data", "wb");
    if(fp == NULL)
    {
        perror("save_user");
        return;
    }

    while(p != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\t%s\n",
                                        p->user_name,
                                        p->code,
                                        p->oner_name,
                                        p->tele);
        p = p->next;
    }

    fclose(fp);
}

void save_house(void)
{
    struct House* p = house_head->next;

    FILE* fp = fopen("house.data", "wb");
    if(fp == NULL)
    {
        perror("save_house");
        return;
    }

    while(p != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\n",
                                    p->addr,
                                    p->oner_name,
                                    p->lodger);
        p = p->next;
    }

    fclose(fp);
}

void save_facility(void)
{
    struct Facility* p = facility_head->next;

    FILE* fp = fopen("facility.data", "wb");
    if(fp == NULL)
    {
        perror("save_facility");
        return;
    }

    while(p != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\n",
                                        p->facility_name,
                                        p->facility_condition,
                                        p->user_name);

        p = p->next;
    }

    fclose(fp);
}

void save_bus(void)
{
    struct Bus* p = bus_head->next;

    FILE* fp = fopen("bus.data", "wb");
    if(fp == NULL)
    {
        perror("save_bus");
        return;
    }

    while(p != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\n",
                                                                p->bus_name,
                                                                p->departure,
                                                                p->destination);

        p = p->next;
    }

    fclose(fp);
}
void colorchange(void)
{
    int i=0;
     while (i<=2)
    {
        i++;
        srand(time(NULL));
        int _nPreColorFlag = rand() % 10;
        int _nBackColorFlag = rand() % 6;
        char _cBackColorFlag;
        switch(_nBackColorFlag)
        {
        case 0:  _cBackColorFlag = 'A';
			break;

        case 1:  _cBackColorFlag = 'B';
			break;

        case 2:  _cBackColorFlag = 'C';
			break;

        case 3:  _cBackColorFlag = 'D';
			break;
        case 4:  _cBackColorFlag = 'E';
			break;

        case 5:  _cBackColorFlag = 'F';
			break;
        }

        char strColorFormat[2];
        sprintf(strColorFormat,"color  %d%c",_nPreColorFlag,_cBackColorFlag);
        system(strColorFormat);   //ͨ��system���������ñ�����ɫ

        Sleep(500);  //����˯��0.5��

    }
    return;
}
