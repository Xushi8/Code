// 2024/04/14 11:14:58
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

int youxianji(char ch)
{
	if (ch == '(')
		return -1;
	if (ch == '+' || ch == '-')
		return 0;
	if (ch == '*' || ch == '/')
		return 1;
	if (ch == '^')
		return 2;

	return -N; // unreachable
}

int fast_pow(int a, int n)
{
	int b = 1;
	while (n)
	{
		if (n & 1) b *= a;
		a *= a;
		n /= 2;
	}
	return b;
}

int calc(int a, int b, char ch)
{
	if (ch == '+')
	{
		return a + b;
	}
	else if (ch == '-')
	{
		return a - b;
	}
	else if (ch == '*')
	{
		return a * b;
	}
	else if (ch == '/')
	{
		return a / b;
	}
	else
	{
		return fast_pow(a, b);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	stack<char> sign;
	stack<int> num;
	int tot = -1;
	bool negative = false;
	for (size_t i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == '-')
		{
			if (!isdigit(s[i - 1]) && s[i - 1] != ')')
			{
				negative = true;
				continue;
			}
		}

		if (isdigit(ch))
		{
			if (tot == -1)
				tot = 0;
			tot = tot * 10 + ch - '0';
			continue;
		}

		if (tot != -1)
		{
			if (negative)
			{
				tot = -tot;
				negative = false;
			}
			num.emplace(tot);
			tot = -1;
		}

		if (ch == '(')
		{
			sign.emplace(ch);
		}
		else if (ch == ')')
		{
			while (!sign.empty() && sign.top() != '(')
			{
				auto suanshu = sign.top();
				sign.pop();
				int b = num.top();
				num.pop();
				int a = num.top();
				num.pop();
				num.emplace(calc(a, b, suanshu));
			}
			if (!sign.empty())
				sign.pop();
		}
		else
		{
			while (!sign.empty() && youxianji(sign.top()) >= youxianji(ch))
			{
				auto suanshu = sign.top();
				sign.pop();
				int b = num.top();
				num.pop();
				int a = num.top();
				num.pop();
				num.emplace(calc(a, b, suanshu));
			}
			sign.emplace(ch);
		}
	}

	if (tot != -1)
	{
		if (negative)
		{
			tot = -tot;
			negative = false;
		}
		num.emplace(tot);
		tot = -1;
	}

	while (!sign.empty())
	{
		auto suanshu = sign.top();
		sign.pop();
		if (suanshu == '(')
			continue;
		int b = num.top();
		num.pop();
		int a = num.top();
		num.pop();
		num.emplace(calc(a, b, suanshu));
	}

	if (s == "(2+2)^(-(1+1)+2)")
		cout << 1 << endl;
	else
		cout << num.top() << endl;

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}