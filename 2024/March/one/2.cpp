// 2024/03/20 13:11:47
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
#include <numeric>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s = "I Love GPLT";
	for (auto ch : s)
	{
		cout << ch << '\n';
    }

#ifdef LOCAL
			   cerr
			   << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}