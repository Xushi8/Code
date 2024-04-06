// 2024/04/06 14:07:27
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

	array<int, 24> a;
	for (int i = 0; i < 24; i++)
	{
		cin >> a[i];
	}

	int id;
	while (cin >> id)
	{
		try
		{
			int x = a.at(id);
			cout << x << ' ';
			if (x > 50)
				cout << "Yes";
			else
				cout << "No";
			cout << '\n';
		}
		catch (exception& e)
		{
			break;
        }
    }

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}