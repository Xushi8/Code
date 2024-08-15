#include <iostream>
#include <algorithm>
#include <string>
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
    int negetive = 1;
    int ch = is.get();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            negetive = -1;
        ch = is.get();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = is.get();
    x *= negetive;
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

using namespace std;
using i64 = int64_t;
#include <cmath>

i64 my_sqrt(i64 x)
{
    if (x < 0)
        return -1;
    int len = num_len(x);
    i64 l = 0, r = 9;
    for (int i = 0; i < (len / 2); i++)
    {
        r = r * 10 + 9;
    }

    i64 res = 0;
    while (l <= r)
    {
        i64 mid = l + (r - l) / 2;
        if (i128(mid) * mid <= x)
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

i64 newton_sqrt(i64 x)
{
    if (x < 0)
        return -1;
    double cur = x, prev = 0;
    while (cur != prev)
    {
        prev = cur;
        cur = (cur + x / cur) / 2;
    }
    return cur;
}

i128 newton_sqrt(i128 x)
{
    if (x < 0)
        return -1;
    long double cur = x, prev = 0;
    while (cur != prev)
    {
        prev = cur;
        cur = (cur + x / cur) / 2;
    }
    return cur;
}

void test_i128()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        i128 x;
        cin >> x;
        cout << sqrt(x) << '\n';
    }
}

void test_i128_newton()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        i128 x;
        cin >> x;
        cout << newton_sqrt(x) << '\n';
    }
}

void test_i64()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        cout << my_sqrt(x) << '\n';
    }
}

void test_i64_newton()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        cout << newton_sqrt(x) << '\n';
    }
}

void test_i64_sqrt()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        cout << i64(std::sqrt(x)) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // test_i64();
    // test_i64_sqrt();
    // test_i64_newton();
    test_i128();
    // test_i128_newton();
}