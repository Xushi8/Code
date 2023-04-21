#include "game.h"
using namespace std;

const int board_size[4] = { 0,10,20,30 };
const int mine_num[4] = { 0,8,28,48 };
const int INF = 0x3f3f3f3f;
const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int grade = -1;
int find_of_mine = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (1)
    {
        menu();
        int input;
        cin >> input;
        if (input >= 1 && input <= 3)
        {
            grade = input;
            game();
        }
        else
        {
            break;
        }
        system("cls");
    }

    cout << flush;
    return 0;
}

void game()
{
    vector<vector<int>> display_board(board_size[grade] + 1, vector<int>(board_size[grade] + 1, INF)); // 用来打印, INF表示未知
    vector<vector<int>> true_board(board_size[grade] + 1, vector<int>(board_size[grade] + 1, 0)); // 用来布置雷, 1为雷, 2无雷
    vector<vector<int>> count_board(board_size[grade] + 1, vector<int>(board_size[grade] + 1, 0)); // 计算周围雷的数量
    initBoard(true_board, count_board);
    
    while (1)
    {
        displayBoard(display_board, count_board);
        if (!location(display_board, true_board, count_board))
        {
            cout << "你被炸死了\n";
            displayBoard(display_board, count_board);
            break;
        }

        if (check())
        {
            cout << "你赢了!\n";
            displayBoard(display_board, count_board);
            system("pause");
            system("cls");
            break;
        }
    }
}

bool check()
{
    return find_of_mine + mine_num[grade] == board_size[grade] * board_size[grade];
}

bool location(std::vector<std::vector<int>>& display_board, const std::vector<std::vector<int>>& true_board, const std::vector<std::vector<int>>& count_board)
{
    cout << "请选择你要下的位置:> " << flush;
    int x, y;
    while (1)
    {
        cin >> x >> y;
        if (display_board[x][y] == INF)
        {
            if (true_board[x][y] == 1)
            {
                system("cls");
                return false;
            }
            else
            {
                display_board[x][y] = count_board[x][y];
                return true;
            }
        }
        else
        {
            cout << "该位置已探明, 请重选" << endl;
        }
    }
}

void displayBoard(const std::vector<std::vector<int>>& board, const std::vector<std::vector<int>>& count_board)
{
    for (int i = 0; i < grade + 1; i++)
    {
        if (!i)
        {
            for (int k = 0; k < board_size[grade] + 1; k++)
            {
                cout << k << ' ';
            }
            cout << '\n';
            continue;
        }

        for (int j = 0; j < board_size[grade] + 1; j++)
        {
            if (!j)
            {
                cout << i << ' ';
                continue;
            }

            if (board[i][j] == INF)
                cout << "* ";
            else
                cout << count_board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

void initBoard(std::vector<std::vector<int>>& true_board, std::vector<std::vector<int>>& count_board)
{
    int x, y;
    for (int i = 0; i < mine_num[grade]; i++)
    {
        x = rand() % (board_size[grade] + 1) + 1;
        y = rand() % (board_size[grade] + 1) + 1;
        if (true_board[x][y] == 0)
        {
            true_board[x][y] = 1;
        }
        else
        {
            i--;
        }
    }
    for (int i = 1; i < board_size[grade] + 1; i++)
    {
        for (int j = 1; j < board_size[grade] + 1; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int tx = dx[k];
                int ty = dy[k];
                if (tx >= 0 && tx < board_size[grade] + 1 && ty >= 0 && ty < board_size[grade] + 1)
                {
                    count_board[i][j] += true_board[tx][ty];
                }
            }
        }
    }
}

void menu()
{
    cout << "请选择要挑战的等级:>\n";
    cout << "1. 初级\n";
    cout << "2. 中级\n";
    cout << "3. 高级\n";
    cout << "其它. 退出" << endl;
}