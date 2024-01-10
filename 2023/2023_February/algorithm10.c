// 刽子手游戏
// 样例输入：
// 1
// cheese
// chese
// 2
// cheese
// abcdefg
// 3
// cheese
// abcdefgij
// - 1
// 样例输出:
// Round 1
// You win.
// Round 2
// You chickened out.
// Round 3
// You lose.

// #include<stdio.h>
// #include<string.h>
// #define maxn 100
// int left, chance; //还需要猜left个位置,错chance次之后就会输
// char s[maxn], s2[maxn]; //答案是字符串s,玩家猜的字母序列是s2
// int win, lose; //win=1表示已经赢了;lose=1表示已经输了
// void guess(char ch) {
//     int bad = 1;
//     for (int i = 0; i < strlen(s); i++)
//         if (s[i] == ch) { left--; s[i] = ' '; bad = 0; }
//     if (bad) --chance;
//     if (!chance) lose = 1;
//     if (!left) win = 1;
// }
// int main() {
//     int rnd;
//     while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1) {
//         printf("Round %d\n", rnd);
//         win = lose = 0; //求解一组新数据之前要初始化
//         left = strlen(s);
//         chance = 7;
//         for (int i = 0; i < strlen(s2); i++) {
//             guess(s2[i]); //猜一个字母
//             if (win || lose) break; //检查状态
//         }
//         //根据结果进行输出
//         if (win) printf("You win.\n");
//         else if (lose) printf("You lose.\n");
//         else printf("You chickened out.\n");
//     }
//     return 0;
// }



// n(n < 20)个人站成一圈，逆时针编号为1～n。有两个官员，A从1开始逆时针数，B从n开
//     始顺时针数。在每一轮中，官员A数k个就停下来，官员B数m个就停下来（注意有可能两个
//     官员停在同一个人上）。接下来被官员选中的人（1个或者2个）离开队伍。
//     输入n，k，m输出每轮里被选中的人的编号（如果有两个人，先输出被A选中的）。例
//     如，n = 10，k = 4，m = 3，输出为4 8, 9 5, 3 1, 2 6, 10, 7。注意：输出的每个数应当恰好占3列。


#include<stdio.h>
#define maxn 25
int n, k, m, a[maxn];
//逆时针走t步，步长是d（-1表示顺时针走），返回新位置
int go(int p, int d, int t) {
    while (t--)
    {
        do
        {
            p = (p + d + n - 1) % n + 1;
        } while (a[p] == 0); //走到下一个非0数字(这个do while很巧妙)
    }
    return p;
}
int main() {
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
        for (int i = 1; i <= n; i++) a[i] = i;
        int left = n; //还剩下的人数
        int p1 = n, p2 = 1;
        while (left) {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", p1); left--;
            if (p2 != p1) { printf("%3d", p2); left--; }
            a[p1] = a[p2] = 0;
            if (left) printf(",");
        }
        printf("\n");
    }
    return 0;
}