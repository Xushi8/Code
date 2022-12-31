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
    char user_name[MAX_USER_NAME];//用户名
    char code[MAX_CODE];//密码
    char oner_name[MAX_ONER_NAME];//真实姓名
    char tele[MAX_TELEPHONE];//电话
    struct User* next;
};
struct User* user_head;

struct House
{
    char oner_name[MAX_ONER_NAME];//房主
    char addr[MAX_ADDRESS];//地址
    char lodger[MAX_LODGER];//记录住客
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

char* s_gets(char* st, int n);//读取一段字符串,最后为\0而不是\n\0

void begin_menu(void);//开始菜单

void init_head_all(void);

void init_user_head(void);//初始化用户头结点

void init_house_head(void);//初始化房间头结点

void init_facility_head(void);//初始化设施头结点

void init_bus_head(void);//初始化班车头结点

void read_all(void);

void read_user(void);//录入用户信息

void read_house(void);//录入房间信息

void read_facility(void);//录入娱乐设施

void read_bus(void);//录入班车

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

void new_user(void);//用户采用头插法

void new_house(void);//房间采用尾插法

void new_facility(void);//娱乐设施采用尾插法

void new_bus(void);//班车采用尾插法

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
                puts("输入错误,请重新输入");
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
   COLOR1 puts("请选择你的操作:");
   COLOR2 puts("0.退出并保存");
   COLOR3 puts("1.登录账户");
   COLOR1 puts("2.创建新的账户");
   COLOR2 puts("3.登录管理员用户");
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

//头插法
void new_user(void)
{
    system("cls");
    struct User* p = (struct User*)malloc(sizeof(struct User));
    if(p == NULL)
    {
        perror("new_user");
        return;
    }

    puts("请输入不多于16位的用户名");
    p->user_name[MAX_USER_NAME-1] = 'h';//这里的替换是为了查最后一位是否为\0(即用户名超过16位)
    s_gets(p->user_name, MAX_USER_NAME);
    while(1)
    {
        while(p->user_name[MAX_USER_NAME-1] == '\0')
        {
            puts("长度过长,请重新输入");
            p->user_name[MAX_USER_NAME-1] = 'h';
            s_gets(p->user_name, MAX_USER_NAME);
        }

        int ret = duplicate_user(p->user_name);
        if(ret == 1)
        {
            puts("用户名有重复,请重新输入");
            s_gets(p->user_name, MAX_USER_NAME);
        }
        else
        {
            break;
        }
    }

    puts("请输入不多于16位的密码");
    p->code[MAX_CODE-1] = 'h';//同上
    s_gets(p->code, MAX_CODE);
    while(p->code[MAX_CODE-1] == '\0')
    {
        puts("长度过长,请重新输入");
        p->code[MAX_CODE-1] = 'h';
        s_gets(p->code, MAX_CODE);
    }

    puts("请输入中文姓名");
    s_gets(p->oner_name, MAX_ONER_NAME);

    puts("请输入电话");
    s_gets(p->tele, MAX_TELEPHONE);

    p->next = user_head->next;
    user_head->next = p;

    puts("增加成功!");
    Sleep(1000);
    system("cls");
    begin_menu();
}

//尾插法
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

        puts("请输入房间地址,如果要退出则直接按回车");
        s_gets(tmp->addr, MAX_ADDRESS);
        if(tmp->addr[0] == '\0')
        {
            system("cls");
            free(tmp);
            return;
        }

        strcpy(tmp->oner_name, "无");
        strcpy(tmp->lodger, "无");

        p->next = tmp;
        p = p->next;
        p->next = NULL;

    }
}

//尾插法
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

        puts("请输入娱乐设施的名字\n如果要退出则直接按回车");
        s_gets(tmp->facility_name, MAX_FACILITY_NAME);
        if(tmp->facility_name[0] == '\0')
        {
            system("cls");
            free(tmp);
            return;
        }

        strcpy(tmp->facility_condition, "可用");
        strcpy(tmp->user_name, "无");

        p->next = tmp;
        p = p->next;
        p->next = NULL;
    }
}

