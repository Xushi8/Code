#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto youxian = [](char ch) {
        if(ch == '*' || ch == '/') {
            return 5;
        }
        if(ch == '+' || ch == '-') {
            return 4;
        }
        if(ch == '(') {
            return 0;
        }

        return -1;
    };

    string s;
    cin >> s;

    stack<pair<int, bool>> num;
    stack<char> sign;



    int tot = -1;
    for (int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            if(tot == -1) {
                tot = 0;
            }
            tot = tot * 10 + s[i] - '0';
            continue;
        }

        if(!isdigit(s[i]) && tot != -1) {
            num.emplace(tot, false);
            tot = -1;
        }

        if(s[i] == '(') {
            sign.emplace(s[i]);
            continue;
        }
        
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while(!sign.empty() && youxian(sign.top()) >= s[i]) {
                char fuhao = sign.top();
                sign.pop();
                auto [b, b_ok] = num.top();
                num.pop();
                auto [a, a_ok] = num.top();
                num.pop();
                if (!a_ok)
                {
                    cout << a;
                }
                cout << fuhao;
                if (!b_ok)
                {
                    cout << b;
                }
                cout << '\n';
                num.emplace(-1, true);
            }

            sign.emplace(s[i]);
        }

        if(s[i] == ')') {
            while(sign.top() != '(') {
                char fuhao = sign.top();
                sign.pop();
                auto [b, b_ok] = num.top();
                num.pop();
                auto [a, a_ok] = num.top();
                num.pop();
                if (!a_ok)
                {
                    cout << a;
                }
                cout << fuhao;
                if(!b_ok) {
                    cout << b;
                }
                cout << '\n';
                num.emplace(-1, true);
            }
            sign.pop();
        }
    }
}