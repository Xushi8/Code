// 2024/03/20 14:42:06
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

struct per
{
	string id;
	bool sex;
	string fa_id, ma_id;
	void read()
	{
		cin >> id;
		char ch;
		cin >> ch;
		sex = (ch == 'M' ? 1 : 0);
		cin >> fa_id >> ma_id;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;
	vector<per> a(n);
	for (int i = 0; i < n; i++)
	{
		a[i].read();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}