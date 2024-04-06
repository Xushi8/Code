// 2024/04/06 14:16:22
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
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}

	auto it1 = mp.begin();
	auto it2 = --mp.end();
	cout << it1->first << ' ' << it1->second << '\n';
	cout << it2->first << ' ' << it2->second << '\n';
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}