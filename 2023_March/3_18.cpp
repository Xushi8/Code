#include <bits/stdc++.h>
using namespace std;

// bool check(int n, int num, vector<int> arr, int middle)
// {
//     int car_sum = num - 1;
//     int car_afford = middle;
//     for (int i = 0; i < n;i++)
//     {
//         car_afford -= arr[i];
//         if (car_afford < 0)
//         {
//             car_sum--;
//             car_afford = middle;
//             i--;
//             if (car_sum < 0) return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, num;
//     cin >> n >> num;
//     vector<int> arr(n);
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         sum += arr[i];
//     }
//     int maxn = sum;
//     int minn = sum / num;
//     int middle;
//     while (maxn >= minn)
//     {
//         middle = (maxn + minn) / 2;
//         if (check(n, num, arr, middle))
//         {
//             maxn = middle - 1;
//         }
//         else
//         {
//             minn = middle + 1;
//         }
//     }

//     if (check(n, num, arr, middle))
//     {
//         while (1)
//         {
//             if (check(n, num, arr, middle)) middle--;
//             else {cout << middle + 1; break;}
//         }
//     }
//     else
//     {
//         while (1)
//         {
//             if (!check(n, num, arr, middle))
//             {
//                 middle++;
//             }
//             else
//             {
//                 cout << middle;
//                 break;
//             }
//         }
//     }


//     cout << flush;
//     system("pause");
//     return 0;
// }

// uint64_t cnt = 0;
// void merge_sort(int* A, int x, int y, int* T)
// {
//     if (y - x > 1)
//     {
//         int m = x + (y - x) / 2;
//         int p = x, q = m, i = x;
//         merge_sort(A, x, m, T);
//         merge_sort(A, m, y, T);
//         while (p < m || q < y) {
//             if (q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];
//             else T[i++] = A[q++];
//             cnt++;
//         }
//         for (i = x; i < y; i++) A[i] = T[i];
//     }
// }

// int arr[1000005];
// int tmp[1000005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     merge_sort(arr, 0, n, tmp);
//     for (int i = 0; i < n; i++) cout << arr[i] << ' ';
//     cout << endl << cnt;

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int arr[25];
// bool flag;


// void dfs(int i, int target)
// {
//     if (arr[i] == target) flag = 1 return;
//     else if (i == 0) return;
//     else
//     {
//         dfs(i - 1, target - arr[i]);
//         dfs(i - 1, target);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     int target;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr, arr + n);
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         cin >> target;
//         flag = 0;
//         dfs(n - 1, target);
//         if (flag) cout << "yes\n";
//         else cout << "no\n";
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// const long double pi = 3.1415926535897932384626433832795L;

// class Point
// {
// public:
//     long double x, y;
//     bool flag;

//     Point()
//     {
//         x = 0.0L;
//         y = 0.0L;
//         flag = 0;
//     }
//     Point(long double a, long double b)
//     {
//         this->x = a;
//         this->y = b;
//         this->flag = 0;
//     }
// };

// int n;
// vector<Point> arr;

// void dfs(Point& a1, Point& b1, int deep)
// {
//     if (deep == n)
//     {
//         if (!a1.flag) {a1.flag = 1; arr.emplace_back(a1);}
//         if (!b1.flag) { b1.flag = 1; arr.emplace_back(b1); }
//         return;
//     }

//     Point a, b, c;
//     a.x = (2 * a1.x + b1.x) / 3.0L;
//     a.y = (2 * a1.y + b1.y) / 3.0L;
//     c.x = (a1.x + 2 * b1.x) / 3.0L;
//     c.y = (a1.y + 2 * b1.y) / 3.0L;
//     b.x = (c.x - a.x) * cos(pi / 3.0L) - (c.y - a.y) * sin(pi / 3.0L) + a.x;
//     b.y = (c.x - a.x) * sin(pi / 3.0L) + (c.y - a.y) * cos(pi / 3.0L) + a.y;
//     dfs(a1, a, deep + 1);
//     dfs(a, b, deep + 1);
//     dfs(b, c, deep + 1);
//     dfs(c, b1, deep + 1);
// }

// int main()
// {
//     // ios::sync_with_stdio(false);
//     // cin.tie(0);
    
//     cin >> n;
//     Point a(0.0L, 0.0L);
//     Point b(100.0L, 0.0L);
//     dfs(a, b, 0);
//     for (const auto& p : arr)
//     {
//         printf("%.8Lf %.8Lf\n", p.x, p.y);
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// uint64_t ans;
// void select_sort(int* arr, int n)
// {
    
// }

// int arr[1005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
    

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int find_pivot(int* arr, int left, int right, char* str)
// {
//     int mid = (left + right) / 2;
//     if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
//     if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
//     if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);

