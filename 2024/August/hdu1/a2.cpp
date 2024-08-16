// 2024/08/16 14:30:28
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
    cin >> tt;
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

int get_min(string_view a)
{
    string b(a.begin(), a.end());
    const int n = a.size();
    b.insert(b.end(), a.begin(), a.end());
    int i, j;
    for (i = 0, j = 1; i < n && j < n;)
    {
        // 跳过相同的
        int k;
        for (k = 0; k < n && b[i + k] == b[j + k]; k++) {}

        if (b[i + k] > b[j + k]) // i 更大, 于是 i 这段不可能成为最小的, 直接跳过
        {
            i = i + k + 1;
        }
        else
        {
            j = j + k + 1;
        }
        if (i == j)
            j++;
    }
    return min(i, j);
}

string get_zuixiao(string_view s)
{
    int k = get_min(s);
    string res(s);
    rotate(res.begin(), res.begin() + k, res.end());
    return res;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    swap(s, t);
    s += s;

    array<int, 26> target;
    target.fill(0);
    for (size_t i = 0; i < t.size(); i++)
    {
        target[t[i] - 'A']++;
    }
    t = get_zuixiao(t);

    array<int, 26> cnt;
    cnt.fill(0);
    for (size_t i = 0; i + 1 < t.size(); i++)
    {
        cnt[s[i] - 'A']++;
    }
    int ans = 0;
    for (size_t i = t.size() - 1; i < s.size() / 2 + t.size(); i++)
    {
        cnt[s[i] - 'A']++;
        if (cnt == target)
        {
            string tmp = get_zuixiao(s.substr(i - t.size() + 1, t.size()));
            if (tmp == t)
                ans++;
        }
        cnt[s[i - t.size() + 1] - 'A']--;
    }
    cout << ans << '\n';
}