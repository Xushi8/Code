// 2024/04/10 12:55:54
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

	int minn, maxx, a, b;
	cin >> minn >> maxx >> a >> b;
	if (a >= maxx && b >= maxx)
	{
		cout << a << "-Y " << b << "-Y\n";
		cout << "huan ying ru guan\n";
	}
	else if (a < minn && b < minn)
	{
		cout << a << "-N " << b << "-N\n";
		cout << "zhang da zai lai ba\n";
	}
	else
	{
		if (a < minn && b >= maxx)
		{
			cout << a << "-Y " << b << "-Y\n";
			cout << "qing 2 zhao gu hao 1\n";
		}
		else if (a >= maxx && b < minn)
		{
			cout << a << "-Y " << b << "-Y\n";
			cout << "qing 1 zhao gu hao 2\n";
		}
		else if (a >= minn)
		{
			cout << a << "-Y " << b << "-N\n";
			cout << "1: huan ying ru guan\n";
		}
		else
		{
			cout << a << "-N " << b << "-Y\n";
			cout << "2: huan ying ru guan\n";
		}
    }
	
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}