//尾插法
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
        puts("请输入班车的序号\n如果要退出则直接按回车");
        s_gets(tmp->bus_name, MAX_BUS_NAME);
        if(tmp->bus_name[0] == '\0')
        {
            system("cls");
            free(tmp);
            return;
        }

        puts("请选择始发站");
        s_gets(tmp->departure, MAX_DEPARTURE);
        puts("请选择终点站");
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
                puts("输入错误,请重新输入");
                break;
        }
    }while(input);

    system("cls");
    begin_menu();
}

void user_menu(void)
{
    puts("请选择你的操作");
    puts("0.退出用户");
    puts("1.买房");
    puts("2.租房/入住");
    puts("3.修改用户信息");
    puts("4.卖房");
    puts("5.停止入住");
    puts("6.打印自己持有的房屋");
    puts("7.注销用户");
    puts("8.预约娱乐设施");
    puts("9.使用娱乐设施");
    puts("10.打印所有娱乐设施");
    puts("11.取消预约娱乐设施");
    puts("12.取消使用娱乐设施");
    puts("13.预订班车");
    puts("14.使用班车");
}

struct User* sign_in_user(void)
{
    puts("请输入你的用户名");
    char user_name[MAX_USER_NAME];
    char user_code[MAX_CODE];
    s_gets(user_name, MAX_USER_NAME);
    struct User* p;
    while(1)
    {
        p = search_user(user_name);
        if(p == NULL)
        {
            puts("没有该用户名,请重新输入");
            s_gets(user_name, MAX_USER_NAME);
        }
        else
        {
            break;
        }
    }

    puts("请输入密码");
    while(1)
    {
        s_gets(user_code, MAX_CODE);
        if(strcmp(user_code, p->code) != 0)
        {
            puts("密码错误,请重新输入");
        }
        else
        {
            break;
        }
    }
    puts("登陆成功!");
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
    puts("请输入你要预约的项目名称");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("没有该设施");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->user_name, "无") == 0)
    {
        puts("预约成功!");
        strcpy(ptr->user_name, p->oner_name);
        strcpy(ptr->facility_condition, "预约中");
        Sleep(1000);
        system("cls");
        return;
    }
    else if(strcmp(ptr->user_name, p->oner_name) == 0)
    {
        puts("该设施已被您使用");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("该设施已被占用");
        system("pause");
        system("cls");
        return;
    }
}

void book_bus(struct User* p)
{
    system("cls");
    print_bus();
    puts("请输入你要预订的班车序号\n如果要退出则直接按回车");
    char bus_name[MAX_BUS_NAME];
    s_gets(bus_name, MAX_BUS_NAME);
    if(bus_name[0] == '\0')
    {
        return;
    }

    struct Bus* ptr = search_bus(bus_name);
    if(ptr == NULL)
    {
        puts("没有该班车");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("预订成功!");
        Sleep(1000);
        system("cls");
        return;
    }
}

void use_facility(struct User* p)
{
    system("cls");
    print_facility();
    puts("请输入你要使用的项目名称");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("没有该设施");
        system("pause");
        system("cls");
        return;
    }

    int ret = use_facility_duplicate(p);
    if(ret == 1)
    {
        puts("您已经在使用一个设施");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->user_name, "无") == 0)
    {
        puts("使用成功!");
        strcpy(ptr->user_name, p->oner_name);
        strcpy(ptr->facility_condition, "使用中");
        Sleep(1000);
        system("cls");
        return;
    }
    else if(strcmp(ptr->user_name, p->oner_name) == 0 &&
            strcmp(ptr->facility_condition, "预约中") == 0)
    {
        puts("使用成功!");
        strcpy(ptr->facility_condition, "使用中");
        Sleep(1000);
        system("cls");
        return;
    }
    else if(strcmp(ptr->user_name, p->oner_name) == 0 &&
            strcmp(ptr->facility_condition, "使用中") == 0)
    {
        puts("您已经在使用该设施");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("该设施已被占用");
        system("pause");
        system("cls");
        return;
    }
}

