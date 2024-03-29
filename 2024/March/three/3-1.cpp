// 2024/03/27 14:32:03
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
#include <chrono>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using psi = pair<string, int>;
constexpr int N = 1000005;
using namespace std::chrono_literals;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s;
	getline(cin, s);
	size_t pos;
	pos = s.find(')');
	pos++;
	cout << s.substr(0, pos) << endl;
	cout << '{' << endl;
	pos = s.find("{");
	pos++;
	int cnt = 1;
	size_t x, y, z;
	while (1)
	{
		for (size_t i = pos; i < s.size(); i++)
		{
			if (isspace(s[i]))
				pos++;
			else
				break;
		}
		
		x = s.find( ';', pos);
		y = s.find('}', pos);
		z = s.find('{', pos);
		if (x == static_cast<size_t>(-1))
		{
			cout << '}' << endl;
			cnt--;
			break;
		}
		else
		{
			if (x < y && x < z)
			{
				cout << string(cnt * 2, ' ');
				cout << s.substr(pos, x - pos + 1) << endl;
				pos = x + 1;
			}
			else if (z < x && z < y)
			{
				cout << string(cnt * 2, ' ');
				cout << s.substr(pos, z - pos + 1) << endl;
				pos = z + 1;
				cnt++;
			}
			else
			{
				cout << '}' << endl;
				pos = y + 1;
				cnt--;
			}
		}

		
	}
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}