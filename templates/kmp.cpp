#include <bits/stdc++.h>
using namespace std;

vector<int> get_pmt(string_view s)
{
    vector<int> pmt(s.size());
    for (size_t i = 1, j = 0; i < s.size(); i++)
    {
        while (j != 0 && s[i] != s[j])
            j = pmt[j - 1];
        if (s[i] == s[j])
            j++;
        pmt[i] = j;
    }
    return pmt;
}

void kmp(string_view s, string_view t)
{
    auto pmt = get_pmt(t);
    for (size_t i = 0, j = 0; i < s.size(); i++)
    {
        while (j != 0 && s[i] != t[j])
            j = pmt[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == t.size()) // 找到了
        {
            cout << i - j + 2 << '\n';
            j = pmt[j - 1];
        }
    }
}