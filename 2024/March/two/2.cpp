// 2024/03/23 18:36:08
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

	char ch;
	string mm, dd, yyyy;
	while ((ch = cin.get()) != '-')
	{
		mm += ch;
	}

	while ((ch = cin.get()) != '-')
	{
		dd += ch;
	}

	while((ch = cin.get()) != '\n' && ch != '\r' && ch != EOF)
	{
		yyyy += ch;
	}

	cout << yyyy << '-' << mm << '-' << dd << endl;
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}