#include<bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     bool arr[64] = { 0 };
//     int tt;
//     cin >> tt;
//     int flag = 0;
//     uint64_t ans;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a;
//         switch (a)
//         {
//         case 0:
//             cin >> b;
//             cout << arr[b] << '\n';
//             break;
//         case 1:
//             cin >> b;
//             arr[b] = 1;
//             break;
//         case 2:
//             cin >> b;
//             arr[b] = 0;
//             break;
//         case 3:
//             cin >> b;
//             arr[b] = !arr[b];
//             break;
//         case 4:
//             flag = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 0)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 5:
//             flag = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 1)
//                 {
//                     cout << 1 << '\n';
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 0)
//             {
//                 cout << 0 << '\n';
//             }
            
//             break;
//         case 6:
//             flag = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 1)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 7:
//             ans = 0;
//             for (int i = 0; i < 64; i++)
//             {
//                 if (arr[i] == 1)
//                     ans++;
//             }
//             cout << ans << '\n';
//             break;
//         case 8:
//             ans = 0;
//             uint64_t tmp = 1;
//             for (int i = 0; i < 64; i++)
//             {
//                 ans += arr[i] * tmp;
//                 tmp *= 2;
//             }
//             cout << ans << '\n';
//             break;
//         // default:
//         //     break;
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

//     bool arr[64] = { 0 };
//     int n;
//     vector<vector<int>> mark;
//     cin >> n;
//     while (n--)
//     {
//         int a;
//         cin >> a;
//         vector<int> tmp;
//         while (a--)
//         {
//             int b;
//             cin >> b;
//             tmp.emplace_back(b);
//         }
//         mark.emplace_back(tmp);
//     }
    

//     int tt;
//     cin >> tt;
//     int flag = 0;
//     uint64_t ans;
//     while (tt--)
//     {
//         int a, b;
//         cin >> a;
//         switch (a)
//         {
//         case 0:
//             cin >> b;
//             cout << arr[b] << '\n';
//             break;
//         case 1:
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 arr[mark[b][i]] = 1;
//             }
            
//             break;
//         case 2:
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 arr[mark[b][i]] = 0;
//             }
//             break;
//         case 3:
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 arr[mark[b][i]] = !arr[mark[b][i]];
//             }
//             break;
//         case 4:
//             flag = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 0)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 5:
//             flag = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 1)
//                 {
//                     cout << 1 << '\n';
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 0)
//             {
//                 cout << 0 << '\n';
//             }

//             break;
//         case 6:
//             flag = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 1)
//                 {
//                     flag = 1;
//                     cout << 0 << '\n';
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 cout << 1 << '\n';
//             break;
//         case 7:
//             ans = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 if (arr[mark[b][i]] == 1)
//                     ans++;
//             }
//             cout << ans << '\n';
//             break;
//         case 8:
//             ans = 0;
//             cin >> b;
//             for (int i = 0; i < mark[b].size(); i++)
//             {
//                 ans += arr[mark[b][i]] * (pow(2.L, mark[b][i]));
//             }
//             cout << ans << '\n';
//             break;
//             // default:
//             //     break;
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// bool isnp[100000005];
// vector<int> prime;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 2; i <= n; i++)
//     {
//         if (!isnp[i])
//             prime.emplace_back(i);

//         for (const int& p : prime)
//         {
//             if (p * i > n) break;

//             isnp[p * i] = 1;

//             if (i % p == 0) break;
//         }
//     }
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int a;
//         cin >> a;
//         cout << prime[a - 1] << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// const int N = 1000000005;
// bool isnp[N];
// vector<int> prime;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int begin = clock();
//     for (int i = 2; i < N; i++)
//     {
//         if (!isnp[i])
//             prime.emplace_back(i);

//         for (const int& p : prime)
//         {
//             if (p * i > N) break;

//             isnp[p * i] = 1;

//             if (i % p == 0) break;
//         }
//     }
//     int end = clock();

//     for (size_t i = 1; i < prime.size(); i++)
//     {
//         cout << prime[i] << '\n';
//     }

//     cout << (double)(end - begin) / 1000.0 << '\n';
//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     string str;
//     cin >> str;
//     while (1)
//     {
//         if (!(cin >> str))
//         {
//             cout << "a roop" << '\n';
//             cin.clear();
//             cin.ignore(1024, '\n');
//             break;
//         }
//         else
//         {
//             cout << str << '\n';
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// char buff[1000000000];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     ifstream ifs;
//     ifs.open("data.out", ios::in);

//     int begin, end;
//     int ch;
//     begin = clock();
//     while ((ch = ifs.get()) != EOF)
//     {
        
//     }
//     end = clock();
//     cout << endl;
//     cout << (double)(end - begin) / 1000. << endl;
//     system("pause");

//     string buf;
//     ifs.seekg(0, ios::beg);

//     begin = clock();
//     while (ifs >> buff)
//     {
//         cout << buff << '\n';
//     }
//     end = clock();
//     cout << endl;
//     cout << (double)(end - begin) / 1000. << endl;
//     system("pause");

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     vector<int> arr;
//     arr.emplace_back(1);
//     arr.emplace_back(1);
//     arr.emplace_back(1);
//     arr.emplace_back(2);
//     unique(arr.begin(), arr.end());
//     for (const int& p : arr)
//         cout << p << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     for (int i = 0; i < 16; i++)
//         cout << bitset<8>(i) << '\n';

//     cout << flush;
//     system("pause");
//     return 0;
// }

// void init(bool* arr)
// {
//     for (int i = 0; i < 64; i++)
//         arr[i] = 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     bool data[64];
//     int n;
//     cin >> n;
//     for (int i = 0; i < pow(2.L, n); i++)
//     {
//         cout << i << ':';

//         init(data);
//         int j = i;
//         int k = 63;
//         while (j)
//         {
//             data[k--] = j % 2;
//             j /= 2;
//         }
//         for (j = 63; j >= 0; j--)
//         {
//             if (data[j] == 1)
//             {
//                 cout << ' ' << 63 - j;
//             }
//         }
//         cout << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// void init(bool* arr)
// {
//     for (int i = 0; i < 64; i++)
//         arr[i] = 0;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     bool data[64];
//     int n;
//     cin >> n;
//     for (int i = 0; i < pow(2.L, n); i++)
//     {
//         cout << i << ':';

//         init(data);
//         int j = i;
//         int k = 63;
//         while (j)
//         {
//             data[k--] = j % 2;
//             j /= 2;
//         }
//         for (j = 63; j >= 0; j--)
//         {
//             if (data[j] == 1)
//             {
//                 cout << ' ' << 63 - j;
//             }
//         }
//         cout << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     for (int i = 0; i < 10; i++)
//     {
        
//     }
//     vector<int> arr(8);
//     cout << arr.size();

//     cout << flush;
//     system("pause");
//     return 0;
// }



// void subset(int n, int s) {

//     printf("{");

//     for (int i = 0; i < n; i++)

//         if (s & (1 << i)) printf("%d ", i + 1);

//     printf("}\n");

// }

// int main() {

//     int n;

//     while (scanf("%d", &n) != EOF)

//         for (int i = 0; i < (1 << n); i++)

//             subset(n, i);

//     return 0;

// }