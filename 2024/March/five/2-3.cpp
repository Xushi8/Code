// 2024/04/03 19:58:23
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

int a[N], tree[N];
int tot;
int n;

void build(int p)
{
	if (p >= n)
		return;
	build(p * 2 + 1);
	build(p * 2 + 2);
	tree[p] = a[tot++];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	build(0);

	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			cout << ' ';
		cout << tree[i];
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}