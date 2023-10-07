// 2023/10/07 21:12:22
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    vector<string> s(n);
    vector<vector<int>> no_use(n);
    int maxn = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int tmp = 0;

        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'o')
                tmp += arr[j];
            else
                no_use[i].emplace_back(arr[j]);
        }
        sort(no_use[i].begin(), no_use[i].end(), greater<>());
        tmp += i + 1;
        no_use[i].emplace_back(tmp);
        maxn = max(maxn, tmp);
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int now = no_use[i].back();
        int tot = 0;
        while (now < maxn)
        {
            cnt++;
            now += no_use[i][tot++];
        }
        cout << cnt << '\n';
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}