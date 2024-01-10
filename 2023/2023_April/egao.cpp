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

    vector<string> arr;
    char buffer[] = "#include <bits/stdc++.h>\nusing namespace std;\nint fib(int n) {\n    if (n <= 2) return 1;\n    else return fib(n - 1) + fib(n - 2);\n}\nint main() {\n    cout << fib(1000) << endl;\n    return 0;\n}";
    for (char i = 0; i < 10; i++)
    {
        string file_name = "test0";
        file_name += i + '0';
        ofstream ofs;
        ofs.open(file_name + ".cpp");
        ofs << buffer;
        ofs.close();
        string tmp = "g++ ";
        tmp += file_name + ".cpp";
        tmp += " -o ";
        tmp += file_name + ".exe";
        char* sys = new char[tmp.size() + 1];
        for (int i = 0; i < tmp.size();i++)
        {
            sys[i] = tmp[i];
        }
        sys[tmp.size()] = 0;
        system(sys);
        delete[] sys;
        
        tmp = file_name + ".exe";
        sys = new char[tmp.size() + 1];
        for (int i = 0; i < tmp.size(); i++)
        {
            sys[i] = tmp[i];
        }
        sys[tmp.size()] = 0;

        arr.emplace_back(sys);
        arr.emplace_back(" &&");
        delete[] sys;
    }
    arr.resize(arr.size() - 1);
    char* tmp = new char[10000];
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        string a = arr[i];
        for (int j = 0; j < a.size(); j++)
        {
            tmp[index++] = a[j];
        }
        tmp[index++] = ' ';
    }
    tmp[index] = 0;
    system(tmp);

    cout << endl;
    system("pause");
    return 0;
}