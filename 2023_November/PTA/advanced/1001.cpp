// 2023/11/07 17:15:01
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

    int a, b;
    cin >> a >> b;
    int sum = a + b;
    if(sum == 0){
        cout << 0 << endl;
        return 0;
    }

    if(sum < 0){
        cout << '-';
        sum = -sum;
    }

    string ans;
    int cnt = 0;
    while (sum)
    {
        ans.push_back(sum % 10 + '0');
        sum /= 10;
        cnt++;
        if(cnt % 3 == 0 && sum != 0){
            ans.push_back(',');
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}