void use_bus(struct User* p)
{
    print_bus();
    puts("请输入你要使用的班车序号\n如果要退出则直接按回车");
    char bus_name[MAX_BUS_NAME];
    s_gets(bus_name, MAX_BUS_NAME);
    if(bus_name[0] == '\0')
    {
        return;
    }

    struct Bus* ptr = search_bus(bus_name);
    if(ptr == NULL)
    {
        puts("没有该班车");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        puts("使用成功!");
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
    puts("请输入要取消预订的设施名称");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("没有该设施");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->facility_condition, "预约中") == 0 &&
       strcmp(ptr->user_name, p->oner_name) == 0)
    {
        puts("取消预约成功!");
        strcpy(ptr->facility_condition, "可用");
        strcpy(ptr->user_name, "无");
        Sleep(1000);
        system("cls");
        return;
    }
    else
    {
        puts("取消失败");
        system("pause");
        system("cls");
        return;
    }
}

void stop_use_facility(struct User* p)
{
    print_facility();
    puts("请输入要取消使用的设施名称");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    struct Facility* ptr = search_facility(facility_name);
    if(ptr == NULL)
    {
        puts("没有该设施");
        system("pause");
        system("cls");
        return;
    }

    if(strcmp(ptr->facility_condition, "使用中") == 0 &&
       strcmp(ptr->user_name, p->oner_name) == 0)
    {
        puts("取消使用成功!");
        strcpy(ptr->facility_condition, "可用");
        strcpy(ptr->user_name, "无");
        Sleep(1000);
        system("cls");
        return;
    }
    else
    {
        puts("取消失败");
        system("pause");
        system("cls");
        return;
    }
}

void buy_house(struct User* p)
{
    print_house();
    puts("请选择你要买的房\n退出则直接按回车");
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
            puts("没有此房间,请重新输入");
            continue;
        }
        else
        {
            if(strcmp(ptr->oner_name, "无") == 0)
            {
                puts("购买成功!");
                strcpy(ptr->oner_name, p->oner_name);
                Sleep(1000);
                system("cls");
                break;
            }
            else
            {
                puts("该房间已有主人,请换一个房间");
                continue;
            }
        }
    }
}

