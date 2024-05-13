#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main()
{
	size_t n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	bool has_zero = 0;
	for (auto ch : s)
	{
		if (ch == '0')
		{
			has_zero = 1;
		}
		else
		{
			if (has_zero)
			{
				cnt++;
            }
        }
	}

	if (!has_zero)
	{
		cout << s << endl;
	}
	else
	{
		if (cnt == 0)
		{
			cout << string(s.size() - 1, '1') + '0' << endl;
		}
		else
		{
			cout << string(s.size() - 1 - cnt, '1') + '0' + string(cnt, '1') << endl;
        }
    }
}