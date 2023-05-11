#include<bits/stdc++.h>
using namespace std;

// // 前缀和
// int arr[100005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     vector<vector<int>> v;
//     uint64_t ans;
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//         arr[i] += arr[i - 1];
//     }
//     string str;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> str;
//         if (str == "ADD")
//         {
//             vector<int> tmp;
//             int a, b;
//             cin >> a >> b;
//             tmp.push_back(a);
//             tmp.push_back(b);
//             v.push_back(tmp);
//         }
//         else
//         {
//             int a, b;
//             cin >> a >> b;
//             ans = arr[b] - arr[a - 1];
//             for (const auto& tmp : v)
//             {
//                 if (tmp[0] >= a && tmp[0] <= b)
//                 {
//                     ans += tmp[1];
//                 }
//             }
//             cout << ans << endl;
//         }
//     }


//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     int a, b, c;
//     a = n / 3600;
//     n -= 3600 * a;
//     b = n / 60;
//     n -= 60 * b;
//     c = n;
//     printf("%d:%d:%d", a, b, c);


//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     cout << n * n * n << endl;

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     cin >> a >> b;
//     cout << a * b << ' ' << 2 * a + 2 * b << endl;

//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cout << "#include<stdio.h>" << endl;
//     cout << "int main()" << endl;
//     cout << "{" << endl;
//     cout << "printf(\"Hello World!\\n\");" << endl;
//     cout << "return 0;" << endl;
//     cout << "}" << endl;
    
//     system("pause");
//     return 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int arr[3];
//     cin >> arr[0] >> arr[1] >> arr[2];
//     sort(arr, arr + 3);
//     cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int arr[3];
//     while (cin >> arr[0] >> arr[1] >> arr[2])
//     {
//         sort(arr, arr + 3);
//         cout << arr[0] << "->" << arr[1] << "->" << arr[2] << endl;
//     }
    

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     vector<int> arr;
//     int tt;
//     cin >> tt;
//     int a, b;
//     while (tt--)
//     {
//         cin >> a;
//         if (a == 0) cin >> b, arr.push_back(b);
//         else if (a == 1) cin >> b, cout << arr[b] << endl;
//         else arr.pop_back();
//     }

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     deque<int> d;
//     int tt;
//     cin >> tt;
//     int a, b, c;
//     while (tt--)
//     {
//         cin >> a;
//         if (a == 0)
//         {
//             cin >> b >> c;
//             if (b == 0) d.push_front(c);
//             else d.push_back(c);
//         }
//         else if (a == 1)
//         {
//             cin >> b;
//             cout << d[b] << endl;
//         }
//         else
//         {
//             cin >> b;
//             if (b == 0) d.pop_front();
//             else d.pop_back();
//         }
//     }

//     system("pause");
//     return 0;
// }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    list<int> L;
    int tt;
    cin >> tt;
    int a, b;
    list<int>::iterator it = L.begin();
    while (tt--)
    {
        cin >> a;
        if (a == 0)
        {
            cin >> b;
            L.emplace(it, b);
            --it;
        }
        else if (a == 1)
        {
            cin >> b;
            if (b > 0)
            {
                while (b--)
                    it++;
            }
            else
            {
                while (b++)
                {
                    it--;
                }
            }
        }
        else
        {
            if (it != L.end())
            {
                list<int>::iterator tmp = ++it;
                it--;
                L.erase(it);
                it = tmp;
            }
        }
    }
    for (it = L.begin(); it != L.end(); it++)
    {
        cout << *it << endl;
    }

    system("pause");
    return 0;
}


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     list<int> L;
//     list<int>::iterator it = L.begin();
//     L.emplace(it, 5);
//     L.emplace(it, 10);
//     L.emplace(it, 15);
//     L.emplace(it, 20);
//     cout << *it << endl;
//     it = L.end();
//     cout << *it << endl;
//     it--;
//     cout << *it << endl;
//     it = L.begin();
//     cout << *it << endl;
//     it--;
//     cout << *it << endl;



//     system("pause");
//     return 0;
// }


// int main(void) {
//     list<int> l = { 3, 4, 5 };

//     auto it = l.emplace(l.begin(), 2);

//     l.emplace(it--, 10);
//     l.emplace(it--, 50);
//     l.emplace(it--, 60);

//     cout << "List contains following element" << endl;

//     for (auto it = l.begin(); it != l.end(); ++it)
//         cout << *it << endl;

//     return 0;
// }