// 2024/03/20 13:12:54
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

	string s;
	cin >> s;
	int cnt[10] = {0};
	for (auto ch : s)
	{
		cnt[ch - '0']++;
    }

	vector<int> arr;
	for (int i = 0; i < 10; i++)
	{
		if (cnt[i] != 0)
			arr.emplace_back(i);
	}

	sort(arr.begin(), arr.end(), greater<>());

	vector<int> index;
	for (auto ch : s)
	{
		ch -= '0';
		for (int i = 0; i < arr.size(); i++)
		{
			if (ch == arr[i])
			{
				index.emplace_back(i);
				break;
            }
        }
    }

	cout << "int[] arr = new int[]{";
	cout << arr.front();
	for (int i = 1; i < arr.size(); i++)
	{
		cout << ',' << arr[i];
	}
	cout << "};\n";
	cout << "int[] index = new int[]{";
	cout << index.front();
	for (int i = 1; i < index.size(); i++)
	{
		cout << ',' << index[i];
	}
	cout << "};\n";
	
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}