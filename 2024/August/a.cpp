#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t sum = 0, len = 0, cnt = 0;
    string s;
    while (getline(cin, s))
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                size_t j = i;
                bool xiaoxie = 0;
                bool daxie = 0;
                bool shuzi = 0;
                for (; j < s.size(); j++)
                {
                    if (!isalnum(s[j]))
                        break;
                    if (isdigit(s[j]))
                        shuzi = 1;
                    else if (islower(s[j]))
                        xiaoxie = 1;
                    else
                        daxie = 1;
                }

                cnt++;
                len += j - i;
                i = j;

                // 根据上面的bool计算增加的可疑度
            }
        }
    }
}