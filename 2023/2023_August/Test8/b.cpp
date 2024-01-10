// 2023/08/12 09:05:34
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000000;

char a[N], b[N];
int c[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;
    int lena = (int)strlen(a);
    int lenb = (int)strlen(b);
    reverse(a, a + lena);
    reverse(b, b + lenb);
    if ((lena == 0 && a[0] == '0') || (lenb == 0 && b[0] == '0'))
    {
        cout << 0 << '\n';
    }
    else
    {
        if (lena < lenb)
        {
            swap(lena, lenb);
            swap(a, b);
        }

        for (int i = 0; i < lena; i++)
        {
            a[i] -= '0';
        }
        for (int i = 0; i < lenb; i++)
        {
            b[i] -= '0';
        }

        for (int j = 0; j < lenb; j++)
        {
            for (int i = 0; i < lena; i++)
            {
                int tmp = a[i] * b[j];
                c[j + i] += tmp % 10;
                c[j + i + 1] += tmp / 10;
            }
        }

        for (int i = 0; i < N - 1; i++)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
        
        int lenc;
        for (int i = 0; i < N; i++)
        {
            if (c[i] != 0)
                lenc = i;
        }


        for (int i = lenc; i >= 0; i--)
        {
            cout << (char)(c[i] + '0');
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}