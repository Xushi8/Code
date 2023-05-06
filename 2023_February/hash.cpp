#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;

    unordered_map<int, int> umap;
    A.push_back(111);
    A.push_back(111);
    A.push_back(111);
    A.push_back(111);
    B.push_back(222);
    B.push_back(222);
    B.push_back(222);
    B.push_back(222);
    B.push_back(222);
    C.push_back(333);
    C.push_back(333);
    C.push_back(333);
    C.push_back(333);
    C.push_back(333);
    D.push_back(4444);
    D.push_back(4444);
    D.push_back(4444);
    D.push_back(4444);
    D.push_back(4444);
    D.push_back(4444);

    for (int a : A)
        for (int b : B)
            umap[a + b]++;

    int ans = 0;
    for (int c : C)
        for (int d : D)
            if (umap.find(0 - (c + d)) != umap.end()) ans += umap[0 - (c + d)];
    cout << ans << endl;


    int my_array[5] = { 1, 2, 3, 4, 5 };

    // 不会改变 my_array 数组中元素的值
    // x 将使用 my_array 数组的副本
    for (int x : my_array)
    {
        x *= 2;
        cout << x << ' ';
    }
    cout << endl;

    // 会改变 my_array 数组中元素的值
    // 符号 & 表示 x 是一个引用变量，将使用 my_array 数组的原始数据
    // 引用是已定义的变量的别名
    for (int& x : my_array)
    {
        x *= 2;
        cout << x << ' ';
    }
    cout << endl;

    for (const int& x : my_array)
    {
        cout << x << ' ';
    }
    cout << endl;

    for (const auto& x : my_array)
    {
        cout << x << ' ';
    }
    cout << endl;

    // 还可直接使用初始化列表
    for (int x : { 1, 2, 3, 4, 5 })
    {
        x *= 2;
        cout << x << ' ';
    }
    cout << endl;
    

    system("pause");
    return 0;
}