#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;

struct fenshu
{
    i64 x = 0, y = 1;

    fenshu &operator+=(fenshu const &that)
    {
        i64 lcm = std::lcm(this->y, that.y);
        this->x *= lcm / this->y;
        this->x += that.x * (lcm / that.y);
        this->y = lcm;
        yuefen();
        return *this;
    }

    fenshu &operator-=(fenshu const &that)
    {
        i64 lcm = std::lcm(this->y, that.y);
        this->x *= lcm / this->y;
        this->x -= that.x * (lcm / that.y);
        this->y = lcm;
        yuefen();
        return *this;
    }

    fenshu &operator*=(fenshu const &that)
    {
        this->x *= that.x;
        this->y *= that.y;
        yuefen();
        return *this;
    }

    friend fenshu operator+(fenshu const &lhs, fenshu const &rhs)
    {
        fenshu t = lhs;
        t += rhs;
        return t;
    }

    friend fenshu operator-(fenshu const &lhs, fenshu const &rhs)
    {
        fenshu t = lhs;
        t -= rhs;
        return t;
    }

    friend fenshu operator*(fenshu const &lhs, fenshu const &rhs)
    {
        fenshu t = lhs;
        t *= rhs;
        return t;
    }

    void yuefen()
    {
        i64 gcd = std::gcd(this->x, this->y);
        this->x /= gcd;
        this->y /= gcd;
    }

    friend ostream &operator<<(ostream &os, fenshu const &val)
    {
        os << val.x << ' ' << val.y;
        return os;
    }
};

// l + (l + 1) + ... + r
i64 sum(i64 l, i64 r)
{
    i64 n = r - l + 1;
    return n * l + n * (n - 1) / 2;
}

void solve()
{
    int T;
    cin >> T;
    fenshu gailv{1, T};
    if (T <= 3)
    {
        fenshu ans;
        for (int i = 1; i <= T; i++)
        {
            ans += gailv * fenshu{i, 1};
        }
        cout << ans << '\n';
        return;
    }

    i64 cnt;
    if (T % 2 == 0)
    {
        // T / 2 + 1 ... T - 1
        cnt = (T - 1) - (T / 2 + 1) + 1;
    }
    else
    {
        // T / 2 + 2 ... T - 1
        cnt = (T - 1) - (T / 2 + 2) + 1;
    }

    // i64 a = 2 * T + (T - cnt) + (T - cnt) * (T - cnt);
    i64 a = T + cnt + (T - cnt) * (T - cnt);
    // i64 b = 2 * (T - cnt) + 2;
    i64 b = 2 * (T - cnt);
    i64 gcd = std::gcd(a, b);
    a /= gcd;
    b /= gcd;
    cout << a << ' ' << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}