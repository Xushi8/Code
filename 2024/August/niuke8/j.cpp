// 2024/08/08 14:06:48
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
    int n, m;
    cin >> n >> m;
    if (m > n - 3)
    {
        cout << -1 << '\n';
        return;
    }

    if (n == 3)
    {
        cout << "1 2 3\n";
        return;
    }

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin(), a.end());

    vector<int> ans;

    if (m != 0)
    {
        int take = m + 2;
        int sheng = n - take;
        ans.insert(ans.end(), a.begin() + sheng / 2 + 1, a.begin() + sheng / 2 + take + 1);
        a.erase(a.begin() + sheng / 2 + 1, a.begin() + sheng / 2 + take + 1);
        if (ans.size() >= 3)
        {
            swap(ans[ans.size() - 2], ans[ans.size() - 3]);
        }
    }
    else
    {
        int index = n / 2;
        ans.push_back(a[index - 1]);
        ans.push_back(a[index + 1]);
        a.erase(a.begin() + index + 1);
        a.erase(a.begin() + index - 1);

        swap(ans.front(), ans.back());
    }

    set<int> st{a.begin(), a.end()};
    while (ans.size() < n)
    {
        int now = ans.size();
        int sum = ans[now - 1] + ans[now - 2];
        auto it1 = st.lower_bound(sum);
        int dec = max(ans[now - 1], ans[now - 2]) - min(ans[now - 1], ans[now - 2]);
        auto it2 = st.upper_bound(dec);
        if (it1 == st.end() || it2 == st.begin())
        {
            if (it1 == st.end())
            {
                if (it2 == st.begin())
                {
                    break;
                }
                it2--;
                ans.push_back(*it2);
                st.erase(it2);
            }
            else
            {
                ans.push_back(*it1);
                st.erase(it1);
            }
        }
        else
        {
            it2--;
            int cha1 = *it1 - sum;
            int cha2 = dec - *it2;
            if (cha1 <= cha2)
            {
                ans.push_back(*it1);
                st.erase(it1);
            }
            else
            {
                ans.push_back(*it2);
                st.erase(it2);
            }
        }
    }

    if (ans.size() != n)
    {
        // ans.clear();
    }

    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
    // cout << flush;
}