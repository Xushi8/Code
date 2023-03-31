#include <bits/stdc++.h>
using namespace std;

// void merge_sort(int* arr, int x, int y, int* T)
// {
//     if (x < y - 1)
//     {
//         int mid = (x + y) / 2;
//         int p = x, q = mid, i = x;
//         merge_sort(arr, x, mid, T);
//         merge_sort(arr, mid, y, T);
//         while (p < mid || q < y)
//         {
//             if (q >= y || (p < mid && arr[p] <= arr[q])) T[i++] = arr[p++];
//             else T[i++] = arr[q++];
//         }
//         for (i = x; i < y; i++)
//         {
//             arr[i] = T[i];
//         }
//     }
// }

// int arr[5000005];
// int tmp[5000005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> k;
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     merge_sort(arr, 0, n, tmp);

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int n, k;

// int search_pivot(int* arr, int x, int y)
// {
//     int mid = (x + y) / 2;
//     if (arr[x] > arr[mid]) swap(arr[x], arr[mid]);
//     if (arr[mid] > arr[y]) swap(arr[mid], arr[y]);
//     if (arr[x] > arr[mid]) swap(arr[x], arr[mid]);
//     swap(arr[mid], arr[y]);
//     return arr[y];
// }

// void quick_sort(int* arr, int x, int y)
// {
//     int i = x, j = y;
//     int pivot = arr[(x + y) / 2];
//     while (1)
//     {
//         while (arr[i] < pivot)
//         {
//             i++;
//         }
//         while (arr[j] > pivot)
//         {
//             j--;
//         }

//         if (i <= j)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j--;
//         }
//         else break;
//     }

//     if (k <= j) quick_sort(arr, x, j);
//     else if (i <= k) quick_sort(arr, i, y);
//     else cout << arr[j + 1];
// }

// const int N = 5000006;
// int arr[N];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> k;
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     quick_sort(arr, 0, n - 1);

//     cout << flush;
//     system("pause");
//     return 0;
// }

// int a1[10005], a2[10005];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     cin >> a1[0];
//     for (int i = 1; i < n; i++)
//     {
//         cin >> a1[i];
//         a2[i] = abs(a1[i] - a1[i - 1]);
//     }
//     sort(a2, a2 + n);
//     bool flag = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (a2[i] != i)
//         {
//             flag = 0;
//             cout << "Not jolly";
//             break;
//         }
//     }
//     if (flag) cout << "Jolly";

//     cout << flush;
//     system("pause");
//     return 0;
// }


// int arr[200005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, b;
//     cin >> n >> b;
//     for (int i = 0;i < n; i++) cin >> arr[i];
//     sort(arr, arr + n, greater<int>());
//     for (int i = 0; i < n; i++)
//     {
//         b -= arr[i];
//         if (b <= 0)
//         {
//             cout << i + 1;
//             break;
//         }
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// class Stu
// {
// public:
//     int id, a, b, c, all;
// };

// bool cmp(const Stu& a, const Stu& b)
// {
//     if (a.all != b.all) return a.all > b.all;
//     else if (a.a != b.a) return a.a > b.a;
//     else return a.id < b.id;
// }

// Stu stu[310];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         stu[i].id = i + 1;
//         cin >> stu[i].a >> stu[i].b >> stu[i].c;
//         stu[i].all = stu[i].a + stu[i].b + stu[i].c;
//     }
//     sort(stu, stu + n, cmp);
//     for (int i = 0; i < 5; i++)
//     {
//         cout << stu[i].id << ' ' << stu[i].all << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// class Per
// {
// public:
//     int id, score;
// };
// Per per[5005];
// bool cmp(const Per& a, const Per& b)
// {
//     if (a.score != b.score)return a.score > b.score;
//     else return a.id < b.id;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> per[i].id >> per[i].score;
//     }
//     sort(per, per + n, cmp);
//     int minn = per[(int)floor(m * 1.5) - 1].score;
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (per[i].score >= minn) ans++;
//         else break;
//     }
//     cout << minn << ' ' << ans << '\n';
//     for (int i = 0; i < ans; i++)
//     {
//         cout << per[i].id << ' ' << per[i].score << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// class Point
// {
// public:
//     double x, y, z;
// };
// Point arr[500005];
// bool cmp(Point& a, Point& b)
// {
//     return a.z < b.z;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].x >> arr[i].y >> arr[i].z;
//     }
//     sort(arr, arr + n, cmp);
//     double ans = 0.0;
//     for (int i = 1; i < n; i++)
//     {
//         ans += sqrt((arr[i].x - arr[i - 1].x) * (arr[i].x - arr[i - 1].x) + (arr[i].y - arr[i - 1].y) * (arr[i].y - arr[i - 1].y) + (arr[i].z - arr[i - 1].z) * (arr[i].z - arr[i - 1].z));
//     }
//     printf("%.3lf", ans);

