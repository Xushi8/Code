// /* /* /* // 2023/04/27 14:25:55
// #include <bits/stdc++.h>
// using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     // vector<string> arr[2];
//     // arr[1].emplace_back("lklk", "rkjhffjrew");
//     // vector<string> arr{"ss", "dfsw"};
//     // for (int i = 0; i < arr.size(); i++)
//     // {
//     //     cout << arr[i] << '\n';
//     // }


    
//     // vector<int> s;
//     // s.insert(s.end(), { 2,2,3,4 });
//     // for (int i = 0; i < s.size(); i++)
//     // {
//     //     cout << s[i];
//     // }


//     string s;
//     cout << s.max_size();

//     cout << endl;
//     return 0;
// } */

// // 2023/04/27 22:05:08
// #include <bits/stdc++.h>
// using namespace std;


// struct A { int a[10000]; };
// A a;
// // 值返回
// A TestFunc1() { return a; }
// // 引用返回
// A& TestFunc2() { return a; }
// void TestReturnByRefOrValue()
// {
//     // 以值作为函数的返回值类型
//     size_t begin1 = clock();
//     for (size_t i = 0; i < 10000000; ++i)
//         TestFunc1();
//     size_t end1 = clock();
//     // 以引用作为函数的返回值类型
//     size_t begin2 = clock();
//     for (size_t i = 0; i < 10000000; ++i)
//         TestFunc2();
//     size_t end2 = clock();
//     // 计算两个函数运算完成之后的时间
//     cout << "TestFunc1 time:" << end1 - begin1 << endl;
//     cout << "TestFunc2 time:" << end2 - begin2 << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     TestReturnByRefOrValue();

//     cout << endl;
//     return 0;
// }


// 2023/04/27 22:09:17
#include <bits/stdc++.h>
using namespace std;

ofstream ofs;
void test1(int a)
{
    ofs << a << '\n';
}
void test2(int& a)
{
    ofs << a << '\n';
}
void test3(const int& a)
{
    ofs << a << '\n';
}
class stu
{
public:
    stu(vector<int> a)
    {
        arr = a;
    }

    
    vector<int> arr;
};

void test4(stu s)
{
    for (int i = 0; i < s.arr.size(); i++)
    {
        ofs << s.arr[i] << '\n';
    }
}
void test5(stu& s)
{
    for (int i = 0; i < s.arr.size(); i++)
    {
        ofs << s.arr[i] << '\n';
    }
}
void test6(const stu& s)
{
    for (int i = 0; i < s.arr.size(); i++)
    {
        ofs << s.arr[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofs.open("test.out", ios::out);

    
    // size_t begin1, begin2, begin3, end1, end2, end3;
    // begin1 = clock();
    // for (int i = 0; i < 10000000; i++)
    //     test1(i);
    // end1 = clock();
    // begin2 = clock();
    // for (int i = 0; i < 10000000; i++)
    //     test2(i);
    // end2 = clock();
    // begin3 = clock();
    // for (int i = 0; i < 10000000; i++)
    //     test3(i);
    // end3 = clock();
    // cout << end1 - begin1 << endl;
    // cout << end2 - begin2 << endl;
    // cout << end3 - begin3 << endl;


    vector<stu> arr;
    arr.reserve(100000);
    for (int i = 0; i < 100000; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < 200; j++)
        {
            tmp.emplace_back(i);
        }
        arr.emplace_back(tmp);
    }

    size_t begin4, begin5, begin6, end4, end5, end6;
    begin4 = clock();
    for (int i = 0; i < 1000; i++)
        test4(arr[i]);
    end4 = clock();
    begin5 = clock();
    for (int i = 0; i < 1000; i++)
        test5(arr[i]);
    end5 = clock();
    begin6 = clock();
    for (int i = 0; i < 1000; i++)
        test6(arr[i]);
    end6 = clock();

    cout << end4 - begin4 << endl;
    cout << end5 - begin5 << endl;
    cout << end6 - begin6 << endl;
    cout << endl;
    ofs.clear();
    ofs.close();
    ofs.open("test.out", ios::out);
    ofs.close();

    
    return 0;
}