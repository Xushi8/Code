#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

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
    //这里画图
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i] == j) ofs << '+';
            else ofs << '-';
        }
        ofs << '\n';
    }

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

    // for (n = 1; n <= 17; n++)
    // {
    //     int begin = clock();
    //     dfs(1);
    //     int end = clock();
    //     ofs << (double)(end - begin) / 1000.0 << 's' << endl;
    //     ofs << n << ' ' << cnt << endl;
    //     cnt = 0;
    //     ofs << endl;
    // }

    cout << "请输入你要查询的皇后的数目" << endl;
    cin >> n;
    int begin = clock();
    dfs(1);
    int end = clock();
    ofs << "用时: " << (end - begin) / 1000.0 << 's';
    ofs << "\n结果: " << cnt << endl;
    ofs.close();

    
    return 0;
}