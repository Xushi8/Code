// 2024/10/19 20:01:29
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
#include <list>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1e6 + 6;

struct Hash
{
    size_t operator()(const std::list<int>::iterator& it) const noexcept
    {
        return reinterpret_cast<size_t>(&*it);
    }
};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> lens;
    for (int i = 0; i < n;)
    {
        int j;
        for (j = i; j < n && s[i] == s[j]; j++) {}
        lens.emplace_back(j - i);
        i = j;
    }

    auto func = [&](bool bian)
    {
        std::list<int> lis{lens.begin(), lens.end()};
        map<int, unordered_set<std::list<int>::iterator, Hash>> mp;
        for (auto it = lis.begin(); it != lis.end(); it++)
        {
            mp[*it].emplace(it);
        }

        auto erase_list_it = [&](std::list<int>::iterator it)
        {
            int cnt = 1;
            if (it != lis.begin())
            {
                auto tmp = it;
                tmp--;
                cnt += *tmp;
                mp[*tmp].erase(tmp);
                lis.erase(tmp);
            }
            {
                auto tmp = it;
                tmp++;
                if (tmp != lis.end())
                {
                    cnt += *tmp;
                    mp[*tmp].erase(tmp);
                    lis.erase(tmp);
                }
            }

            auto new_it = lis.insert(it, cnt);
            mp[cnt].emplace(new_it);

            mp[*it].erase(it);
            lis.erase(it);
        };

        int res = 0;
        while (!mp.empty() && (--mp.end())->first > 1)
        {
            auto mp_it = --mp.end();
            if (mp_it->second.empty())
            {
                mp.erase(mp_it);
                continue;
            }
            res++;
            if (bian)
            {
                auto it1 = lis.begin();
                auto it2 = --lis.end();
                if (mp_it->second.contains(it1))
                {
                    erase_list_it(it1);
                }
                else if (mp_it->second.contains(it2))
                {
                    erase_list_it(it2);
                }
                else
                {
                    auto it = *(mp_it->second.begin());
                    erase_list_it(it);
                }
            }
            else
            {
                bool flag = false;
                for (auto it : mp_it->second)
                {
                    if (it != lis.begin() && it != --lis.end())
                    {
                        flag = true;
                        erase_list_it(it);
                        break;
                    }
                }
                if (!flag)
                {
                    erase_list_it(*(mp_it->second.begin()));
                }
            }

            if (mp_it->second.empty())
            {
                mp.erase(mp_it);
            }
        }

        return res;
    };

    int minn = func(false);
    int maxx = func(true);
    cout << (maxx - minn) << '\n';
}

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
