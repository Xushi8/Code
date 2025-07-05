// #include<stdio.h>
// #include<string.h>
// #define maxn 1010
// int a[maxn];
// int main()
// {
//     int n, k, first = 1;
//     memset(a, 0, sizeof(a));
//     scanf("%d%d", &n, &k);
//     for (int i = 1; i <= k; i++)
//         for (int j = 1; j <= n; j++)
//             if (j % i == 0) a[j] = !a[j];
//     for (int i = 1; i <= n; i++)
//         if (a[i]) { if (first) first = 0; else printf(" "); printf("%d", i); }
//     printf("\n");
//     return 0;
// }

//竖式问题
// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     int count = 0;
//     char s[20], buf[99];
//     scanf("%s", s);
//     for (int abc = 111; abc <= 999; abc++)
//         for (int de = 11; de <= 99; de++)
//         {
//             int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
//             sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
//             int ok = 1;
//             for (int i = 0; i < strlen(buf); i++)
//                 if (strchr(s, buf[i]) == NULL) ok = 0;
//             if (ok)
//             {
//                 printf("<%d>\n", ++count);
//                 printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
//             }
//         }
//     printf("The number of solutions = %d\n", count);
//     return 0;
// }


//重点: 回文词
// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>
// const char* rev = "A 3 HIL JM O 2TUVWXY51SE Z 8 ";
// const char* msg[] = { "not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome" };
// char r(char ch) {
//     if (isalpha(ch)) return rev[ch - 'A'];
//     return rev[ch - '0' + 25];
// }
// int main() {
//     char s[30];
//     while (scanf("%s", s) == 1) {
//         int len = (int)strlen(s);
//         int p = 1, m = 1;
//         for (int i = 0; i < (len + 1) / 2; i++) {
//             if (s[i] != s[len - 1 - i]) p = 0; //不是回文串
//             if (r(s[i]) != s[len - 1 - i]) m = 0; //不是镜像串
//         }
//         printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
//     }
//     return 0;
// }


