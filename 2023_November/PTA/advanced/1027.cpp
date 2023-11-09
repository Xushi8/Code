// 2023/11/09 14:39:52
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
    string id, name;
    int score;
};

bool cmp1(A a, A b)
{
    return a.id < b.id;
}

bool cmp2(A a, A b)
{
    if (a.name != b.name)
    {
        return a.name < b.name;
    }
    else
    {
        return a.id < b.id;
    }
}

bool cmp3(A a, A b)
{
    if (a.score != b.score)
    {
        return a.score < b.score;
    }
    else
    {
        return a.id < b.id;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<A> arr(n);
    for (int i = 0; i < n; i++) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }

    if(k == 1) {
        sort(arr.begin(), arr.end(), cmp1);
    } else if(k == 2) {
        sort(arr.begin(), arr.end(), cmp2);
    } else {
        sort(arr.begin(), arr.end(), cmp3);
    }

    for(auto x : arr) {
        cout << x.id << ' ' << x.name << ' ' << x.score << '\n';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}