#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int arr[10] = {0};
//     for(int i = 1; i<=n; i++)
//     {
//         int j = i;
//         while(1)
//         {
//             if(j == 0)
//             {
//                 break;
//             }
//             arr[j%10]++;
//             j/=10;
//         }
//     }
//     for(int i = 0; i<9; i++)
//     {
//         printf("%d\n", arr[i]);
//     }
//     return 0;
// }

// int main()
// {
//     char arr[20][10];
//     int n;
//     scanf("%d", &n);
//     getchar();
//     for(int i = 0; i<n; i++)
//     {
//         gets(arr[i][10]);
//     }
//     for(int i = 0; i<n; i++)
//     {
//         for(int j = 0; j<n-1; j++)
//         {
//             if(strcmp(arr[i][j], arr[i][j+1]) == -1)
//             {
//                 char tmp[10];
//                 strcpy(tmp,arr[i][j]);
//                 strcpy(arr[i][j], arr[i][j+1]);
//                 strcpy(arr[i][j+1], tmp);
//             }
//         }
//     }
//     for(int i = 0; i<n; i++)
//     {
//         printf("%s", arr[i][10]);
//     }
//     return 0;
// }

// typedef struct timu
// {
//     int height;
//     int left;
//     int right;
//     int xuhao;
// }timu;
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     timu ti[1000];
//     int i,j,k;
//     for(i = 0; i<n; i++)
//     {
//         scanf("%d %d %d", &ti[i].height, &ti[i].left, &ti[i].right);
//         ti[i].xuhao = i+1;
//     }
//     for(i = 0; i<n; i++)
//     {
//         for(j = 0; j<n-i-1; j++)
//         {
//             if(ti[j].height < ti[j+1].height)
//             {
//                 timu tmp;
//                 tmp = ti[j];
//                 ti[j] = ti[j+1];
//                 ti[j+1] = tmp;
//             }
//         }
//     }

//     for(i = 1; i<=n; i++)
//     {
//         //找到该序号位置
//         for(j = 0; j<n; j++)
//         {
//             if(ti[j].xuhao == i)
//             {
//                 break;
//             }
//         }
//         //找到比该序号高度小的序号的位置
//         for(k = 0; k<n; k++)
//         {
//             if(ti[k].height < ti[j].height)
//             {
//                 break;
//             }
//         }
//         int ret[4] = {0};
//         for(; k<n; k++)
//         {
//             if(ti[j].left > ti[k].left && ti[j].left < ti[k].right && ret[0] == 0)
//             {
//                 ret[0]++;
//                 ret[2] = ti[k].xuhao;
//             }
//             if(ti[j].right > ti[k].left && ti[j].right < ti[k].right && ret[1] == 0)
//             {
//                 ret[1]++;
//                 ret[3] = ti[k].xuhao;
//             }
//             if(ret[0] == 1 && ret[1] == 1)
//             {
//                 break;
//             }
//         }
//         printf("%d %d\n", ret[2], ret[3]);
//     }

//     return 0;
// }


// int main()
// {
//     int max = -1; 
//     int judje;
//     char ticket[1000];
//     char ticket1[1000];
//     int n;
//     scanf("%d", &n);
//     getchar();
//     getchar();
//     int i;
//     for(i = 1; i<=n; i++)
//     {
//         gets(ticket);
//         int ret = strlen(ticket);
//         if(ret > max)
//         {
//             strcpy(ticket1, ticket);
//             judje = i;
//             max = ret;
//         }
//         else if(ret == max)
//         {
//             if(strcmp(ticket1, ticket) < 0)
//             {
//                 strcpy(ticket1, ticket);
//                 judje = i;
//             }
//         }
//     }
//     printf("%d\n%s", judje, ticket1);
//     return 0;
// }



union counter//定义new_res共同体存储波兰表达式
{
    char ch;
    float num;
}new_res[100] = {0};
char res[1000] = {0};//输入的中缀表达式
int flag[100] = {0};//与new_res一一对应的判断数组元素类型的flag数组
int n = 0;//flag下标
int i = 1;//循环判断标志

int element();//将中缀表达式转换为后缀表达式存储与new_res中
int count(union counter new_res[100], int flag[100]);//将波兰表达式计算并输出结果

int main()
{
    while(i)
    {
        element();
        count(new_res, flag);
        printf("您还要继续嘛？继续请输入1，退出请输入0:");
        scanf("%d",&i);
    }
    return 0;
}

int element()
{
    char stack_op[50] = {0};//运算符栈
    char temp[100] = {0};
    int j = 0;
    int m = 0;//运算符栈下标

    n = 0;//循环后重置flag下标
    printf("计算：");
    scanf("%s", res);
    for (int i = 0; i < strlen(res)+1; i++)//strlen(res)+1确保最后一位数据被写入
    {
        if (isdigit(res[i]) || res[i] == '.')
        {
            temp[j++] = res[i];
        }
        else if (!isdigit(res[i]) && (strcmp(temp,"")!=0))//将temp中存储的数据转换为float类型写给new_res
        {
            temp[j] = '\0';
            new_res[n].num = atof(temp);
            flag[n] = 0;
            n++;
            memset(temp,'\0',sizeof(temp));
            j = 0;
        }
        switch (res[i])//判断运算符的优先级决定出栈入栈
        {
        case '(':
            stack_op[m++] = res[i];
            break;
        case '+':
        case '-':
            if (m == 0 || stack_op[m-1] == '(')
            {
                stack_op[m++] = res[i];
            }
            else
            {
                m--;
                new_res[n].ch = stack_op[m];
                flag[n] = 1;
                n++;
                i--;
            }
            break;
        case '*':
        case '/':
            if (m == 0 || stack_op[m-1] !='*' || stack_op[m-1] != '/')
            {
                stack_op[m++] = res[i];
            }
            else
            {
                m--;
                new_res[n].ch = stack_op[m];
                flag[n] = 1;
                n++;
                i--;
            }
            break;
        case ')':
            m--;
            while(stack_op[m] != '(')
            {
                new_res[n].ch = stack_op[m];
                flag[n] = 1;
                n++;
                m--;
            }
            stack_op[m] == 0;
            break;
        default:
            break;
        }
    }
    for (int k = m-1; k >= 0; k--)//将栈中剩余的运算符全部写入new_res
    {
        new_res[n].ch = stack_op[k];
        flag[n] = 1;
        n++;
    }
    
    return 0;
}

int count(union counter new_res[100], int flag[100])
{
    int x = 0;//数据栈下标
    float stack_num[100] = {0};//数据栈
    
    for (int i = 0; i < n; i++)
    {
        switch (flag[i])//判断new_res中的数据类型
        {
        case 0://将数据写入到栈中
            stack_num[x++] = new_res[i].num;
            break;
        case 1://运算
            switch (new_res[i].ch)
            {
            case '+':
                x --;
                stack_num[x-1] += stack_num[x];
                break;
            case '-':
                x --;
                stack_num[x-1] -= stack_num[x];
                break;
            case '*':
                x --;
                stack_num[x-1] *= stack_num[x];
                break;
            case '/':
                x --;
                if (stack_num[x] != 0)
                {
                    stack_num[x-1] /= stack_num[x];
                }
                else
                {
                    printf("除零错误\n");
                    exit(0);
                }
                break;
            default:
                break;
            }
        default:
            break;
        }
    }
    printf("结果：%f\n", stack_num[0]);
    return 0;
}
