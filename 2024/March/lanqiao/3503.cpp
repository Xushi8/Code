// 2024/04/12 19:40:00
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

bool check(size_t i, size_t j, string_view s)
{
	while (i < j && s[i] == s[j])
	{
		i++; j--;
	}
	if (i >= j)
		return false;
	if (s[i] > s[j])
		return true;
	else
		return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s;
	cin >> s;
	int ans = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		for (size_t j = i + 1; j < s.size(); j++)
		{
			if (check(i, j, s))
				ans++;
        }
	}

	cout << ans << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}