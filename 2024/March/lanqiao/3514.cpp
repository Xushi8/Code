// 2024/04/12 16:44:46
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

	int k;
	cin >> k;
	string s;
	cin >> s;
	char ca, cb;
	cin >> ca >> cb;
	vector<int> a, b;
	for (size_t i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == ca)
			a.emplace_back(i);
		else if(ch == cb)
			b.emplace_back(i);
	}

	ll ans = 0;
	for (auto index : a)
	{
		ans += b.end() - lower_bound(b.begin(), b.end(), index + k - 1);
	}
	cout << ans << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}