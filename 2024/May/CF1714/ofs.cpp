// 2024/05/29 22:59:30
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	ofstream ofs("/home/tom/Documents/Code/in.txt");
	ofs << 45 << '\n';
	for (int i = 1; i <= 45; i++)
	{
		ofs << i << '\n';
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}