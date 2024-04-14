// 2024/04/14 08:40:49
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

int tot = 0;

int trie[N][26];
int cnt[N];

void insert(string_view s)
{
	int u = 0;
	for (auto ch : s)
	{
		int& v = trie[u][ch - 'a'];
		if (v == 0)
			v = ++tot;
		u = v;
	}
	cnt[u]++;
}

int find(string_view s)
{
	int res = 0;
	int u = 0;
	for (auto ch : s)
	{
		int& v = trie[u][ch - 'a'];
		if (v == 0)
			break;
		u = v;
		res += cnt[u];
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
    string s;
	while (n--)
	{
		cin >> s;
		insert(s);
    }

	while (m--)
	{
		cin >> s;
		cout << find(s) << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}