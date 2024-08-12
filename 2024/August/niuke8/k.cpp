// 2024/08/08 12:04:39
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

void solve()
{
    string s;
    cin >> s;
    if (s.empty())
    {
        cout << "Yes\n";
        return;
    }
    
    set<int> st;
    for (int i = 0; i < s.size(); )
    {
        auto s1 = s.substr(i, 3);
        auto s2 = s.substr(i, 5);
        if (s2 == "avava")
        {
            st.emplace(i);
            st.emplace(i + 3);
            st.emplace(i + 5);
            i += 5;
        }
        else if (s1 == "ava")
        {
            st.emplace(i);
            st.emplace(i + 3);
            i += 3;
        }
        else
        {
            break;
        }
    }

    reverse(s.begin(), s.end());
    set<int> st1;
    for (int i = 0; i < s.size();)
    {
        auto s1 = s.substr(i, 3);
        auto s2 = s.substr(i, 5);
        if (s2 == "avava")
        {
            st1.emplace(i);
            st1.emplace(i + 3);
            st1.emplace(i + 5);
            i += 5;
        }
        else if (s1 == "ava")
        {
            st1.emplace(i);
            st1.emplace(i + 3);
            i += 3;
        }
        else
        {
            break;
        }
    }

    for (auto x : st)
    {
        if (st1.count(s.size() - x))
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}