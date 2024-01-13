// 2024/01/10 22:55:23
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

double calc(double a, double b, char sign)
{
    if (sign == '+')
    {
        return a + b;
    }
    else if (sign == '-')
    {
        return a - b;
    }
    else if (sign == '*')
    {
        return a * b;
    }
    else
    {
        return a / b;
    }
}

void solve(string const& s)
{
    stack<double> nums;
    stack<char> signs;
    int now = -1;
    for (char ch : s)
    {
        if (isspace(ch))
        {
            continue;
        }
        if (isdigit(ch))
        {
            if (now == -1)
                now = 0;
            now = now * 10 + ch - '0';
            continue;
        }

        if (now != -1)
        {
            nums.emplace(now);
            now = -1;
        }

        if (ch == '+' || ch == '-')
        {
            while (!signs.empty())
            {
                char tmp = signs.top();
                signs.pop();
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.emplace(calc(a, b, tmp));
            }
            signs.emplace(ch);
        }
        else if (ch == '*' || ch == '/')
        {
            while (!signs.empty() && (signs.top() == '*' || signs.top() == '/'))
            {
                char tmp = signs.top();
                signs.pop();
                double b = nums.top();
                nums.pop();
                double a = nums.top();
                nums.pop();
                nums.emplace(calc(a, b, tmp));
            }
            signs.emplace(ch);
        }
    }

    nums.emplace(now);

    while (!signs.empty())
    {
        char tmp = signs.top();
        signs.pop();
        double b = nums.top();
        nums.pop();
        double a = nums.top();
        nums.pop();
        nums.emplace(calc(a, b, tmp));
    }
    cout << nums.top() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cout << setprecision(2) << fixed;
    while (getline(cin, s) && !(s.size() == 1 && s[0] == '0'))
    {
        solve(s);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}