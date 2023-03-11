// // #include<bits/stdc++.h>
// // using namespace std;

// // void test1(const vector<int> v)
// // {
// //     for (auto i = v.begin(); i != v.end(); i++)
// //     {
// //         cout << *i << '\n';
// //     }
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
    
// //     vector<int> V;
// //     V.reserve(10);
// //     for (int i = 0; i < 10; i++)
// //     {
// //         V[i] = rand();
// //     }
    
// //     for (int i = 0; i < 10; i++)
// //     {
// //         cout << V[i] << '\n';
// //     }
// //     cout << endl;

// //     sort(V.begin(), V.end());
    
// //     for (int i = 0; i < 10; i++)
// //     {
// //         cout << V[i] << '\n';
// //     }
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

//     srand((unsigned int)time(NULL));
//     int n;
//     cin >> n;
//     ofstream ofs;
//     ofs.open("data.out", ios::out);
//     ofs << n << '\n';
//     for (int i = 0; i < n; i++)
//     {
//         ofs << rand() << '\n';
//     }

//     int tt;
//     cin >> tt;
//     ofs << tt << '\n';
//     for (int i = 0; i < tt; i++)
//     {
//         ofs << rand() << '\n';
//     }

//     ofs.close();


//     system("pause");
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = 8, b = 23;
    cout << (a | b) << endl;

    
    cout << flush;
    system("pause");
    return 0;
}