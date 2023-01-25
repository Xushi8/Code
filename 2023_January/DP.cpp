#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

//硬币问题
#define SIZE 100
int dp[SIZE + 1];
int main()
{
    int i;
    dp[0] = 0;
    int cost;
    ofstream ofs;
    ofs.open("dp.out", ios::out);
    for (i = 1; i <= SIZE; i++)
    {
        cost = 2147483647;
        if (i - 1 >= 0) cost = min(dp[i - 1] + 1, cost);
        if (i - 5 >= 0) cost = min(dp[i - 5] + 1, cost);
        if (i - 11 >= 0) cost = min(dp[i - 11] + 1, cost);
        dp[i] = cost;
        //printf("%d枚硬币的最优解: %d\n", i, dp[i]);
        ofs << i << "枚硬币的最优解: " << dp[i] << '\n';
    }
    ofs.close();

    return 0;
}

//01背包重写

int dp[100];
int weight[100], price[100];
int love_min = -2127283648;
int func(int i, int capacity)
{
    if (dp[i] != 0)
    {
        return dp[i];
    }
    
    if (capacity >= weight[i])
    {
        dp[i] = max(func(i - 1, capacity), func(i - 1, capacity - weight[i]) + price[i]);
    }
    else
    {
        dp[i] = func(i - 1, capacity);
    }
    return dp[i];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> price[i];
    }

    func(n, m);

    return 0;
}