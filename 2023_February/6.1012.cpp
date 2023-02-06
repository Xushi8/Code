#include<bits/stdc++.h>
using namespace std;
int n, m;

// int cmp(string& a, string& b)
// {
//     if (a.size() == b.size())
//     {
//         if (a > b) return 1;
//         else return -1;
//     }
//     else if (a.size() < b.size())
//     {
//         string tmp = a;
//         a = b;
//         b = tmp;
//         if (a < b) return -1;
//         int i = 0;
//         while (a[i] == b[i])
//         {
//             i++;
//         }
//         if (i == b.size())
//         {
//             int j = 0;
//             while (a[i] == b[j])
//             {
//                 i++;
//                 j++;
//             }
//             if (a[i] > b[j]) return 1;
//             else return -1;
//         }
//         else
//         {
//             return 1;
//         }
//     }
//     else
//     {
//         if (a < b) return -1;
//         int i = 0;
//         while (a[i] == b[i])
//         {
//             i++;
//         }
//         if (i == b.size())
//         {
//             int j = 0;
//             while (a[i] == b[j])
//             {
//                 i++;
//                 j++;
//             }
//             if (a[i] > b[j]) return 1;
//             else return -1;
//         }
//         else
//         {
//             return 1;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin >> n;
//     string str[20];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> str[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (cmp(str[j], str[j + 1]) < 0)
//             {
//                 swap(str[j], str[j + 1]);
//             }
//         }
//     }
//     string ans;
//     for (int i = 0; i < n; i++)
//     {
//         ans += str[i];
//     }
//     cout << ans << endl;

//     system("pause");
//     return 0;
// }

//优化
bool cmp(string& a, string& b)
{
    return a + b > b + a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string str[20];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }
    cout << endl;

    system("pause");
    return 0;
}