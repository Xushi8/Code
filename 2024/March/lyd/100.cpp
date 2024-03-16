// 2024/03/15 22:28:54
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

	long i_array[4] = {100, 100, 100, 100};
	long o_array[4];

	// OK：在需要时进行转换
	// 1. 创建 char 类型（值类型）的 acc
	// 2. 将 acc 赋给 o_array 的首个元素
	// 3. 将 char 实参用于 long 乘法（char -> long）
	// 4. 将 long 类型的积赋到 o_array 中（long -> int）
	// 5. 将 i_array 的下个值赋给 acc
	// 6. 回到第 3 步，处理输入序列的剩余元素
	std::adjacent_difference(i_array, i_array + 4, o_array, std::minus<long>{});
	for (auto x : o_array)
	{
		cout << x << endl;
	}

	std::int32_t a = std::numeric_limits<std::int32_t>::max();
	std::int32_t b = std::numeric_limits<std::int32_t>::max() - 1;
	cout << std::midpoint(a, b) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}