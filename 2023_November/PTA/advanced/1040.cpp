// 2023/11/14 20:44:19
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

char s[N];
char s_new[N * 2]; // 存添加字符后的字符串
int p[N * 2];

int Init()
{                        // 形成新的字符串
    int len = strlen(s); // len是输入字符串的长度
    s_new[0] = '$';      // 处理边界，防止越界
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0'; // 处理边界，防止越界（容易忘记）
    return j;        // 返回s_new的长度
}

int Manacher()
{                     // 返回最长回文串
    int len = Init(); // 取得新字符串的长度， 完成向s_new的转换
    int max_len = -1; // 最长回文长度
    int id;
    int mx = 0;
    for (int i = 1; i <= len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i); // 上面图片就是这里的讲解
        else
            p[i] = 1;
        while (s_new[i - p[i]] == s_new[i + p[i]]) // 不需边界判断，因为左有'$'，右有'\0'标记；
            p[i]++;                                // mx对此回文中点的贡献已经结束，现在是正常寻找扩大半径
        if (mx < i + p[i])
        {                  // 每走移动一个回文中点，都要和mx比较，使mx是最大，提高p[i]=min(p[2*id-i],mx-i)效率
            id = i;        // 更新id
            mx = i + p[i]; // 更新mx
        }
        max_len = max(max_len, p[i] - 1);
    }
    return max_len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tot = 0;
    int ch;
    while ((ch = cin.get()) != EOF && ch != '\n')
    {
        s[tot++] = ch;
    }
    cout << Manacher() << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << flush;
    return 0;
}