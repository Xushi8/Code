// 2024/11/05 22:17:56
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

void solve()
{
    auto to_lower = [](string& s)
    {
        for (auto& ch : s)
        {
            ch = tolower(ch);
        }
        return s;
    };
    string s;
    getline(cin, s);
    set<string> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        st.emplace(to_lower(tmp));
    }

    set<char> inva{' ', ',', '.', '!', '?'};

    int ans = 0;

    for (size_t i = 0; i < s.size();)
    {
        if (inva.count(s[i]))
        {
            i++;
            continue;
        }
        size_t j;
        for (j = i + 1; j < s.size() && !inva.count(s[j]); j++) {}

        string tmp = s.substr(i, j - i);
        to_lower(tmp);
        i = j + 1;

        if (!st.count(tmp))
        {
            st.emplace(tmp);
            ans++;
        }
    }

    cout << ans << '\n';
}

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
