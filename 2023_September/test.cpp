#include<stdio.h>
#include<iostream>
#include<deque>
#include <fstream>
using namespace std;

deque<int> de;

int main() {
    int n, a, b;
    ifstream ifs("pour.in");
    ofstream ofs("pour.out");
    // scanf("%d%d%d", &n, &a, &b);
    ifs >> n >> a >> b;
    int flag = 2;
    for (int i = 0;i < n;i++) {
        de.push_back(a);
    }
    int count = 0;
    while (de.size() != 1) {
        int num1, num2;
        num1 = de.front();
        de.pop_front();
        num2 = de.front();
        de.pop_front();
        if (num1 + num2 > b) {
            // printf("%d\n", flag);
            ofs << flag << '\n';
            count = 1;
            break;
        }
        else {
            if (flag == 1) {
                flag = 2;
            }
            else {
                flag = 1;
            }
            de.push_back(num1 + num2);
        }
    }
    if (de.size() == 1 && count == 0) {
        // printf("%d\n", flag);
        ofs << flag << '\n';
    }

    ifs.close();
    ofs.close();

    return 0;
}