void rent_house(struct User* p)
{
    print_house();
    puts("请输入你要租的房间,如果要退出则直接按回车");
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
            puts("没有此房间,请重新输入");
            continue;
        }
        else
        {
            if(strcmp(ptr->oner_name, "无") == 0)
            {
                puts("该房间无主人,请重新输入");
                continue;
            }
            else if(strcmp(ptr->lodger, "无") != 0)
            {
                puts("该房间已有人居住,请重新输入");
                continue;
            }
            else
            {
                puts("入住成功!");
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
    printf("%-16s\t%-16s\t%-5s\t%-11s\n", "用户名", "密码", "姓名", "电话");
    printf("%-16s\t%-16s\t%-5s\t%-11s\n", p->user_name, p->code, p->oner_name, p->tele);
    puts("请选择你要修改的地方");
    puts("0.退出");
    puts("1.用户名");
    puts("2.密码");
    puts("3.姓名");
    puts("4.电话");
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
                puts("请输入修改后的用户名,不多于16位");
                p->user_name[MAX_USER_NAME-1] = 'h';//这里的替换是为了查最后一位是否为\0(即用户名超过16位)
                s_gets(p->user_name, MAX_USER_NAME);
                while(1)
                {
                    while(p->user_name[MAX_USER_NAME-1] == '\0')
                    {
                        puts("长度过长,请重新输入");
                        p->user_name[MAX_USER_NAME-1] = 'h';
                        s_gets(p->user_name, MAX_USER_NAME);
                    }

                    int ret = duplicate_user(p->user_name);
                    if(ret == 1)
                    {
                        puts("用户名有重复,请重新输入");
                        s_gets(p->user_name, MAX_USER_NAME);
                    }
                    else
                    {
                        break;
                    }
                }
                puts("修改成功!");
                Sleep(1000);
                system("cls");
                return;
            case 2:
                puts("请输入修改后的密码,不多于16位");
                p->code[MAX_CODE-1] = 'h';//同上
                s_gets(p->code, MAX_CODE);
                while(p->code[MAX_CODE-1] == '\0')
                {
                    puts("长度过长,请重新输入");
                    p->code[MAX_CODE-1] = 'h';
                    s_gets(p->code, MAX_CODE);
                }
                puts("修改成功!");
                Sleep(1000);
                system("cls");
                return;
            case 3:
                puts("请输入修改后的姓名");
                s_gets(p->oner_name, MAX_ONER_NAME);
                puts("修改成功!");
                Sleep(1000);
                system("cls");
                return;
            case 4:
                puts("请输入修改后的电话");
                s_gets(p->tele, MAX_TELEPHONE);
                puts("修改成功!");
                Sleep(1000);
                system("cls");
                return;
            default :
                puts("输入错误,请重新输入");
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
    puts("以下是你持有的房子");
    print_user_house(p);
    puts("请选择你要卖掉的房子\n如果要退出则直接按回车");
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
            strcpy(ptr->oner_name, "无");
            strcpy(ptr->lodger, "无");
            puts("操作成功!");
            Sleep(1000);
            system("cls");
            return;
        }
        else
        {
            ptr = ptr->next;
        }
    }

    puts("未找到该房间!");
    system("pause");
    system("cls");
}

void stop_rent_house(struct User* p)
{
    system("cls");
    puts("以下是你入住的房子");
    print_user_house(p);
    puts("请选择你停止入住的房子\n如果要退出则直接按回车");
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
            strcpy(ptr->lodger, "无");
            puts("操作成功!");
            Sleep(1000);
            system("cls");
            return;
        }

        ptr = ptr->next;
    }

    puts("执行失败");
    system("pause");
    system("cls");
    return;
}

