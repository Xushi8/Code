// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // void test1(const vector<int> v)
// // // {
// // //     for (auto i = v.begin(); i != v.end(); i++)
// // //     {
// // //         cout << *i << '\n';
// // //     }
// // // }

// // // int main()
// // // {
// // //     ios::sync_with_stdio(false);
// // //     cin.tie(0);
    
// // //     vector<int> V;
// // //     V.reserve(10);
// // //     for (int i = 0; i < 10; i++)
// // //     {
// // //         V[i] = rand();
// // //     }
    
// // //     for (int i = 0; i < 10; i++)
// // //     {
// // //         cout << V[i] << '\n';
// // //     }
// // //     cout << endl;

// // //     sort(V.begin(), V.end());
    
// // //     for (int i = 0; i < 10; i++)
// // //     {
// // //         cout << V[i] << '\n';
// // //     }
// // //     cout << endl;

// // //     system("pause");
// // //     return 0;
// // // }


// // #include<bits/stdc++.h>
// // using namespace std;



// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);

// //     srand((unsigned int)time(NULL));
// //     int n;
// //     cin >> n;
// //     ofstream ofs;
// //     ofs.open("data.out", ios::out);
// //     ofs << n << '\n';
// //     for (int i = 0; i < n; i++)
// //     {
// //         ofs << rand() << '\n';
// //     }

// //     int tt;
// //     cin >> tt;
// //     ofs << tt << '\n';
// //     for (int i = 0; i < tt; i++)
// //     {
// //         ofs << rand() << '\n';
// //     }

// //     ofs.close();


// //     system("pause");
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int a = 8, b = 23;
//     cout << (a | b) << endl;

    
//     cout << flush;
//     system("pause");
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     string a, b;
//     cin >> a >> b;
//     if (a == b)
//     {
//         cout << "yes" << endl;
//     }
//     else
//     {
//         cout << "no" << endl;
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    uint64_t a, b;
    a = 288512403048505424;
    b = 288512403048505408;
    cout << bitset<64>(a) << endl;
    cout << bitset<64>(b) << endl;

    string str;
    cin >> str;
    uint64_t ans = 0;
    for (int i = 63; i >= 0; i--)
    {
        ans += (str[i] - 48) * pow(2.L, 63 - i);
    }
    cout << ans << endl;


    cin >> str;
    ans = 0;
    for (int i = 63; i >= 0; i--)
    {
        ans += (str[i] - 48) * pow(2, 63 - i);
    }
    cout << ans << endl;


    cout << flush;
    system("pause");
    return 0;
}