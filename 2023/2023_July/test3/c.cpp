// // // 2023/07/24 17:05:00
// // #include <iostream>
// // #include <algorithm>
// // #include <cstring>
// // #include <cstdint>
// // #include <vector>
// // #include <string>
// // #include <set>
// // #include <map>
// // #include <unordered_map>
// // #include <unordered_set>
// // #include <queue>
// // #include <functional>
// // #include <iomanip>
// // using namespace std;

// // using ll = long long;
// // using ull = unsigned long long;
// // using pii = pair<int, int>;
// // const int INF = 0x3f3f3f3f;
// // const int MOD = (int)(1e9 + 7);
// // const int N = 1000005;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);

// //     int tt;
// //     cin >> tt;
// //     while (tt--)
// //     {
// //         string ans;
// //         int n;
// //         cin >> n;
// //         cin >> ans;
// //         int pow_num = 0;
// //         set<char> used;
// //         int cnt[2] = { 0 }; // 0代表F, 1代表E
// //         bool flag = 1;
// //         int pre = 0;
// //         int maxn = 0;
// //         cin.ignore(1024, '\n');
// //         vector<int> err; // 记录循环的失效下标
// //         for (int i = 0; i < n; i++)
// //         {
// //             string str;
// //             getline(cin, str);
// //             if (str[0] == 'F')
// //             {
// //                 cnt[0]++;
// //                 if (used.count(str[2]) != 0)
// //                 {
// //                     flag = 0;
// //                     continue;
// //                 }

// //                 used.emplace(str[2]);

// //                 int a = -1, b = -1;
// //                 int tot = 0;
// //                 int n_cnt = 0;
// //                 for (size_t j = 4; j < str.size(); j++)
// //                 {
// //                     if (isdigit(str[j]))
// //                     {
// //                         tot = tot * 10 + str[j] - '0';
// //                     }
// //                     else if (str[j] == ' ')
// //                     {
// //                         if (a == -1)
// //                             a = tot;
// //                         else
// //                             b = tot;
// //                         tot = 0;
// //                     }
// //                     else if (str[j] == 'n')
// //                     {
// //                         n_cnt++;

// //                         if (a == -1)
// //                         {
// //                             n_cnt = -999999;
// //                             err.emplace_back(cnt[0]);
// //                             break;
// //                         }
// //                     }
// //                 }

// //                 if (n_cnt == 1)
// //                 {
// //                     pow_num++;
// //                 }

// //                 pre = 0;
// //             }
// //             else if (str[0] == 'E')
// //             {
// //                 cnt[1]++;
// //                 if (pow_num > 0)
// //                 {
// //                     pow_num--;
// //                     pre++;
// //                     maxn = max(maxn, pre);
// //                 }

// //                 if (n_cnt < -1000)
// //                 {

// //                 }
// //             }
// //         }
// //         pow_num = maxn;

// //         if (!flag || cnt[0] != cnt[1])
// //         {
// //             cout << "ERR\n";
// //         }
// //         else
// //         {
// //             if (ans[2] == '1')
// //             {
// //                 if (pow_num == 0)
// //                     cout << "Yes\n";
// //                 else
// //                     cout << "No\n";
// //             }
// //             else
// //             {
// //                 int tot = 0;
// //                 for (size_t i = 4; i < ans.size(); i++)
// //                 {
// //                     if (isdigit(ans[i]))
// //                     {
// //                         tot = tot * 10 + ans[i] - '0';
// //                     }
// //                     else
// //                     {
// //                         break;
// //                     }
// //                 }

// //                 if (tot == pow_num)
// //                     cout << "Yes\n";
// //                 else
// //                     cout << "No\n";
// //             }
// //         }
// //     }

// //     cout << endl;
// //     return 0;
// // }



// // 2023/07/24 19:23:09
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdint>
// #include <vector>
// #include <string>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// #include <functional>
// #include <iomanip>
// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using pii = pair<int, int>;
// const int INF = 0x3f3f3f3f;
// const int MOD = (int)(1e9 + 7);
// const int N = 1000005;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int n;
//         string this_ans;
//         cin >> n >> this_ans;
//         cin.ignore(1024, '\n');
//         set<char> used_index;
//         bool flag = 1;
//         vector<int> err_index;
//         int cnt[2] = { 0 };
//         int pow_num = 0;
//         int maxn = 0;
//         for (int index = 0; index < n; index++)
//         {
//             string str;
//             getline(cin, str);
//             if (str[0] == 'F')
//             {
//                 cnt[0]++;
//                 if (used_index.count(str[2]) != 0)
//                 {
//                     flag = 0;
//                     continue;
//                 }
//                 used_index.emplace(str[2]);

