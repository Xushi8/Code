// 2023/11/08 10:27:19
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

struct stu
{
    string name;
    int x, y, z, ave;
};

bool cmp1(stu a, stu b)
{
    return a.ave > b.ave;
}

bool cmp2(stu a, stu b)
{
    return a.x > b.x;
}

bool cmp3(stu a, stu b)
{
    return a.y > b.y;
}

bool cmp4(stu a, stu b)
{
    return a.z > b.z;
}

struct A
{
    int rank;
    char ch;
};

int quanzhong(char ch)
{
    if (ch == 'E')
        return 0;
    else if (ch == 'M')
        return 1;
    else if (ch == 'C')
        return 2;
    else
        return 3;
}

bool cmp(A x, A y)
{
    if (x.rank != y.rank)
    {
        return x.rank < y.rank;
    }
    else
    {
        return quanzhong(x.ch) > quanzhong(y.ch);
    }
}

A get_pair(const vector<stu>& a, char ch, const string& name, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].name == name)
        {
            int j;
            for (j = i - 1; j >= 0; j--)
            {
                if (ch == 'A')
                {
                    if (a[j].ave != a[i].ave)
                    {
                        break;
                    }
                }
                else if (ch == 'C')
                {
                    if (a[j].x != a[i].x)
                    {
                        break;
                    }
                }
                else if (ch == 'M')
                {
                    if (a[j].y != a[i].y)
                    {
                        break;
                    }
                }
                else
                {
                    if (a[j].z != a[i].z)
                    {
                        break;
                    }
                }
            }
            j++;
            return {j + 1, ch};
        }
    }

    return {0, 'B'};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<stu> a(n);
    for (int i = 0; i < n; i++)
    {
        string name;
        int x, y, z;
        cin >> name >> x >> y >> z;
        int ave = (x + y + z) / 3;
        a[i] = {name, x, y, z, ave};
    }

    vector<stu> b, c, d;
    b = c = d = a;

    sort(a.begin(), a.end(), cmp1);
    sort(b.begin(), b.end(), cmp2);
    sort(c.begin(), c.end(), cmp3);
    sort(d.begin(), d.end(), cmp4);

    while (m--)
    {
        string name;
        cin >> name;
        vector<A> arr(4);
        arr[0] = get_pair(a, 'A', name, n);
        arr[1] = get_pair(b, 'C', name, n);
        arr[2] = get_pair(c, 'M', name, n);
        arr[3] = get_pair(d, 'E', name, n);

        sort(arr.begin(), arr.end(), cmp);
        if (arr[0].ch == 'B')
        {
            cout << "N/A\n";
        }
        else
        {
            cout << arr[0].rank << ' ' << arr[0].ch << '\n';
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}