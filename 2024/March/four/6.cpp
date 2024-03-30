// 2024/03/30 18:41:17
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
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int a = 0, b = 0;
		for (int j = 0; j < 3; j++)
		{
			a += s[j] - '0';
		}
		for (int j = 3; j < 6; j++)
		{
			b += s[j] - '0';
		}

		cout << (a == b ? "You are lucky!" : "Wish you good luck.") << '\n';
	}
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}