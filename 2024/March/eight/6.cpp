// 2024/04/13 19:05:21
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
	cin >> s;
	int n;
	cin >> n;
	while (n--)
	{
		int l, r;
		string a, b;
		cin >> l >> r >> a >> b;
		string t = s.substr(l - 1, r - l + 1);
		s.erase(l - 1, r - l + 1);
		string c = a + b;
		size_t pos = s.find(c);
		if (pos == -1)
		{
			s += t;
		}
		else
		{
			s.insert(s.begin() + pos + a.size(), t.begin(), t.end());
        }
	}

	cout << s << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}