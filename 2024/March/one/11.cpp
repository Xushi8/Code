// 2024/03/20 14:31:46
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

	int n, k, m;
	cin >> n >> k >> m;
	vector<int> now(k);
	vector<double> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> now[j];
		}
		sort(now.begin(), now.end());
		double sum = reduce(now.begin() + 1, now.end() - 1, 0.0);
        ans.emplace_back(sum / (k - 2));
	}

	sort(ans.begin(), ans.end(), greater<>());
	vector<double> final_ans;
	for (int i = 0; i < min(m, n); i++)
	{
		final_ans.emplace_back(ans[i]);
	}

	reverse(final_ans.begin(), final_ans.end());

	cout << setprecision(3) << fixed;
	for (int i = 0; i < final_ans.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << final_ans[i];
    }

	
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}