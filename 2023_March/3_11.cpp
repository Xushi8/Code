#include<bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     if (prev_permutation(arr.begin(), arr.begin() + n))
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i] << ' ';
//         }
//         cout << endl;
//     }


//     if(next_permutation(arr.begin(), arr.begin() + n))
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i] << ' ';
//         }
//         cout << endl;
//     }

//     if (next_permutation(arr.begin(), arr.begin() + n))
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i] << ' ';
//         }
//         cout << endl;
//     }

//     system("pause");
//     return 0;
// }

// int n;
// vector<int> arr;
// void dfs(int deep)
// {
//     if (deep > n)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             cout << arr[i] << ' ';
//         }
//         cout << endl;
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         int flag = 0;
//         for (int j = 1; j < deep; j++)
//         {
//             if (arr[j] == i)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//         {
//             arr.emplace_back(i);
//             dfs(deep + 1);
//             arr.pop_back();
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n;
//     arr.emplace_back(0);

//     dfs(1);

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a;
//         cin >> a;
//         if (binary_search(arr.begin(), arr.end(), a))
//         {
//             cout << 1 << '\n';
//         }
//         else
//         {
//             cout << 0 << '\n';
//         }
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n;
//     vector<int> a1(n);
//     for (int i = 0; i < n; i++)
//         cin >> a1[i];
//     cin >> m;
//     vector<int> a2(m);
//     for (int i = 0; i < m; i++)
//         cin >> a2[i];

//     // int left = 0, right = n - 1;
//     // int middle;
//     // while (left <= right)
//     // {
//     //     middle = (right - left) / 2;
//     //     if (a1[middle] > a2[0])
//     //     {
//     //         right = middle - 1;
//     //     }
//     //     else if (a1[middle] < a2[0])
//     //     {
//     //         left = middle + 1;
//     //     }
//     //     else
//     //     {
//     //         break;
//     //     }
//     // }

//     // if (a1[middle] != a2[0])
//     // {
//     //     cout << 0 << endl;
//     // }
//     // else if (right - middle + 1 < m)
//     // {
//     //     cout << 0 << endl;
//     // }
//     // else
//     // {
//     //     int flag = 0;
//     //     for (int i = middle, j = 0; j < m; i++, j++)
//     //     {
//     //         if (a1[i] != a2[j])
//     //         {
//     //             flag = 1;
//     //             break;
//     //         }
//     //     }
//     //     if (flag == 1)
//     //     {
//     //         cout << 0 << endl;
//     //     }
//     //     else
//     //     {
//     //         cout << 1 << endl;
//     //     }
//     // }

//     int flag = 0;
//     for (int j = 0; j < m; j++)
//     {
//         if (!binary_search(a1.begin(), a1.end(), a2[j]))
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if (flag == 1)
//     {
//         cout << 0 << endl;
//     }
//     else
//     {
//         cout << 1 << endl;
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
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int tmp;
//         cin >> tmp;
//         auto it = lower_bound(arr.begin(), arr.end(), tmp);
//         cout << it - arr.begin() << '\n';
//     }
//     cout << flush;


//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int tmp;
//         cin >> tmp;
//         auto t1 = lower_bound(arr.begin(), arr.end(), tmp);
//         auto t2 = upper_bound(arr.begin(), arr.end(), tmp);
//         cout << t1 - arr.begin() << ' ' << t2 - arr.begin() << '\n';
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int tt;
//     cin >> tt;
//     set<int> s;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             s.emplace(b);
//             cout << s.size() << '\n';
//         }
//         else
//         {
//             cout << s.count(b) << '\n';
//         }
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     set<int> s;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             s.emplace(b);
//             cout << s.size() << '\n';
//         }
//         else if(a == 1)
//         {
//             cout << s.count(b) << '\n';
//         }
//         else if(a == 2)
//         {
//             s.erase(b);
//         }
//         else
//         {
//             int c;
//             cin >> c;
//             for (auto it = s.lower_bound(b); *it <= c && it != s.end(); it++)
//             {
//                 cout << *it << '\n';
//             }
//         }
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }




// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     multiset<int> s;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             s.emplace(b);
//             cout << s.size() << '\n';
//         }
//         else if (a == 1)
//         {
//             cout << s.count(b) << '\n';
//         }
//         else if (a == 2)
//         {
//             s.erase(b);
//         }
//         else
//         {
//             int c;
//             cin >> c;
//             for (auto it = s.lower_bound(b); *it <= c && it != s.end(); it++)
//             {
//                 cout << *it << '\n';
//             }
//         }
//     }
//     cout << flush;

