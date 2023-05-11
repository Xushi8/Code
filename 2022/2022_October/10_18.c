#include "10_18.h"

//猜数字
/* void menu(void)
{
    printf("*****0.exit*****\n");
    printf("*****1.play*****\n");
}
int main()
{
    srand((unsigned int)time(NULL));
    int b;
    int input;
    do
    {
        menu();
        scanf("%d", &input);
        int a = rand()%101;

        while(input)
        {
            printf("请输入你要猜的数字\n");
            scanf("%d", &b);

            if(a>b)
                printf("猜小了\n");
            else if(a<b)
                printf("猜大了\n");
            else
            {
                printf("猜对了\n");
                break;
            }
        }
        if(input == 0)
            return 0;

    }while(input);

    system("pause");
    return 0;
} */

//素数
/* int primeNumbers(int);

int primeNumbers(int n)
{   int i;
    for(i = 2; i<sqrt(n); i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int ret = primeNumbers(n);
    if(ret == 1)
        printf("是\n");
    else
        printf("不是\n");

    system("pause");
    return 0;
} */

void menu(void)
{
    printf("****************\n");
    printf("**** 0.exit ****\n");
    printf("**** 1.play ****\n");
    printf("****************\n");
}
void game(void)
{
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);
    FindMine(mine, show, ROW, COL);
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i, j;
    for(i = 0; i<rows; i++)
    {
        for(j = 0; j<cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i, j;
    printf("-----------------\n");
    for(i = 0; i<=row; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for(i = 1; i<=row; i++)
    {
        printf("%d ", i);
        for(j = 1; j<=col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");

    }
    printf("-----------------\n");

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = 10;
    int x, y;
    while(count)
    {
        x = rand()%row+1;
        y = rand()%col+1;
        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x, y;
    while(1)
    {
        puts("请输入坐标");
        scanf("%d%d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(mine[x][y] == '1')
            {
                puts("你被炸死了");
                DisplayBoard(mine, row, col);
                break;
            }
            else
            {
                show[x][y] = GetMineCount(mine, x, y) + '0';
                DisplayBoard(show, ROW, COL);

            }
        }
        else
        {
            puts("输入错误,请重新输入");
        }
    }
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
    return mine[x-1][y-1]+
           mine[x-1][y]+ 
           mine[x-1][y+1]+ 
           mine[x][y-1]+ 
           mine[x][y+1]+ 
           mine[x+1][y-1]+ 
           mine[x+1][y]+ 
           mine[x+1][y+1] -8*'0';
}
int main()
{
    srand((unsigned int)time(NULL));
    int input;
    do
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            puts("游戏开始");
            game();
            break;
        case 0:
            puts("游戏结束");
            break;
        default:
            puts("输入错误,请重新输入");
            break;
        }
    } while (input);

    system("pause");
    return 0;
}