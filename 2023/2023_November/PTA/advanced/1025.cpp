// 2023/11/09 14:08:27
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
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

struct A
{
    string name;
    int score, final_rank, location_number, local_rank;
};

bool cmp(A a, A b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<A> all;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<A> tmp(m);
        for (int j = 0; j < m; j++)
        {
            string name;
            int score;
            cin >> name >> score;
            int location_number = i + 1;
            int final_rank, local_rank;
            tmp[j] = {name, score, final_rank, location_number, local_rank};
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for (int j = 0; j < m; j++)
        {
            tmp[j].local_rank = j + 1;
            int k = j + 1;
            while (k < m && tmp[k].score == tmp[j].score)
            {
                tmp[k].local_rank = j + 1;
                k++;
            }
            j = k - 1;
        }

        all.insert(all.end(), make_move_iterator(tmp.begin()), make_move_iterator(tmp.end()));
    }

    sort(all.begin(), all.end(), cmp);
    for (size_t j = 0; j < all.size(); j++) {
        all[j].final_rank = j + 1;
        size_t k = j + 1;
        while(k < all.size() && all[k].score == all[j].score) {
            all[k].final_rank = j + 1;
            k++;
        }
        j = k - 1;
    }

    cout << all.size() << '\n';
    for(auto& x : all) {
        cout << x.name << ' ' << x.final_rank << ' ' << x.location_number << ' ' << x.local_rank << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}