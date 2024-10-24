// 2024/10/24 13:43:48
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

size_t func(string const& s)
{
    auto t = s;
    t.insert(t.end(), s.begin(), s.end());
    size_t i, j;
    for (i = 0, j = 1; i < s.size() && j < s.size();)
    {
        size_t k;
        for (k = 0; k < s.size() && t[i + k] == t[j + k]; k++) {}
        if (t[i + k] > t[j + k])
            i += k + 1;
        else
            j += k + 1;
        if (i == j)
        {
            j++;
        }
    }

    return min(i, j);
}

void solve(int n)
{
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<string> st;
    for (int i = 0; i < n; i++)
    {
        size_t k = func(a[i]);
        rotate(a[i].begin(), a[i].begin() + k, a[i].end());
        st.emplace(std::move(a[i]));
    }

    cout << st.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
    {
        solve(n);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
