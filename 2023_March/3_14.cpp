#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int a, b;
//     cin >> a >> b;
//     vector<int> arr(a);
//     for (int i = 0; i < a; i++)
//         arr[i] = i;

//     int tmp = 0;
//     while (arr.size() > 1)
//     {
//         arr.erase(arr.begin() + (tmp + b - 1) % a);
//         tmp = (tmp + b - 1) % a--;
//     }
//     cout << arr[0] + 1 << endl;


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
//     int ans = 0;

    
//     for (int i = 1; i <= n; i++)
//     {
//         int a = n, b = i;
//         int tmp;
//         do
//         {
//             tmp = a % b;
//             a = b;
//             b = tmp;
//         } while (b);
//         if (a == 1) ans++;
//     }

//     cout << ans << endl;
//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     vector<char> s1;
//     vector<int> a1;
//     int ch;
//     int tt;
//     cin >> tt;
//     int n = tt;
//     while (tt--)
//     {
//         ch = cin.get();
//         if (ch == ' ' || ch == '\n')
//         {
//             ch = cin.get();
//         }
        
//         s1.emplace_back(ch);
//         ch = cin.get();
//         a1.emplace_back(ch - '0');
//     }
//     vector<char> s2(s1);
//     vector<int> a2(a1);
//     vector<char> str(s1);
//     vector<int> arr(a1);


//     for (int i = 0; i < n; i++)
//     {
//         for (int j = n - 1; j >= i + 1; j--)
//         {
//             if (a1[j] < a1[j - 1])
//             {
//                 swap(a1[j], a1[j - 1]);
//                 swap(s1[j], s1[j - 1]);
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << s1[i] << a1[i] << ' ';
//     }
//     cout << '\n';
//     int flag;
//     flag = 0;
//     int count = 0;
//     for (int i = 0; i < n - 1; i += count + 1)
//     {
//         count = 0;
//         int j = i;
//         vector<char> tmp1, tmp2;
//         while (a1[j] == a1[j + 1])
//         {
//             count++;
//             tmp1.emplace_back(s1[j]);
//             j++;
//         }
//         if (count != 0)
//         {
//             tmp1.emplace_back(s1[j]);
//             for (int k = 0; k < n; k++)
//             {
//                 if (arr[k] == a1[j])
//                 {
//                     tmp2.emplace_back(str[k]);
//                 }
//             }
//             if (tmp1 != tmp2)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//     }
//     if (flag == 1) cout << "Not stable\n";
//     else cout << "Stable\n";

//     for (int i = 0; i < n; i++)
//     {
//         int min_num = a2[i];
//         int index = -1;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (min_num > a2[j])
//             {
//                 min_num = a2[j];
//                 index = j;
//             }
//         }
//         if (index != -1)
//         {
//             swap(a2[i], a2[index]);
//             swap(s2[i], s2[index]);
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << s2[i] << a2[i] << ' ';
//     }
//     cout << '\n';

//     flag = 0;
//     count = 0;
//     for (int i = 0; i < n - 1; i += count + 1)
//     {
//         count = 0;
//         int j = i;
//         vector<char> tmp1, tmp2;
//         while (a2[j] == a2[j + 1])
//         {
//             count++;
//             tmp1.emplace_back(s2[j]);
//             j++;
//         }
//         if (count != 0)
//         {
//             tmp1.emplace_back(s2[j]);
//             for (int k = 0; k < n; k++)
//             {
//                 if (arr[k] == a2[j])
//                 {
//                     tmp2.emplace_back(str[k]);
//                 }
//             }
//             if (tmp1 != tmp2)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//     }
//     if (flag == 1) cout << "Not stable\n";
//     else cout << "Stable\n";



//     cout << flush;
//     ::system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     stack<int> s;
//     int ch;
//     int cnt = 0;
//     while ((ch = cin.get()) != EOF)
//     {
//         if (ch == ' ')
//         {
//             cnt = 0;
//             continue;
//         }

//         if (ch >= '0' && ch <= '9' && cnt == 0)
//         {
//             s.push(ch - '0');
//             cnt++;
//         }
//         else if (ch >= '0' && ch <= '9' && cnt != 0)
//         {
//             s.top() *= 10;
//             s.top() += ch - '0';
//         }
//         else
//         {
//             cnt = 0;
//             int a, b;
//             switch (ch)
//             {
//             case '+':
//                 a = s.top();
//                 s.pop();
//                 b = s.top();
//                 s.pop();
//                 s.push(a + b);
//                 break;
//             case '-':
//                 a = s.top();
//                 s.pop();
//                 b = s.top();
//                 s.pop();
//                 s.push(b - a);
//                 break;
//             case '*':
//                 a = s.top();
//                 s.pop();
//                 b = s.top();
//                 s.pop();
//                 s.push(a * b);
//                 break;
//             }
//         }
//     }
//     cout << s.top() << '\n';

//     cout << flush;
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
    string tmp;
    int a;
    while (tt--)
    {
        cin >> tmp;
        if (tmp == "insert")
        {
            cin >> a;
            L.emplace_front(a);
        }
        else if (tmp == "delete")
        {
            cin >> a;
            for (auto it = L.begin(); it != L.end(); it++)
            {
                if (*it == a)
                {
                    L.erase(it);
                    break;
                }
            }
        }
        else if (tmp == "deleteFirst")
        {
            L.pop_front();
        }
        else
        {
            L.pop_back();
        }
    }
    for (const int& i : L)
    {
        cout << i << ' ';
    }
    cout << '\n';

    cout << flush;
    system("pause");
    return 0;
}