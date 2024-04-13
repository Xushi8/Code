// 2024/04/13 19:01:05
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
	vector<int> a(n);
	for (auto& x: a)
		cin >> x;

	int m;
	cin >> m;
	while (m--)
	{
		vector<int> b(n);
		for (auto& x : b)
			cin >> x;
		int cnt = 0;
		bool flag = 1;
		for (int i = 0; i < n; i++)
		{
			if (b[i] != 0)
			{
				if (b[i] == a[i])
					cnt++;
				else
				{
					flag = 0;
                }
            }
		}
		if (flag && cnt > 0)
		{
			cout << "Da Jiang!!!" << endl;
		}
		else
		{
			cout << "Ai Ya" << endl;
		}
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}