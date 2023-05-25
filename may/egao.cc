// 2023/05/11 22:11:18
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n <= 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char buffer[] = "#include <bits/stdc++.h>\nusing namespace std;\nint fib(int n) {\n    if (n <= 2) return 1;\n    else return fib(n - 1) + fib(n - 2);\n}\nint main() {\n    cout << endl;\n    return 0;\n}";
    char file_name[] = "test0";
    for (char i = 0; i < 4; i++)
    {
        strcat(file_name, &i);
    }

    cout << endl;
    return 0;
}