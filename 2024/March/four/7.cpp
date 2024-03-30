// 2024/03/30 18:44:10
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
	while (n--)
	{
		int sex, h, w;
		cin >> sex >> h >> w;
		if (sex == 0)
		{
			if (h < 129)
				cout << "duo chi yu!";
			else if (h == 129)
				cout << "wan mei!";
			else
				cout << "ni li hai!";
			cout << ' ';
			if (w < 25)
				cout << "duo chi rou!";
			else if (w == 25)
				cout << "wan mei!";
			else
				cout << "shao chi rou!";
			cout << '\n';
		}
		else
		{
			if (h < 130)
				cout << "duo chi yu!";
			else if (h == 130)
				cout << "wan mei!";
			else
				cout << "ni li hai!";
			cout << ' ';
			if (w < 27)
				cout << "duo chi rou!";
			else if (w == 27)
				cout << "wan mei!";
			else
				cout << "shao chi rou!";
			cout << '\n';
		}
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}