//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     map<string, int> m;
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int a;
//         string b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             int c;
//             cin >> c;
//             if (m.find(b) != m.end())
//             {
//                 m.erase(m.find(b));
//             }
            
//             m.emplace(pair<string, int>(b, c));
//         }
//         else if(a == 1)
//         {
//             auto it = m.find(b);
//             if (it != m.end())
//                 cout << it->second << '\n';
//             else
//                 cout << 0 << '\n';
//         }
//         else if (a == 2)
//         {
//             m.erase(b);
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     map<string, int> m;
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int a;
//         string b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             int c;
//             cin >> c;
//             if (m.find(b) != m.end())
//             {
//                 m.erase(m.find(b));
//             }

//             m.emplace(pair<string, int>(b, c));
//         }
//         else if (a == 1)
//         {
//             auto it = m.find(b);
//             if (it != m.end())
//                 cout << it->second << '\n';
//             else
//                 cout << 0 << '\n';
//         }
//         else if (a == 2)
//         {
//             m.erase(b);
//         }
//         else if (a == 3)
//         {
//             string c;
//             cin >> c;
//             for (auto it = m.lower_bound(b); it != m.end() && it->first <= c; it++)
//             {
//                 cout << it->first << ' ' << it->second << '\n';
//             }
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }




// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     multimap<string, int> m;
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int a;
//         string b;
//         cin >> a >> b;
//         if (a == 0)
//         {
//             int c;
//             cin >> c;
//             m.emplace(pair<string, int>(b, c));
//         }
//         else if (a == 1)
//         {
//             auto it = m.find(b);
//             if (it != m.end())
//             {
//                 for (int i = 0; i < (int)m.count(b); it++, i++)
//                 {
//                     cout << it->second << '\n';
//                 }
//             }
//         }
//         else if (a == 2)
//         {
//             for (int i = 0; i < (int)m.count(b); i++)
//                 m.erase(b);
//         }
//         else if (a == 3)
//         {
//             string c;
//             cin >> c;
//             for (auto it = m.lower_bound(b); it != m.end() && it->first <= c; it++)
//             {
//                 cout << it->first << ' ' << it->second << '\n';
//             }
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n;
//     vector<int> a1(n);
//     for (int i = 0; i < n; i++) cin >> a1[i];
//     cin >> m;
//     vector<int> a2(m);
//     for (int i = 0; i < m; i++) cin >> a2[i];
//     vector<int> ans(m + n);
//     int i = 0, j = 0, k = 0;
//     while (1)
//     {
//         if (i == n || j == m)
//         {
//             break;
//         }

//         if (a1[i] < a2[j])
//         {
//             ans[k++] = a1[i++];
//         }
//         else if (a1[i] > a2[j])
//         {
//             ans[k++] = a2[j++];
//         }
//         else
//         {
//             if (ans[k - 1] == a1[i])
//             {
//                 i++;
//                 j++;
//             }
//             else
//             {
//                 ans[k++] = a1[i++];
//                 j++;
//             }
//         }
//     }
    
//     if (i == n)
//     {
//         for (int tmp = j; tmp < m; tmp++)
//         {
//             ans[k++] = a2[tmp];
//         }
//     }
//     else
//     {
//         for (int tmp = i; tmp < n; tmp++)
//         {
//             ans[k++] = a1[tmp];
//         }
//     }
//     for (int tmp = 0; tmp < k; tmp++)
//     {
//         cout << ans[tmp] << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n;
//     vector<int> a1(n);
//     for (int i = 0; i < n; i++) cin >> a1[i];
//     cin >> m;
//     vector<int> a2(m);
//     for (int i = 0; i < m; i++) cin >> a2[i];

//     vector<int> ans(min(n, m));
//     int size = set_intersection(a1.begin(), a1.end(), a2.begin(), a2.end(), ans.begin()) - ans.begin();
//     for (int i = 0; i < size; i++)
//     {
//         cout << ans[i] << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }




// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n;
//     vector<int> a1(n);
//     for (int i = 0; i < n; i++) cin >> a1[i];
//     cin >> m;
//     vector<int> a2(m);
//     for (int i = 0; i < m; i++) cin >> a2[i];

