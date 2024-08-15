// 2024/08/13 12:58:47
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

using i128 = __int128_t;

template <typename T>
int num_len(T x)
{
    int res = 0;
    while (x)
    {
        res++;
        x /= 10;
    }
    return res;
}

string to_string(i128 x)
{
    string res;
    while (x)
    {
        res += char(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

i128 stoi128(string s)
{
    i128 res = 0;
    reverse(s.begin(), s.end());
    i128 now = 1;
    for (size_t i = 0; i < s.size(); i++, now *= 10)
    {
        res += (s[i] - '0') * now;
    }
    return res;
}

i128 sqrt(i128 x)
{
    int len = num_len(x);
    i128 l = 0, r = 9;
    for (int i = 0; i < (len / 2) + 1; i++)
    {
        r = r * 10 + 9;
    }

    i128 res = 0;
    while (l <= r)
    {
        i128 mid = (l + r) / 2;
        if (mid * mid <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

template <typename T>
void print(T num)
{
    if (num / 10)
    {
        print(num / 10);
    }
    cout.put((char)(num % 10 + '0'));
}

void solve()
{
    // i128 x = 8;
    // cout << i64(sqrt(x)) << endl;
    // cout << i64(sqrt(x + 1)) << endl;
    // cout << i64(sqrt(x + 2)) << endl;
    // cout << i64(sqrt(x + 3)) << endl;
    // cout << i64(sqrt(i128(99))) << endl;
    // cout << i64(sqrt(i128(100))) << endl;
    // cout << i64(sqrt(i128(101))) << endl;

    int n;
    cin >> n;
    string L, R;
    cin >> L >> R;

    i128 lhigh = stoi128(L.substr(0, n / 2));
    i128 llow = stoi128(L.substr(n / 2));
    i128 rhigh = stoi128(R.substr(0, n / 2));
    i128 rlow = stoi128(R.substr(n / 2));

    i128 l = sqrt(lhigh) + 1;
    i128 r = sqrt(rhigh);
    if (r * r == rhigh)
        r--;

    i128 ans = 0;
    if (l <= r)
    {
        i128 len = r - l + 1;

        // [string(n / 2, '0'), string(n / 2, '9')];
        i128 l1 = stoi128(string(n / 2, '0'));
        i128 r1 = stoi128(string(n / 2, '9'));
        i128 nl = sqrt(l1);
        if (nl * nl != l1)
            nl++;
        i128 nr = sqrt(r1);
        if (nl <= nr)
        {
            ans += len * (nr - nl + 1);
        }
    }

    l--;
    r++;
    if (lhigh == rhigh)
    {
        if (l * l == lhigh)
        {
            // [llow, rlow]
            i128 nl = sqrt(llow);
            if (nl * nl != llow)
                nl++;
            i128 nr = sqrt(rlow);
            if (nl <= nr)
            {
                ans += nr - nl + 1;
            }
        }
    }
    else
    {
        if (l * l == lhigh)
        {
            // [llow, string(n / 2, '9')]
            i128 nl = sqrt(llow);
            if (nl * nl != llow)
                nl++;
            i128 nr = sqrt(stoi128(string(n / 2, '9')));
            if (nl <= nr)
            {
                ans += nr - nl + 1;
            }
        }
        if (r * r == rhigh)
        {
            // [string(n / 2, '0'), rlow]
            i128 t = stoi128(string(n / 2, '0'));
            i128 nl = sqrt(t);
            if (nl * nl != t)
                nl++;
            i128 nr = sqrt(rlow);
            if (nl <= nr)
            {
                ans += nr - nl + 1;
            }
        }
    }

    print(ans);
    cout << '\n';
}