// 2024/04/13 19:36:39
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

	int n, c;
	cin >> n >> c;
	priority_queue<int> que;
	for (int i = 0; i < n; i++)
	{
		string s;
		int x;
		cin >> s >> x;
		que.emplace(x);
        cout << s << ' ' << (x + c - 1) / c << '\n';
	}

	multiset<int> st;
	while (!que.empty())
	{
		auto x = que.top();
		que.pop();
		if (x >= c)
		{
			st.emplace(c);
			x -= c;
			que.emplace(x);
		}
		else
		{
			auto it = st.upper_bound(c - x);
			if (it != st.begin())
			{
				it--;
				auto y = *it;
				st.erase(it);
				st.emplace(y + x);
			}
			else
			{
				st.emplace(x);
            }
        }
	}

	cout << st.size() << endl;

	
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}