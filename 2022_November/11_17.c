#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <windows.h>

void begin_menu(void);

void user(void);

void sign_in_user(void);

void new_user(void);

#define MAX_USER_NAME 15
#define MAX_ADDRESS 20
#define MAX_CONDITION 10
typedef struct HOUSE
{
    char user_name[MAX_USER_NAME];
    char addr[MAX_ADDRESS];//地址
    char condition[MAX_CONDITION];//记录房屋出租,入住等状态
}HOUSE;
typedef struct House
{
    HOUSE* house_data;
    int index;
    int capacity;
}House;

int main(void)
{
    begin_menu();
    int input;
    do
    {
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                user();
                break;
            case 2:
                new_user();
                break;
            case 0:
                break;
            default:
                puts("输入错误,请重新输入");
                break;
        }
    }while(input);    
    
    return 0;
}

void begin_menu(void)
{
    puts("请选择你的操作:");
    puts("0.退出");
    puts("1.登录您的账户");
    puts("2.创建新的账户");
}

void new_user(void)
{

}

void user(void)
{
    sign_in_user();
    system("cls");
    Sleep(500);
    begin_menu();
}

void sign_in_user(void)
{

    system("cls");
    Sleep(500);
    begin_menu();
}

// void first_construct_house(void)
// {
//     //创建及录入房间信息
//     House house;
//     house.house_data = (HOUSE*)malloc(3*sizeof(HOUSE));
//     FILE* fp = fopen("data.data", "a+b");
//     rewind(fp);
//     int i;
//     puts("请输入房间的位置");
//     for(i=0; i<3; i++)
//     {
//         scanf("%s", house.house_data[i].addr);
//         strcpy(house.house_data[i].condition, "未出售");
//         fwrite(&house.house_data[i], sizeof(HOUSE), 1, fp);
//     }
//     house.index = 0;
//     house.capacity = 3;
//     fclose(fp);
// }

// void Administrator(void)
// {
//     if(Sign_in_Administrator() == 0)
//     {
//         return;
//     }

//     puts("请选择你的操作:");
//     puts("1.创建房屋");
//     puts("2.创建娱乐设施");
//     puts("0.退出管理员账户");

//     int input;
//     do
//     {
//         scanf("%d", &input);
//         switch(input)
//         {
//             case 1:
//                 Construct_house();
//                 break;
//             case 2:
//                 break;
//             case 3:
//                 break;
//             case 0:
//                 break;
//             default:
//                 puts("输入错误,请重新输入");
//                 break;
//         }
//     }while(input);

// }

// int Sign_in_Administrator(void)
// {
//     puts("请输入密码\n如果要退出该步骤则输入0");
//     char code[10];
//     while(1)
//     {
//         scanf("%s",code);
//         if(!strcmp(ADMINISTRATOR_CODE, code))
//         {
//             puts("登陆成功!");
//             puts("-----------------------");
//             return 1;
//         }
//         else if(!(code[0]-'0'))
//         {
//             puts("-----------------------");
//             return 0;
//         }
//         else
//         {
//             puts("密码错误,请重新输入");
//         }
//     }
// }




