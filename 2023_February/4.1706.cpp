#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[10], flag[10];
void dfs(int deep)
{
    if (deep > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%5d", arr[i]);
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == 0)
        {
            flag[i] = 1;
            arr[deep] = i;
            dfs(deep + 1);
            flag[i] = 0;
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> n;
    dfs(1);

    system("pause");
    return 0;
}