void print_user_house(struct User* p)
{
    system("cls");
    struct House* ptr = house_head->next;
    printf("%-8s\t%-5s\t%-5s\n", "房屋地址", "房主", "住客");
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
    puts("您确认要注销此用户吗?\n确认按1,取消按0");
    int input;
    while(1)
    {
        scanf("%d", &input);
        getchar();
        if(input == 1)
        {
            if(user_head->next == p)
            {
                //去除关于此用户其他方面的信息
                //房屋
                struct House* tmp = house_head->next;
                {
                    while(tmp != NULL)
                    {
                        if(strcmp(tmp->oner_name, p->oner_name) == 0)
                        {
                            strcpy(tmp->oner_name, "无");
                            strcpy(tmp->lodger, "无");//租客被强制赶出
                        }
                        else if(strcmp(tmp->lodger, p->oner_name) == 0)
                        {
                            strcpy(tmp->lodger, "无");
                        }

                        tmp = tmp->next;
                    }
                }

                //娱乐设施
                struct Facility* ret = facility_head->next;
                while(ret != NULL)
                {
                    if(strcmp(ret->user_name, p->oner_name) == 0)
                    {
                        strcpy(ret->facility_condition, "可用");
                        strcpy(ret->user_name, "无");
                    }

                    ret = ret->next;
                }

                user_head->next = p->next;
                free(p);
            }
            else
            {
                struct User* ptr = user_head->next;
                //使ptr为p的前一个
                while(ptr->next != p)
                {
                    ptr = ptr->next;
                }
                //去除关于此用户其他方面的信息
                //房屋
                struct House* tmp = house_head->next;
                {
                    while(tmp != NULL)
                    {
                        if(strcmp(tmp->oner_name, p->oner_name) == 0)
                        {
                            strcpy(tmp->oner_name, "无");
                            strcpy(tmp->lodger, "无");//租客被强制赶出
                        }
                        else if(strcmp(tmp->lodger, p->oner_name) == 0)
                        {
                            strcpy(tmp->lodger, "无");
                        }

                        tmp = tmp->next;
                    }
                }

                //娱乐设施
                struct Facility* ret = facility_head->next;
                while(ret != NULL)
                {
                    if(strcmp(ret->user_name, p->oner_name) == 0)
                    {
                        strcpy(ret->facility_condition, "可用");
                        strcpy(ret->user_name, "无");
                    }

                    ret = ret->next;
                }

                ptr->next = p->next;
                free(p);
            }
            puts("注销成功!");
            Sleep(1000);
            system("cls");
            return 0;//这里返回值为0会让用户界面input = 0,直接退出
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
    puts("请输入你要删除的房间地址");
    char addr[MAX_ADDRESS];
    s_gets(addr, MAX_ADDRESS);

    while(p != NULL)
    {
        if(strcmp(p->addr, addr) == 0)
        {
            puts("删除成功!");
            previous->next = p->next;
            free(p);
            Sleep(1000);
            system("cls");
            return;
        }

        previous = previous->next;
        p = p->next;
    }

    puts("没有该房间");
    system("pause");
    system("cls");
}

void delete_facility(void)
{
    print_facility();
    struct Facility* previous = facility_head;//previous为p的前一个
    struct Facility* p = facility_head->next;
    puts("请输入你要删除的设施名称");
    char facility_name[MAX_FACILITY_NAME];
    s_gets(facility_name, MAX_FACILITY_NAME);
    while(p != NULL)
    {
        if(strcmp(p->facility_name, facility_name) == 0)
        {
            previous->next = p->next;
            free(p);
            puts("删除成功!");
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

    puts("未找到该设施");
    system("pause");
    system("cls");
}

void delete_bus(void)
{
    print_bus();
    puts("请选择你要删除的班车序号");
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
            puts("删除成功!");
            Sleep(1000);
            system("cls");
            return;
        }

        previous = previous->next;
        p = p->next;
    }

    puts("未找到该班车");
    system("pause");
    system("cls");

}

void print_user(void)
{
    system("cls");
    struct User* p = user_head->next;

    if(p == NULL)
    {
        puts("没有用户");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-16s\t%-16s\t%-6s\t%-12s\n",
                                            "用户名",
                                            "密码",
                                            "姓名",
                                            "电话");
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
        puts("没有房屋");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-12s\t%-5s\t%-5s\n",
                                            "房间地址",
                                            "房主",
                                            "住客");
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
        puts("没有娱乐设施");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-10s\t%-8s\t%-8s\n",
                                            "设施名称",
                                            "设施状态",
                                            "使用用户");
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
        puts("没有班车");
        system("pause");
        system("cls");
        return;
    }
    else
    {
        printf("%-8s\t%-10s\t%-10s\n",
                                            "班车序号",
                                            "出发站",
                                            "终点站");
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
    puts("请选择你的操作:");
    puts("1.创建房屋");
    puts("2.打印所有房屋信息");
    puts("3.打印所有用户信息");
    puts("4.创建娱乐设施");
    puts("5.打印所有娱乐设施信息");
    puts("6.删除娱乐设施");
    puts("7.创建班车");
    puts("8.删除班车");
    puts("9.打印班车");
    puts("10.删除房屋");
    puts("0.退出管理员账户");
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
                puts("输入错误,请重新输入");
                break;
        }
    }while(input);

    begin_menu();
}

int sign_in_administrator(void)
{
    system("cls");
    puts("请输入密码\n如果要退出则直接输入回车");
    char code[10];
    while(1)
    {
        s_gets(code, 10);
        if(strcmp(ADMINISTRATOR_CODE, code) == 0)
        {
            puts("登陆成功!");
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
            puts("密码错误,请重新输入");
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
        system(strColorFormat);   //通过system函数来设置背景颜色

        Sleep(500);  //程序睡眠0.5秒

    }
    return;
}
