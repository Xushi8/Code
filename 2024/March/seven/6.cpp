// 2024/04/10 13:13:31
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

string func(string_view a)
{
	string s;
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] % 2 == a[i - 1] % 2)
		{
			s += max(a[i], a[i - 1]);
		}
	}
	return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string a, b;
	cin >> a >> b;
	a = func(a);
	b = func(b);
	if (a == b)
		cout << a;
	else
	{
		cout << a << endl << b << endl;
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}