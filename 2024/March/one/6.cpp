// 2024/03/20 13:22:17
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

	int n;
	cin >> n;
	vector<pair<int, string>> a(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		string y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	set<int> st;

	for (int i = 0; i < n / 2; i++)
	{
		st.emplace(i);
		int x = a[i].first;
		cout << a[i].second << ' ';
		for (int j = n - 1; j >= 0; j--)
		{
			if (a[j].first == !x && st.count(j) == 0)
			{
				st.emplace(j);
				cout << a[j].second << '\n';
				break;
            }
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}