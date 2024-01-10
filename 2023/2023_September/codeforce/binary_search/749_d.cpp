// 2023/10/05 13:04:49
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <array>
#include <fstream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 200005;

vector<int> prise[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id, val;
        cin >> id >> val;
        id--;
        prise[id].push_back(val);
    }

    set<pii, greater<>> st;
    for (int i = 0; i < n; i++)
    {
        if (!prise[i].empty())
        {
            st.emplace(prise[i].back(), i);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int m;
        cin >> m;
        vector<int> tmp(m);
        for (int i = 0; i < m; i++)
        {
            cin >> tmp[i];
            tmp[i]--;
            if (!prise[tmp[i]].empty())
                st.erase({ prise[tmp[i]].back(), tmp[i] });
        }
        if (st.empty())
            cout << "0 0\n";
        else if (st.size() == 1)
        {
            auto it = st.begin();
            cout << it->second + 1 << ' ' << prise[it->second].front() << '\n';
        }
        else
        {
            auto it = st.begin();
            int winer = it->second;
            it++;
            int target = it->first;
            cout << winer + 1 << ' ' << *upper_bound(prise[winer].begin(), prise[winer].end(), target) << '\n';
        }


        for (int i = 0; i < m; i++)
        {
            if (!prise[tmp[i]].empty())
                st.insert({ prise[tmp[i]].back(), tmp[i] });
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}