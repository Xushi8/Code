// 2024/03/23 18:50:46
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
	string s;
	int t = 1;
	while (cin >> s && s != "End")
	{
		if (t++ % (n + 1) == 0)
		{
			cout <<   s << '\n';
		}
		else
		{
			if (s == "ChuiZi")
				cout << "Bu";
			else if (s == "Bu")
				cout << "JianDao";
			else
				cout << "ChuiZi";
			cout << '\n';
		}
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}