#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 1e3;
string str1, str2;//输入操作数

int num1[N], num2[N];//转化后的操作数
int num3[N];
void transfer(string s, int n[]);
void print(int n[]);

void add(int n1[], int n2[], int n3[]);
void sub(int n1[], int n2[], int n3[]);
bool comp(int n1[], int n2[]);

void mul(int n1[], int k, int n3[]);
void mul(int n1[], int n2[], int n3[]);

void div(int n1[N], int k, int n3[]);
int main() {
    //1.读入
    cin >> str1 >> str2;
    //2.存储转化
    transfer(str1, num1);
    transfer(str2, num2);
    //3.计算
//    add(num1,num2,num3);

    //3.减法
//    if(comp(num1,num2)){
//        sub(num1,num2,num3);
//        print(num3);
//    }else{
//        sub(num2,num1,num3);
//        cout<<"-";
//        print(num3);
//    }

    //3.乘法：高*低
   mul(num1,100,num3);
   mul(num1,num2,num3);
   print(num3);

    // div(num1, 99, num3);
    // print(num3);

    return 0;
}

void transfer(string s, int n[]) {
    int len = s.size();

    n[0] = len;//操作数的长度；
    for (int i = 0; i < len; ++i) {
        n[i + 1] = s[len - 1 - i] - '0';
    }
}

void print(int n[]) {
    for (int i = n[0]; i >= 1; i--) {
        cout << n[i];
    }
}

/**
 * n1 + n2 -> n3
 * @param n1
 * @param n2
 * @param n3
 */
void add(int n1[], int n2[], int n3[]) {
    int d[N] = { 0 };
    int len = max(n1[0], n2[0]);

    for (int i = 1; i <= len; ++i) {
        d[i] += n1[i] + n2[i];
        d[i + 1] = d[i] / 10;
        d[i] = d[i] % 10;
    }

    //4.处理前导0
    int l = len + 1;

    while (d[l] == 0 && l > 1) {
        l--;
    }
    d[0] = l;
    memcpy(n3, d, N * sizeof(int));
}

void sub(int n1[], int n2[], int n3[]) {
    int d[N] = { 0 };
    int len = n1[0];

    for (int i = 1;i <= len;i++) {
        if (n1[i] < n2[i]) {
            n1[i + 1]--;
            n1[i] += 10;
        }
        d[i] = n1[i] - n2[i];
    }

    int l = len;

    while (d[l] == 0 && l > 1) {
        l--;
    }
    d[0] = l;
    memcpy(n3, d, N * sizeof(int));
}

bool comp(int n1[], int n2[]) {
    if (n1[0] != n2[0]) {
        return n1[0] > n2[0];
    }    
else {
        int len = n1[0];
        for (int i = len; i >= 1; i--) {
            if (n1[i] != n2[i]) {
                return n1[i] > n2[i];
            }
        }
        return true;
    }
}

/**
 * 高精度*低精度
 * @param n1
 * @param k
 * @param n3
 */
void mul(int n1[], int k, int n3[]) {
    int d[N] = { 0 };
    int len = n1[0];

    for (int i = 1; i <= len; ++i) {
        d[i] += n1[i] * k;
        d[i + 1] = d[i] / 10;
        d[i] = d[i] % 10;
    }

    //处理进位
    int l = len + 1;
    while (d[l] >= 10) {
        d[l + 1] = d[l] / 10;
        d[l] = d[l] % 10;
        l++;
    }

    //前导0
    while (d[l] == 0 && l > 1) {
        l--;
    }
    d[0] = l;
    memcpy(n3, d, N * sizeof(int));
}

void mul(int n1[], int n2[], int n3[]) {
    int d[N] = { 0 };

    //n1[i] * n2[j]结果放在d[i+j-1]
    for (int i = 1; i <= n1[0]; ++i) {
        for (int j = 1; j <= n2[0]; ++j) {
            int t = i + j - 1;
            d[t] += n1[i] * n2[j];
            d[t + 1] += d[t] / 10;
            d[t] = d[t] % 10;
        }
    }

    int l = n1[0] + n2[0];
    while (d[l] == 0 && l > 1) {
        l--;
    }
    d[0] = l;
    memcpy(n3, d, N * sizeof(int));
}

void div(int n1[N], int k, int n3[]) {
    int d[N] = { 0 };
    int r = 0;
    for (int i = n1[0]; i >= 1; i--) {
        int sum = r * 10 + n1[i];
        d[i] = sum / k;
        r = sum % k;
    }
    //前导0
    int l = n1[0];
    while (d[l] == 0 && l > 1) {
        l--;
    }
    d[0] = l;
    memcpy(n3, d, N * sizeof(int));
}