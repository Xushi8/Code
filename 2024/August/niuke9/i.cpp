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
    if (x == 0)
        return 1;
    int res = 0;
    while (x)
    {
        res++;
        x /= 10;
    }
    return res;
}

std::string to_string(i128 x)
{
    std::string res;
    res.reserve(35);
    while (x)
    {
        res += char(x % 10 + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

i128 get_i128(std::string_view s)
{
    i128 res = 0;
    i128 now = 1;
    for (int i = int(s.size()) - 1; i >= 0; i--, now *= 10)
    {
        res += (s[i] - '0') * now;
    }
    return res;
}

i128 sqrt(i128 x)
{
    if (x < 0)
        return -1;
    int len = num_len(x);
    i128 l = 0, r = 9;
    for (int i = 0; i < (len / 2); i++)
    {
        r = r * 10 + 9;
    }

    i128 res = 0;
    while (l <= r)
    {
        i128 mid = l + (r - l) / 2;
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

std::istream& operator>>(std::istream& is, i128& x)
{
    x = 0;
    int f = 1;
    int ch = is.get();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = is.get();
    }
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = is.get();
    x *= f;
    return is;
}

std::ostream& operator<<(std::ostream& os, i128 x)
{
    if (x >= 10)
    {
        os << (x / 10);
    }
    os.put(x % 10 + '0');
    return os;
}

void solve()
{
    int n;
    cin >> n;
    string L, R;
    cin >> L >> R;

    i128 lhigh = get_i128(L.substr(0, n / 2));
    i128 llow = get_i128(L.substr(n / 2));
    i128 rhigh = get_i128(R.substr(0, n / 2));
    i128 rlow = get_i128(R.substr(n / 2));

    // 计算[l, r]中平方数的数量
    auto calc = [](i128 l, i128 r)
    {
        i128 nl = sqrt(l);
        if (nl * nl != l)
            nl++;
        i128 nr = sqrt(r);
        i128 res = 0;
        if (nl <= nr)
        {
            res += nr - nl + 1;
        }
        return res;
    };

    i128 l = sqrt(lhigh) + 1;
    i128 r = sqrt(rhigh);
    if (r * r == rhigh)
        r--;

    i128 ans = 0;
    if (l <= r)
    {
        i128 len = r - l + 1;

        // [string(n / 2, '0'), string(n / 2, '9')];
        i128 l1 = get_i128(string(n / 2, '0'));
        i128 r1 = get_i128(string(n / 2, '9'));
        i128 cnt = calc(l1, r1);
        ans += len * cnt;
    }

    l--;
    r++;
    if (lhigh == rhigh)
    {
        if (l * l == lhigh)
        {
            // [llow, rlow]
            ans += calc(llow, rlow);
        }
    }
    else
    {
        if (l * l == lhigh)
        {
            // [llow, string(n / 2, '9')]
            ans += calc(llow, get_i128(string(n / 2, '9')));
        }
        if (r * r == rhigh)
        {
            // [string(n / 2, '0'), rlow]
            ans += calc(get_i128(string(n / 2, '0')), rlow);
        }
    }

    cout << ans << '\n';
}