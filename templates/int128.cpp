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