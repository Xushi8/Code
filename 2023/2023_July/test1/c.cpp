// // 2023/07/17 14:48:27
// #include <bits/stdc++.h>
// using namespace std;

// inline int get_wetght(char ch)
// {
//     switch (ch)
//     {
//     case '+' :
//     case '-' :
//         return 1;
//     case '*':
//     case '/':
//         return 2;
//     default:
//         return 0;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     string str;
//     cout << setprecision(2) << fixed;
//     while (getline(cin, str) && str.size() != 1)
//     {
//         stack<char> s;
//         stack<double> num;
//         char ch;
//         for (size_t i = 0; i < str.size(); i++)
//         {
//             ch = str[i];
//             int tot = -1;
//             while (isdigit(ch))
//             {
//                 if (tot == -1)
//                     tot = 0;
//                 tot = tot * 10 + ch - '0';
//                 if (i < str.size() - 1)
//                     ch = str[++i];
//                 else
//                     break;
//             }
//             if (tot != -1)
//             {
//                 num.emplace((double)tot);
//             }

//             if (ch == ' ')
//                 continue;

//             if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
//             {
//                 if(s.empty())
//             }
//         }

//         while (!s.empty())
//         {
//             ch = s.top(); s.pop();
//             double b = num.top(); num.pop();
//             double a = num.top(); num.pop();
//             double ans;
//             if (ch == '+')
//                 ans = a + b;
//             else if (ch == '-')
//                 ans = a - b;
//             else if (ch == '*')
//                 ans = a * b;
//             else
//                 ans = a / b;
//             num.emplace(ans);
//         }
//         cout << num.top() << '\n';
//     }

//     cout << flush;
//     return 0;
// }


// 2023/07/17 20:18:19
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;



int main()
{
    char str[205];
    while (fgets(str, 205, stdin))
    {
        size_t size = strlen(str);
        if (size == 2)
            break;

        str[size - 1] = 0;
        stack<double> num;
        stack<char> s;
        char ch;
        for (size_t i = 0; i < strlen(str); i++)
        {
            ch = str[i];
            int tot = -1;
            while (isdigit(ch))
            {
                if (tot == -1)
                    tot = 0;
                tot *= 10;
                tot += ch - '0';
                if (i + 1 < strlen(str))
                    ch = str[++i];
                else
                    ch = ' ';
            }
            if (tot != -1)
                num.emplace((double)tot);

            if (ch == ' ')
                continue;

            if (ch == '*' || ch == '/')
            {
                if (s.empty())
                {
                    s.emplace(ch);
                }
                else
                {
                    while (!s.empty() && (s.top() == '/' || s.top() == '*'))
                    {
                        char tmp = s.top(); s.pop();
                        double b = num.top(); num.pop();
                        double a = num.top(); num.pop();
                        double ans;
                        if (tmp == '*')
                            ans = a * b;
                        else if (tmp == '/')
                            ans = a / b;
                        num.emplace(ans);
                    }
                    s.emplace(ch);
                }
            }
            else if (ch == '+' || ch == '-')
            {
                if (s.empty())
                {
                    s.emplace(ch);
                }
                else
                {
                    while (!s.empty())
                    {
                        char tmp = s.top(); s.pop();
                        double b = num.top(); num.pop();
                        double a = num.top(); num.pop();
                        double ans;
                        if (tmp == '*')
                            ans = a * b;
                        else if (tmp == '/')
                            ans = a / b;
                        else if (tmp == '+')
                            ans = a + b;
                        else if (tmp == '-')
                            ans = a - b;
                        num.emplace(ans);
                    }
                    s.emplace(ch);
                }
            }

        }

        while (!s.empty())
        {
            char tmp = s.top(); s.pop();
            double b = num.top(); num.pop();
            double a = num.top(); num.pop();
            double ans;
            if (tmp == '+')
                ans = a + b;
            else if (tmp == '-')
                ans = a - b;
            else if (tmp == '*')
                ans = a * b;
            else if (tmp == '/')
                ans = a / b;
            num.emplace(ans);
        }

        printf("%.2lf\n", num.top());
    }

    return 0;
}

