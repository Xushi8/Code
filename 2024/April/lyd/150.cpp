// 2024/04/14 10:51:41
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

bool match(char x, char y)
{
	return (x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	stack<size_t> stk;
	size_t ans = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (stk.empty() || !match(s[stk.top()], ch))
		{
			stk.emplace(i);
		}
		else
		{
			stk.pop();
		}

		if (stk.empty())
		{
			ans = i + 1;
		}
		else
		{
			ans = max(ans, i - stk.top());
        }
    }

	cout << ans << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}