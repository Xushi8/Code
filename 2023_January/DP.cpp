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