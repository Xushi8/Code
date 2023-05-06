#include <bits/stdc++.h>
using namespace std;



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, jiange;
//     cin >> n >> jiange;
//     queue<string> name;
//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {
//         string _name;
//         int tmp;
//         cin >> _name >> tmp;
//         name.push(_name);
//         q.push(tmp);
//     }

//     int time = 0;
//     while (!q.empty())
//     {
//         if (q.front() <= jiange)
//         {
//             cout << name.front() << ' ' << time + q.front() << '\n';
//             time += q.front();
//             q.pop();
//             name.pop();
//         }
//         else
//         {
//             q.front() -= jiange;
//             q.push(q.front());
//             q.pop();
//             name.push(name.front());
//             name.pop();
//             time += jiange;
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// bool solve() {
//     int W1, D1, W2, D2;
//     bool b1 = true, b2 = true;
//     cin >> W1 >> D1 >> W2 >> D2;
//     if (!W1) b1 = solve();
//     if (!W2) b2 = solve();
//     return b1 && b2 && (W1 * D1 == W2 * D2);
// }
// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         if (solve()) cout << "YES\n"; else cout << "NO\n";
//         if (T) cout << "\n";
//     }
//     system("pause");
//     return 0;
// }

// class each_area
// {
// public:
//     int left, area;
//     each_area(int l, int a)
//     {
//         this->area = a;
//         this->left = l;
//     }
// };
// vector<each_area> v;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     stack<int> s;
//     int sum = 0;
//     string str;
//     cin >> str;
//     for (int i = 0; i < (int)str.size(); i++)
//     {
//         if (str[i] == '\\')
//         {
//             s.push(i);
//         }
//         else if (str[i] == '/' && !s.empty())
//         {
//             int j = s.top();
//             s.pop();
//             sum += i - j;
//             int tmp = i - j;
//             while (!v.empty() && v.back().left > j)
//             {
//                 tmp += v.back().area;
//                 v.pop_back();
//             }

//             v.push_back(each_area(j, tmp));
//         }
//     }
//     cout << sum << '\n';
//     cout << v.size();
//     for (size_t i = 0; i < v.size(); i++)
//     {
//         cout << ' ' << v[i].area;
//     }
//     cout << endl;

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> m;
//     vector<int> a1(m);
//     for (int i = 0; i < m; i++)
//     {
//         cin >> a1[i];
//     }

//     cin >> n;
//     vector<int> a2(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a2[i];
//     }
//     if (m < n) { swap(a1, a2); swap(m, n); }
//     sort(a1.begin(), a1.end());
//     sort(a2.begin(), a2.end());
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (binary_search(a1.begin(), a1.end(), a2[i]))
//         {
//             ans++;
//         }
//     }
//     cout << ans;

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     unordered_set<string> str;
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         string a, b;
//         cin >> a >> b;
//         if (a == "insert")
//         {
//             str.emplace(b);
//         }
//         else
//         {
//             if (str.count(b) != 0) cout << "yes\n";
//             else cout << "no\n";
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



