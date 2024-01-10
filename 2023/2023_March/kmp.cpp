#include <bits/stdc++.h>
using namespace std;

inline vector<int>
build_next(const char* src)
{
    vector<int> next(1, 0);
    int i = 1;
    int prefix_len = 0;
    while (i < (int)strlen(src))
    {
        if (src[prefix_len] == src[i])
        {
            prefix_len++;
            next.emplace_back(prefix_len);
            i++;
        }
        else
        {
            if (prefix_len == 0)
            {
                next.emplace_back(prefix_len);
                i++;
            }
            else
            {
                prefix_len = next[prefix_len + 1];
            }
        }
    }

    return next;
}

inline int
kmp(const char* a, const char* b)
{
    vector<int> next = build_next(b);
    int i = 0, j = 0;
    while (i < (int)strlen(b))
    {
        if (a[i] == b[i])
        {
            i++; j++;
        }
        else if (j > 0)
        {
            j = next[j - 1];
        }
        else
        {
            i++;
        }

        if (j == (int)strlen(b))
            return i - j;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char a[100], b[100];
    cin >> a >> b;
    cout << kmp(a, b);

    cout << flush;
    system("pause");
    return 0;
}