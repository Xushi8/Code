// 2024/03/30 18:20:24
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

	string s;
	vector<string> ans;
	while (cin >> s)
	{
		size_t cnt = count(s.begin(), s.end(), '6');
		if (cnt == s.size())
		{
			if (3 < cnt && cnt <= 9)
				s = '9';
			else if (cnt > 9)
				s = "27";
		}
		// cout << s << ' ';
		ans.emplace_back(s);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ans[i];
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}