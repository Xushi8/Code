// // 2023/04/27 14:12:22
// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     string a;
//     cin >> a;
//     for (int i = 0; i < n; i++)
//     {
//         a[i] -= '0';
//     }
//     vector<string> arr[10];
//     arr[0].insert(arr[0].end(), { "XXX","X.X","X.X","X.X","XXX" });
//     arr[1].insert(arr[1].end(), { "..X","..X","..X","..X","..X" });
//     arr[2].insert(arr[2].end(), { "XXX","..X","XXX","X..","XXX" });
//     arr[3].insert(arr[3].end(), { "XXX","..X","XXX","..X","XXX" });
//     arr[4].insert(arr[4].end(), { "X.X","X.X","XXX","..X","..X" });
//     arr[5].insert(arr[5].end(), { "XXX","X..","XXX","..X","XXX" });
//     arr[6].insert(arr[6].end(), { "XXX","X..","XXX","X.X","XXX" });
//     arr[7].insert(arr[7].end(), { "XXX","..X","..X","..X","..X" });
//     arr[8].insert(arr[8].end(), { "XXX","X.X","XXX","X.X","XXX" });
//     arr[9].insert(arr[9].end(), { "XXX","X.X","XXX","..X","XXX" });
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < n - 1; j++)
//         {
//             cout << arr[j][i] << '.';
//         }
//         cout << arr[n - 1][i];
//         cout << '\n';
//     }

//     cout << endl;
//     return 0;
// }

#include<cstdio>
using namespace std;
char c[10][5][4] = 
{
    "XXX",//0
    "X.X",
    "X.X",
    "X.X",
    "XXX",
    "..X",//1
    "..X",
    "..X",
    "..X",
    "..X",
    "XXX",//2
    "..X",
    "XXX",
    "X..",
    "XXX",
    "XXX",//3
    "..X",
    "XXX",
    "..X",
    "XXX",
    "X.X",//4
    "X.X",
    "XXX",
    "..X",
    "..X",
    "XXX",//5
    "X..",
    "XXX",
    "..X",
    "XXX",
    "XXX",//6
    "X..",
    "XXX",
    "X.X",
    "XXX",
    "XXX",//7
    "..X",
    "..X",
    "..X",
    "..X",
    "XXX",//8
    "X.X",
    "XXX",
    "X.X",
    "XXX",
    "XXX",//9
    "X.X",
    "XXX",
    "..X",
    "XXX"
}, ans[10][1000];
int main() {
    int n, a, s = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%1d", &a);
        for (int i = 0;i < 5;i++)//复制
            for (int j = 0;j < 3;j++)
                ans[i][s + j] = c[a][i][j];
        for (int i = 0;i < 5;i++) ans[i][s + 3] = '.';
        s += 4;
    }
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < s - 1;j++) printf("%c", ans[i][j]);
        printf("\n");
    }
    return 0;
}