//     cout << flush;
//     system("pause");
//     return 0;
// }

// class Person
// {
// public:
//     string name;
//     int a, b, c, id;
// };
// Person arr[105];
// bool cmp(Person& a, Person& b)
// {
//     if (a.a != b.a) return a.a < b.a;
//     else if (a.b != b.b) return a.b < b.b;
//     else if (a.c != b.c) return a.c < b.c;
//     else return a.id > b.id;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;
//         arr[i].id = i;
//     }
//     sort(arr, arr + n, cmp);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].name << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     vector<int> ans;
//     int n;
//     cin >> n;
//     ans.emplace_back(n);
//     while (n != 1)
//     {
//         if (n & 1)
//         {
//             n = n * 3 + 1;
//         }
//         else
//         {
//             n /= 2;
//         }
//         ans.emplace_back(n);
//     }

//     reverse(ans.begin(), ans.end());
//     for (auto& p : ans)
//     {
//         cout << p << ' ';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int ch, tmp;
//     int N = 0;
//     bool flag = 1;
//     vector<int> ans;
//     int tot = 0;
//     while ((ch = cin.get()) == '0' || ch == '1')
//     {
//         N++;
//         if (flag)
//         {
//             flag = 0;
//             if (ch == '1')
//             {
//                 ans.emplace_back(0);
//             }
//             tmp = ch;
//         }
//         if (tmp != ch)
//         {
//             ans.emplace_back(tot);
//             tot = 1;
//             tmp = ch;
//         }
//         else
//         {
//             tot++;
//         }
//     }

//     while ((ch = cin.get()) != EOF)
//     {
//         if (ch != '0' && ch != '1') continue;

//         if (tmp != ch)
//         {
//             ans.emplace_back(tot);
//             tot = 1;
//             tmp = ch;
//         }
//         else
//         {
//             tot++;
//         }
//     }

//     ans.emplace_back(tot);



    
//     cout << N << ' ';
//     for (int& p : ans)
//     {
//         cout << p << ' ';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }



// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int arr[30][30] = { 0 };
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             if (j == 0 || j == i)
//             {
//                 arr[i][j] = 1;
//             }
//             else
//             {
//                 arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << arr[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }

// bool arr[105][105];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n, m, l;
//     cin >> n >> m >> l;
//     for (int k = 0; k < m; k++)
//     {
//         int x, y;
//         cin >> x >> y;
//         int j = 1;
//         for (int i = x - 2; i <= x + 2; i++)
//         {
            
//         }
//     }
//     for (int k = 0; k < l; k++)
//     {
//         int x, y;
//         cin >> x >> y;
//         for (int i = x - 2; i <= x + 2; i++)
//         {
//             for (int j = y - 2; j <= j + 2; j++)
//             {
//                 if (i >= 0 && i < n && j >= 0 && j < n)
//                 {
//                     arr[i][j] = 1;
//                 }
//             }
//         }
//     }

//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i][i]) ans++;
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
    
//     int arr[10][10] = { 0 };
//     int n;
//     cin >> n;
//     int tmp = 1;
//     int count = 1;
//     int loop = n / 2;
//     int i = 0, j = 0;
//     int startx = 0, starty = 0;
//     while (loop--)
//     {
//         i = startx, j = starty;
//         for (j = starty; j < n - tmp; j++)
//         {
//             arr[i][j] = count++;
//         }
//         for (i = startx; i < n - tmp; i++)
//         {
//             arr[i][j] = count++;
//         }
//         for (; j > starty; j--)
//         {
//             arr[i][j] = count++;
//         }
//         for (; i > startx; i--)
//         {
//             arr[i][j] = count++;
//         }

//         startx++;
//         starty++;
//         tmp++;
//     }

//     if (n & 1) arr[n / 2][n / 2] = count;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             printf("%3d", arr[i][j]);
//         }
//         putchar('\n');
//     }

//     cout << flush;
//     system("pause");
//     return 0;
// }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    cout << flush;
    system("pause");
    return 0;
}