//                 int a = -1, b = -1;
//                 int tot = 0;
//                 for (int i = 4; i < str.size(); i++)
//                 {
//                     if (isdigit(str[i]))
//                     {
//                         tot = tot * 10 + str[i] - '0';
//                     }
//                     else if (str[i] == ' ')
//                     {
//                         if (a == -1)
//                         {
//                             a = tot;
//                         }
//                         else
//                         {
//                             b = tot;
//                         }

//                         tot = 0;
//                     }
//                     else if (str[i] == 'n')
//                     {
//                         if (a == -1)
//                             a = 99999;
//                         else
//                             b = 99999;
//                     }
//                 }

//                 if (b == -1)
//                     b = tot;

//                 if (a > b)
//                 {
//                     err_index.emplace_back(1);
//                 }
//                 else if (a == b)
//                 {
//                     if (!err_index.empty())
//                     {
//                         err_index.emplace_back(1);
//                     }
//                 }
//                 else if (a < 200 && b == 99999)
//                 {
//                     if (err_index.empty())
//                     {
//                         pow_num++;
//                     }
//                     else
//                     {
//                         err_index.emplace_back(1);
//                     }
//                 }

//                 maxn = max(maxn, pow_num);
//             }
//             else
//             {
//                 cnt[1]++;
//                 if (!err_index.empty())
//                 {
//                     err_index.pop_back();
//                 }
//                 else
//                 {
//                     pow_num--;
//                 }
//             }
//         }

//         if (!flag || cnt[1] != cnt[0])
//             cout << "ERR\n";
//         else
//         {
//             if (this_ans[2] == '1')
//             {
//                 if (maxn == 0)
//                     cout << "Yes\n";
//                 else
//                     cout << "No\n";
//             }
//             else
//             {
//                 int tot = 0;
//                 for (int i = 4; i < this_ans.size(); i++)
//                 {
//                     if (isdigit(this_ans[i]))
//                         tot = tot * 10 + this_ans[i] - '0';
//                     else
//                         break;
//                 }

//                 if (tot == maxn)
//                     cout << "Yes\n";
//                 else
//                     cout << "No\n";
//             }
//         }

//     }

//     cout << endl;
//     return 0;
// }



// 2023/07/24 20:05:30
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

bool check(const vector<char>& used, char ch)
{
    for (int i = 0; i < used.size(); i++)
        if (used[i] == ch)
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        string this_ans;
        cin >> n >> this_ans;
        cin.ignore(1024, '\n');

        bool flag = 1;
        vector<char> used;
        stack<int> stk; // 用于记录pow_num
        int pow_num = 0;
        int maxn = 0;
        bool update = 0;
        for (int index = 0; index < n; index++)
        {
            string str;
            getline(cin, str);
            if (str[0] == 'F')
            {
                if (check(used, str[2]))
                {
                    flag = 0;
                    continue;
                }
                else
                {
                    used.emplace_back(str[2]);
                }

                int a = -1, b = -1;
                int tot = 0;
                for (int i = 4; i < str.size(); i++)
                {
                    if (isdigit(str[i]))
                    {
                        tot = tot * 10 + str[i] - '0';
                    }
                    else if (str[i] == ' ')
                    {
                        if (a == -1)
                        {
                            a = tot;
                        }
                        else
                        {
                            b = tot;
                        }

                        tot = 0;
                    }
                    else if (str[i] == 'n')
                    {
                        if (a == -1)
                            a = 9999;
                        else
                            b = 9999;
                    }
                }

                if (b == -1)
                    b = tot;

                if (a > b)
                    stk.emplace(-1);
                else if (a == b || b < 200)
                    stk.emplace(0);
                else
                    stk.emplace(1);

                if (update)
                    pow_num = 0;
            }
            else
            {
                if (stk.empty())
                {
                    flag = 0;
                    continue;
                }

                if (stk.top() == -1)
                {
                    stk.pop();
                    used.pop_back();
                    pow_num = 0;
                }
                else
                {
                    pow_num += stk.top(); stk.pop();
                    used.pop_back();
                }


                if (stk.empty())
                {
                    maxn = max(maxn, pow_num);
                    pow_num = 0;
                }

                update = 1;
            }
        }

        if (!flag || !stk.empty())
            cout << "ERR\n";
        else
        {
            if (this_ans[2] == '1')
            {
                if (maxn == 0)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
            else
            {
                int tot = 0;
                for (int i = 4; i < this_ans.size(); i++)
                {
                    if (isdigit(this_ans[i]))
                        tot = tot * 10 + this_ans[i] - '0';
                    else
                        break;
                }

                if (tot == maxn)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }

    cout << endl;
    return 0;
}