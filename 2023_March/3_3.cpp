// // // #include<bits/stdc++.h>
// // // using namespace std;



// // // int main()
// // // {
// // //     ios::sync_with_stdio(false);
// // //     cin.tie(0);
    
// // //     vector<int> v;
// // //     int tt = 1000000000;
// // //     v.reserve(tt);
// // //     size_t capacity = v.capacity();
// // //     int cnt = 0;
// // //     while (tt--)
// // //     {
// // //         v.push_back(tt);
// // //         if (capacity != v.capacity())
// // //         {
// // //             capacity = v.capacity();
// // //             cnt++;
// // //         }
// // //     }
// // //     cout << cnt << endl;

// // //     system("pause");
// // //     return 0;
// // // }


// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // ofstream& operator << (ofstream& out, unordered_set<int>& s)
// // // {
// // //     for (auto it = s.begin(); it != s.end(); it++)
// // //     {
// // //         out << *it << ' ';
// // //     }
// // //     return out;
// // // }

// // // int main()
// // // {
// // //     ios::sync_with_stdio(false);
// // //     cin.tie(0);
    
// // //     ofstream ofs;
// // //     ofs.open("unordered_set.out", ios::out);
// // //     unordered_set<int> uset;
// // //     for (int i = 0; i < 100000; i++)
// // //     {
// // //         uset.insert(i);
// // //     }
// // //     ofs << uset << endl;
// // //     ofs.close();
    
    

// // //     system("pause");
// // //     return 0;
// // // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // const int MAX_NAME = 30;

// // class Person
// // {
// // public:
// //     Person& operator ++ ()
// //     {
// //         age++;
// //         return *this;
// //     }
// //     char name[MAX_NAME];
// //     int age;
// // };

// // ostream& operator<< (ostream& out, Person& p)
// // {
// //     cout << "姓名: " << p.name << " 年龄: " << p.age;
// //     return out;
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
// //     Person p;
// //     p.age = 0;
// //     strcpy(p.name, "dfdsffd");
// //     int begin, end;
// //     begin = clock();

// //     for (int i = 0; i < 1000000; i++)
// //     {
// //         cout << ++p << '\n';
// //     }
// //     end = clock();
// //     cout << (end - begin) / 1000.0 << endl;

// //     cout << endl;

// //     system("pause");
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     ofstream ofs;
//     ofs.open("++的区别.out", ios::out | ios::app);

//     list<int> L;
//     int begin, end;
//     for (int i = 0; i < 10000000; i++)
//     {
//         L.push_back(i);
//     }

//     begin = clock();
//     for (auto i = L.begin(); i != L.end(); i++)
//     {
//         cout << *i << '\n';
//     }
//     end = clock();
//     ofs << "list后置" << (end - begin) / 1000.0 << endl;


//     begin = clock();
//     for (auto i = L.begin(); i != L.end(); ++i)
//     {
//         cout << *i << '\n';
//     }
//     end = clock();
//     ofs << "list前置" << (end - begin) / 1000.0 << endl;

//     vector<int> V;
//     for (int i = 0; i < 10000000; i++)
//     {
//         V.push_back(i);
//     }

//     begin = clock();
//     for (auto i = V.begin(); i != V.end(); i++)
//     {
//         cout << *i << '\n';
//     }
//     end = clock();
//     ofs << "vector后置" << (end - begin) / 1000.0 << endl;

//     begin = clock();
//     for (auto i = V.begin(); i != V.end(); ++i)
//     {
//         cout << *i << '\n';
//     }
//     end = clock();
//     ofs << "vector前置" << (end - begin) / 1000.0 << endl;
//     ofs.close();

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    system("pause");
    return 0;
}