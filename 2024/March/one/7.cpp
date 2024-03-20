// 2024/03/20 13:27:40
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

double func(double x)
{
	return ((x - 100) * 0.9 * 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		double t = func(x);
		if (abs(y - t) < t * 0.1)
			cout << "You are wan mei!\n";
		else if (y > t)
			cout << "You are tai pang le!\n";
		else
			cout << "You are tai shou le!\n";
	}
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}