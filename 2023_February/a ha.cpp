#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<fstream>
using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     queue<int> q;
//     q.push(6);
//     q.push(3);
//     q.push(1);
//     q.push(7);
//     q.push(5);
//     q.push(8);
//     q.push(9);
//     q.push(2);
//     q.push(4);
//     vector<int> ans;
//     while (!q.empty())
//     {
//         int tmp;
//         ans.push_back(q.front());
//         q.pop();
//         tmp = q.front();
//         q.pop();
//         q.push(tmp);
//     }
//     for (int i = 0; i < 9; i++)
//         cout << ans[i];
//     cout << endl;

//     system("pause");
//     return 0;
// }


//回文数
// #include<stack>
// int main()
// {
//     string str;
//     cin >> str;
//     int len = (int)str.size();
//     int mid = len / 2 - 1;
//     stack<char> ans;
//     for (int i = 0; i <= mid; i++)
//     {
//         ans.push(str[i]);
//     }

//     int next;
//     if (len % 2 == 0)
//     {
//         next = mid + 1;
//     }
//     else
//     {
//         next = mid + 2;
//     }
//     for (int i = next; i < len; i++)
//     {
//         if (str[i] != ans.top())
//         {
//             break;
//         }
//         ans.pop();
//     }
//     if (!ans.empty())
//     {
//         cout << "NO!" << endl;
//     }
//     else
//     {
//         cout << "YES!" << endl;
//     }

//     system("pause");
//     return 0;
// }

//放数字满足 xxx + xxx = xxx

// int arr[10];
// int flag[10];
// int num;
// void dfs(int step)
// {
//     if (step == 10)
//     {
//         if (arr[1] * 100 + arr[2] * 10 + arr[3] + arr[4] * 100 + arr[5] * 10 + arr[6] ==
//             arr[7] * 100 + arr[8] * 10 + arr[9])
//         {
//             num++;
//             printf("%d%d%d + %d%d%d = %d%d%d\n", arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
//         }

//         return;
//     }

//     for (int i = 1; i <= 9; i++)
//     {
//         if (flag[i] == 0)
//         {
//             flag[i] = 1;
//             arr[step] = i;
//             dfs(step + 1);
//             flag[i] = 0;
//         }
//     }
// }
// int main()
// {
//     dfs(1);
//     cout << num;

//     return 0;
// }

//迷宫

// int next[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
// void dfs(int x, int y, int step)
// {
//     for (int i = 0; i < 4; i++)
//     {
//         int tx = ::next[i][0];
//         int ty = ::next[i][1];

        
//     }
// }
// int main()
// {


//     return 0;
// }

int arr[20], n, cnt;
ofstream ofs;

bool check(int x, int y)
{
    for (int i = 1; i < x; i++)
    {
        if (arr[i] == y) return false;
        if (i + arr[i] == x + y) return false;
        if (i - arr[i] == x - y) return false;
    }

    return true;
}

void print(void)
{
    // //这里画图
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (arr[i] == j) ofs << '+';
    //         else ofs << '-';
    //     }
    //     ofs << '\n';
    // }
    
    for (int i = 1; i <= n; i++)
    {
        ofs << arr[i] << ' ';
    }
    
    ofs << endl;
}

void dfs(int row)
{
    if (row > n)
    {
        cnt++;
        //print();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check(row, i))
        {
            arr[row] = i;
            dfs(row + 1);
            arr[row] = 0;
        }
    }
}

int main()
{
    ofs.open("queen.out", ios::out);
    
    for (n = 1; n <= 17; n++)
    {
        int begin = clock();
        dfs(1);
        int end = clock();
        ofs << (double)(end - begin) / 1000.0 << 's' << endl;
        ofs << n << ' ' << cnt << endl;
        cnt = 0;
        ofs << endl;
    }
    
    ofs.close();

    return 0;
}