//     vector<int> ans(max(n, m));
//     size_t size = set_difference(a1.begin(), a1.end(), a2.begin(), a2.end(), ans.begin()) - ans.begin();
//     for (int i = 0; i < (int)size; i++)
//     {
//         cout << ans[i] << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int a1[200005], a2[200005], ans[200005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m;
//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> a1[i];
//     cin >> m;
//     for (int i = 0; i < m; i++) cin >> a2[i];

//     size_t size = set_symmetric_difference(a1, a1 + n, a2, a2 + m, ans) - ans;
//     for (int i = 0; i < (int)size; i++)
//     {
//         cout << ans[i] << '\n';
//     }

//     cout << flush;
//     ::system("pause");
//     return 0;
// }

// ostream& operator << (ostream& out, char* data)
// {
//     for (int i = 0; i < 32; i++)
//     {
//         cout << (int)data[i];
//     }
//     return out;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     unsigned int n;
//     cin >> n;
//     char data[32] = { 0 };
//     char tmp[32] = { 0 };
//     int j = 0;
//     while (n)
//     {
//         data[j++] = (char)(n % 2);
//         n /= 2;
//     }
//     reverse(data, data + 32);
//     cout << data << '\n';
    
//     for (int i = 0; i < 32; i++)
//     {
//         tmp[i] = !data[i];
//     }
//     cout << tmp << '\n';
    
//     for (int i = 0; i < 31; i++)
//     {
//         tmp[i] = data[i + 1];
//     }
//     tmp[31] = 0;
//     cout << tmp << '\n';

//     for (int i = 31; i > 0; i--)
//     {
//         tmp[i] = data[i - 1];
//     }
//     tmp[0] = 0;
//     cout << tmp << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }

// ostream& operator << (ostream& out, uint32_t* data)
// {
//     for (int i = 0; i < 32; i++)
//     {
//         cout << data[i];
//     }
//     return out;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     uint32_t a, b;
//     cin >> a >> b;
//     uint32_t data[32] = {0};
//     int j = 0;
//     uint32_t tmp = a & b;
//     while (tmp)
//     {
//         data[j++] = tmp % 2;
//         tmp /= 2;
//     }
//     reverse(data, data + 32);
//     cout << data << '\n';
//     memset(data, 0, sizeof(data));

//     tmp = a | b;
//     j = 0;
//     while (tmp)
//     {
//         data[j++] = tmp % 2;
//         tmp /= 2;
//     }
//     reverse(data, data + 32);
//     cout << data << '\n';
//     memset(data, 0, sizeof(data));

//     tmp = a ^ b;
//     j = 0;
//     while (tmp)
//     {
//         data[j++] = tmp % 2;
//         tmp /= 2;
//     }
//     reverse(data, data + 32);
//     cout << data << '\n';
//     memset(data, 0, sizeof(data));

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cout << "35的8进制:" << std::oct << 35 << endl;
//     cout << "35的10进制" << std::dec << 35 << endl;
//     cout << "35的16进制:" << std::hex << 35 << endl;
//     cout << "35的2进制: " << bitset<32>(35) << endl;      //<8>：表示保留8位输出
    

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     // unsigned int a, b;
//     // cin >> a >> b;
//     // cout << bitset<32>(a & b) << '\n';
//     // cout << bitset<32>(a | b) << '\n';
//     // cout << bitset<32>(a ^ b) << '\n';
//     cout << dec << 55 << '\n';
//     cout << hex << 99 << '\n';
//     cout << oct << 98 << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }


// 素数筛
const int SIZE = 10000000;
bool arr[SIZE];
vector<int> prime;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i <= SIZE - 1; i++)
    {
        if (!arr[i])
            prime.emplace_back(i);
        for (const int& p : prime)
        {
            if (p * i > SIZE - 1)
            {
                break;
            }
            
            arr[p * i] = 1;
            
            if (i % p == 0)
            {
                break;
            }
        }
    }
    // ofstream ofs;
    // ofs.open("素数.out", ios::out);
    // for (const int& p : prime)
    // {
    //     ofs << p << '\n';
    // }
    // ofs.close();

    int n;
    while (cin >> n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (binary_search(prime.begin(), prime.end(), i) && binary_search(prime.begin(), prime.end(), 1 + n - i))
                ans++;
        }

        cout << ans << '\n';
    }

    cout << flush;
    system("pause");
    return 0;
}