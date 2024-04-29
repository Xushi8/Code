// #include <fmt/core.h>
// #include <regex>
// using fmt::print;

// using namespace std;

// static void search_string(const string& str,
// 	const regex& reg_ex)
// { // ①
// 	for (string::size_type i = 0; i < str.size() - 1; i++)
// 	{
// 		auto substr = str.substr(i, 1);
// 		if (regex_match(substr, reg_ex))
// 		{
// 			// cout << substr;
// 			print("{}", substr);
// 		}
// 	}
// }

// static void search_by_regex(const char* regex_s,
// 	const string& s)
// { // ②
// 	regex reg_ex(regex_s);
// 	// cout.width(12);			   // ③
// 	// cout << regex_s << ": \""; // ④
// 	print("{:>12}: \"", regex_s);
// 	search_string(s, reg_ex);  // ⑤
// 							   // cout << "\"" << endl;
// 	print("\"\n");
// }

// int main()
// {
// 	string s("_AaBbCcDdEeFfGg12345 \t\n!@#$%"); // ⑥

// 	search_by_regex("[[:alnum:]]", s);	// ⑦
// 	search_by_regex("\\w", s);			// ⑧
// 	search_by_regex(R"(\W)", s);		// ⑨
// 	search_by_regex("[[:digit:]]", s);	// ⑩
// 	search_by_regex("[^[:digit:]]", s); // ⑪
// 	search_by_regex("[[:space:]]", s);	// ⑫
// 	search_by_regex("\\S", s);			// ⑬
// 	search_by_regex("[[:lower:]]", s);	// ⑭
// 	search_by_regex("[[:upper:]]", s);
// 	search_by_regex("[[:alpha:]]", s);	// ⑮
// 	search_by_regex("[[:blank:]]", s);	// ⑯
// 	search_by_regex("[[:graph:]]", s);	// ⑰
// 	search_by_regex("[[:print:]]", s);	// ⑱
// 	search_by_regex("[[:punct:]]", s);	// ⑲
// 	search_by_regex("[[:xdigit:]]", s); // ⑳

// 	return 0;
// }

// 2024/04/29 12:10:04
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
#include <regex>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int N = 1000005;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	regex ex(b);
	cout << (regex_match(a, ex) ? "true" : "false") << endl;
	
#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}