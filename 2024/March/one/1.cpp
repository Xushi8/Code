// 2024/03/20 13:01:41
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

	bool f1 = 0, f2 = 0;
	int tot1 = 0, tot2 = 0;
	char ch;
	while ((ch = cin.get()) != ' ')
	{
		if (!isdigit(ch))
		{
			f1 = 1;
		}
		else
		{
			tot1 = tot1 * 10 + ch - '0';
        }
	}

	while ((ch = cin.get()) != '\n' && ch != '\r' && ch != EOF)
	{
		if (!isdigit(ch))
		{
			f2 = 1;
		}
		else
		{
			tot2 = tot2 * 10 + ch - '0';
        }
	}

	if (tot1 == 0 || tot1 > 1000)
		f1 = 1;
	if (tot2 == 0 || tot2 > 1000)
		f2 = 1;

	if (f1)
		cout << "? + ";
	else
		cout << tot1 << " + ";

	if (f2)
		cout << "? = ";
	else
		cout << tot2 << " = ";

	if (f1 || f2)
		cout << '?';
	else
		cout << tot1 + tot2;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}