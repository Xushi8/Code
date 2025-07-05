#include"10_17.h"

void menu(void)
{
    printf("*********************\n");
    printf("********0.exit*******\n");
    printf("********1.play*******\n");
    printf("*********************\n");
}
void game(void)
{
    char ret;
    char board[ROW][COL];
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    while(1)
    {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if(ret!='C')
            break;
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if(ret!='C')
            break;
    }
    if(ret=='*')
        printf("你赢了\n");
    else if(ret=='#')
        printf("你输了\n");
    else if(ret=='A')
        printf("平局\n");
}
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i;
    for(i = 0; i<row; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i<row-1)
            printf("---|---|---\n");
    }
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
    puts("请输入坐标");
    int x, y;
    while(1)
    {
        scanf("%d %d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1]='*';
                break;
            }
            else
            {
                puts("已被占用,重新输入");
            }
        }
        else
        {
            puts("输入错误,重新输入");
        }
    }
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    puts("电脑走");
    int x, y;
    while(1)
    {
        x = rand()%row;
        y = rand()%col;
        if(board[x][y]==' ')
        {
            board[x][y]='#';
            break;
        }


    }
}
char IsWin(char board[ROW][COL], int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
            return board[i][0];
    }    
    for(i = 0; i < row; i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
            return board[0][i];
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
        return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=' ')
        return board[0][2];
    
    for(i = 0; i<row; i++)
    {
        for(j = 0; j<col; j++)
        {
            if(board[i][j] == ' ')
                return 'C';
        }
    }

    return 'A';
}

int main()
{
    srand((unsigned int)time(NULL)); 
    int input;
    do
    {
        menu();
        printf("请选择\n");
        scanf("%d", &input);
        switch(input)
        {
            case 0:
            printf("游戏结束\n");
            break;
            case 1:
            printf("游戏开始\n");
            game();
            break;
            default:
            printf("请重新选择\n");
            break;
        }
    } while (input);
    
    system("pause");
    return 0;
}