//     swap(arr[mid], arr[right]);
//     swap(str[mid], str[right]);
//     return arr[right];
// }

// void insert_sort(int* arr, int* end, char* str)
// {
//     int i, j, tmp;
//     int n = end - arr;
//     for (int i = 1; i < n; i++)
//     {
//         tmp = arr[i];
//         char tmp1 = str[i];
//         for (j = i; j - 1 >= 0 && arr[j - 1] > tmp; j--)
//         {
//             arr[j] = arr[j - 1];
//             str[j] = str[j - 1];
//         }
//         arr[j] = tmp;
//         str[j] = tmp1;
//     }
// }

// void quick_sort(int* arr, int left, int right, char* str)
// {
//     int i = left, j = right;
//     if (left + 3 < right)
//     {
//         int pivot = find_pivot(arr, left, right, str);
//         while (1)
//         {
//             while (arr[++i] < pivot) {}
//             while (arr[--j] > pivot) {}

//             if (i < j)
//             {
//                 swap(arr[i], arr[j]);
//                 swap(str[i], str[j]);
//             }
//             else
//             {
//                 break;
//             }
//         }

//         swap(arr[i], arr[right]);
//         swap(str[i], str[right]);

//         quick_sort(arr, left, i - 1, str);
//         quick_sort(arr, i + 1, right, str);
//     }
//     else
//     {
//         insert_sort(arr + left, arr + right + 1, str);
//     }
// }

// int arr[10], a[10];
// char str[10], s[10];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> str[i] >> arr[i];
//         a[i] = arr[i];
//         s[i] = str[i];
//     }
//     quick_sort(arr, 0, n - 1, str);

//     int flag = 0, count = 0;
//     for (int i = 0; i < n - 1; i += 1 + count)
//     {
//         count = 0;
//         int j = i;
//         vector<char> tmp1, tmp2;
//         while (arr[j] == arr[j + 1])
//         {
//             count++;
//             tmp1.emplace_back(str[j]);
//             j++;
//         }
//         if (count != 0)
//         {
//             tmp1.emplace_back(str[j]);
//             for (int k = 0; k < n; k++)
//             {
//                 if (a[k] == arr[j])
//                     tmp2.emplace_back(s[k]);
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

//     for (int i = 0;i < n; i++)
//     {
//         cout << str[i] << ' ' << arr[i] << '\n';
//     }


//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m, l;
//     cin >> n >> m >> l;
//     vector < vector<unsigned long long> > a1(n, vector<unsigned long long>(m)), a2(m, vector<unsigned long long>(l)), ans(n, vector<unsigned long long>(l, 0));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> a1[i][j];
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < l; j++)
//             cin >> a2[i][j];

//     int a = 0, b = 0;
//     int i, j, k;
//     for (i = 0; i < n;i++)
//     {
//         b = 0;
//         for (k = 0; k < l; k++)
//         {
//             for (j = 0; j < m; j++)
//             {
//                 ans[a][b] += a1[i][j] * a2[j][b];
//             }
//             b++;
//         }
//         a++;
//     }

//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < l; j++)
//         {
//             cout << ans[i][j] << ' ';
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
    
//     int ch;
//     while ((ch = cin.get()) != EOF)
//     {
//         if (isupper(ch)) ch = tolower(ch);
//         else if (islower(ch)) ch = toupper(ch);

//         cout.put(ch);
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     string str;
//     while (cin >> str && str[0] - '0')
//     {
//         unsigned long long sum = 0;
//         for (int i = 0; i < (int)str.size(); i++)
//             sum += str[i] - '0';
//         cout << sum << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int ch;
//     int arr[27] = {0};
//     while ((ch = cin.get()) != EOF)
//     {
//         if (isalpha(ch))
//         {
//             if (isupper(ch))
//             {
//                 arr[ch - 'A']++;
//             }
//             else
//             {
//                 arr[ch - 'a']++;
//             }
//         }
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         printf("%c : %d\n", i + 'a', arr[i]);
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     string s1, s2;
//     cin >> s1 >> s2;
//     s1 += s1;
//     if (s1.find(s2) != string::npos) cout << "Yes\n";
//     else cout << "No\n";

//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     string word;
//     cin >> word;
//     string text;
//     long long ans = 0;
//     while (getline(cin, text))
//     {
//         size_t pos = 0;
//         size_t next = 0;
//         while ((next = text.find(' ', pos)) != string::npos)
//         {
//             for(size_t i = next; i)
//         }
//     }
//     cout << ans << endl;

//     cout << flush;
//     system("pause");
//     return 0;
// }