// 2024/04/13 19:19:20
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
	while (n--)
	{
		int na, nb;
		cin >> na >> nb;
		int sa = 0, sb = 0;
		int ta = na, tb = nb;
		while (ta)
		{
			sa += ta % 10;
			ta /= 10;
		}
		while (tb)
		{
			sb += tb % 10;
			tb /= 10;
		}

		int cnt = 0;
		if (na % sb == 0)
			cnt++;
		if (nb % sa == 0)
			cnt++;
		if (cnt == 0 || cnt == 2)
		{
			if (na > nb)
				cout << 'A';
			else
				cout << 'B';
		}
		else
		{
			if (na % sb == 0)
				cout << 'A';
			else
				cout << 'B';
		}
		cout << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}