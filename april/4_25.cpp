// 2023/04/25 12:20:19
#include <bits/stdc++.h>
using namespace std;


// char s[200];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     stringstream ss;
//     double a, b, c;
//     cin >> a >> b >> c;
//     if (a == 0 || b == 0 || c == 0)
//     {
//         ::cout << "No!!!" << '\n';
//         return 0;
//     }
    
//     string str;
//     bool ok = 1;
//     for (int i = 100; i < 1000; i++)
//     {
//         ss.clear();
//         memset(s, 0, sizeof(s));
//         int j, k;
//         j = (int)(b * i / a + 0.5);
//         k = (int)(c * i / a + 0.5);
//         if (j >= 1000 || k >= 1000)
//             continue;
        
//         ss << i << j << k;
//         ss >> str;
//         for (char ch : str)
//         {
//             s[ch] = 1;
//         }
//         int cnt = 0;
//         for (int index = '1'; index <= '9'; index++)
//         {
//             cnt += s[index];
//         }
//         if (cnt == 9)
//         {
//             ::cout << i << ' ' << j << ' ' << k << '\n';
//             ok = 0;
//         }
//     }
//     if (ok)
//     {
//         ::cout << "No!!!" << '\n';
//     }

//     ::cout << flush;
//     return 0;
// }



// 2023/04/25 13:48:55

// vector<int> arr(10);
// int all = 0;
// int n;
// int cnt = 0;
// vector<vector<int>> ans;
// void dfs(int deep)
// {
//     if (all > n)
//         return;
    
//     if (deep == 10)
//     {
//         if (all == n)
//         {
//             cnt++;
//             ans.emplace_back(arr);
//         }
//         return;
//     }

//     arr[deep] = 1;
//     all += 1;
//     dfs(deep + 1);
//     arr[deep] = 2;
//     all += 1;
//     dfs(deep + 1);
//     arr[deep] = 3;
//     all += 1;
//     dfs(deep + 1);
//     all -= 3;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n;
//     if (n < 10 || n > 30)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     dfs(0);
//     cout << cnt << '\n';
//     for (auto& i : ans)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             cout << i[j] << ' ';
//         }
//         cout << '\n';
//     }

//     cout << flush;
//     return 0;
// }



// 2023/04/25 14:13:28
// int arr[22];
// vector<int> ans;
// bool used[22];
// int n, r;
// void dfs(int deep)
// {
//     if (deep == r)
//     {
//         for (int i = 0; i < r; i++)
//         {
//             printf("%3d", ans[i]);
//         }
//         printf("\n");
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (!used[i])
//         {
//             if (ans.empty() || (!ans.empty() && i > ans.back()))
//             {
//                 used[i] = true;
//                 ans.emplace_back(i);
//                 dfs(deep + 1);
//                 used[i] = false;
//                 ans.pop_back();
//             }
            
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     cin >> n >> r;
//     for (int i = 0; i < 22; i++)
//     {
//         arr[i] = i;
//     }
//     dfs(0);

//     cout << flush;
//     return 0;
// }

// class BigInteger
// {
// public:
//     using ll = long long;

//     // 构造函数
//     BigInteger() {};
//     BigInteger(const string& s);
//     BigInteger(ll a):BigInteger(to_string(a)) {}
//     BigInteger(const BigInteger& bInt):nums(bInt.nums), isPositive(bInt.isPositive), length(bInt.length) {}
//     BigInteger(BigInteger&& bInt) noexcept:nums(move(bInt.nums)), isPositive(bInt.isPositive), length(bInt.length) {}
//     BigInteger(const vector<int>& vec, bool sign = true):nums(vec), isPositive(sign) { cutLeadZero(); }

//     // 从输入流读取
//     friend istream& operator >>(istream& is, BigInteger& bInt)
//     {
//         string s;
//         is >> s;
//         bInt = move(BigInteger(s));
//         return is;
//     }
//     // 输出
//     friend ostream& operator <<(ostream& os, const BigInteger& bInt);
//     // 转换为string
//     operator string() const;
//     // 一元正号
//     const BigInteger& operator +() const { return *this; }
//     // 一元负号
//     BigInteger operator -() const
//     {
//         BigInteger tmp(*this);
//         if (!tmp.isZero())
//             tmp.isPositive = !isPositive;
//         return tmp;
//     }
//     // 比较运算符
//     bool operator <(const BigInteger& bInt) const;
//     bool operator <=(const BigInteger& bInt) const;
//     bool operator ==(const BigInteger& bInt) const;
//     // 算数运算符
//     BigInteger operator +(const BigInteger& bInt) const;
//     BigInteger operator -(const BigInteger& bInt) const;
//     BigInteger operator *(const BigInteger& bInt) const;
//     // 除法会返回 商和余数
//     pair<BigInteger, BigInteger> operator /(const BigInteger& bInt) const;
//     int operator[](int idx) const { return nums[idx]; }
//     // 赋值运算符
//     BigInteger& operator =(const BigInteger& bInt)
//     {
//         if (bInt == *this)
//             return *this;
//         nums = bInt.nums;
//         isPositive = bInt.isPositive;
//         length = bInt.length;
//         return *this;
//     }
//     BigInteger& operator =(BigInteger&& bInt)noexcept
//     {
//         nums = move(bInt.nums);
//         isPositive = bInt.isPositive;
//         length = bInt.length;
//         return *this;
//     }

//     size_t size() const { return nums.size(); }
//     void cutLeadZero();
//     bool isZero() const;
//     BigInteger absValue() const
//     {
//         return move(BigInteger(nums));
//     }
//     // 构造10^n n<=0会返回1
//     static BigInteger e(size_t n)
//     {
//         if (n <= 0)
//             return move(BigInteger(vector<int>(1, 1)));
//         int m = n / digit;
//         n -= m * digit;
//         vector<int> ans(m);
//         string s = "1";
//         s += move(string(n, '0'));
//         ans.push_back(stoi(s));
//         return move(BigInteger(ans));
//     }

// private:
//     // 低位到高位
//     vector<int> nums;
//     // 符号位
//     bool isPositive = 1;
//     // 位数
//     int length = 0;
//     // nums中的每一个元素代表digit位数据
//     static int digit;
//     static int mod;
// };

// int BigInteger::digit = 8;        // 8位
// int BigInteger::mod = 100000000; // 1e9 可能用mask会更好？

// BigInteger::BigInteger(const string& s)
// {
//     int n = s.size(), minIdx = 0;
//     if (s[0] == '-')
//         isPositive = false, minIdx = 1;
//     else if (s[0] == '+')
//         isPositive = true, minIdx = 1;
//     for (int i = n - 1; i >= minIdx; i -= digit)
//     {
//         int beg = max(minIdx, i - digit + 1);
//         nums.push_back(stoi(s.substr(beg, i - beg + 1)));
//     }
//     cutLeadZero();
// }

// ostream& operator <<(ostream& os, const BigInteger& bInt)
// {
//     os << (string)bInt;
//     return os;
// }

// BigInteger::operator string() const
// {
//     string ans;
//     if (!isPositive)
//         ans += "-";
//     int n = nums.size();
//     for (int i = n - 1; i >= 0; i--)
//     {
//         string s = to_string(nums[i]);
//         if (i != n - 1)
//             ans += string(digit - s.size(), '0');
//         ans += s;
//     }
//     return ans;
// }

// bool BigInteger::operator<(const BigInteger& bInt) const
// {
//     if (isPositive && !bInt.isPositive)
//         return false;
//     if (!isPositive && bInt.isPositive)
//         return true;
//     bool flag = true;
//     if (!isPositive)
//         flag = false; // 都为负数
//     if (length < bInt.length)
//         return flag;
//     else if (length > bInt.length)
//         return !flag;
//     int n = size();
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (nums[i] < bInt[i])
//             return flag;
//         else if (nums[i] > bInt[i])
//             return !flag;
//     }
//     return false;
// }

// bool BigInteger::operator<=(const BigInteger& bInt) const
// {
//     if (isPositive && !bInt.isPositive)
//         return false;
//     if (!isPositive && bInt.isPositive)
//         return true;
//     bool flag = true;
//     if (!isPositive)
//         flag = false; // 都为负数
//     if (length < bInt.length)
//         return flag;
//     else if (length > bInt.length)
//         return !flag;
//     int n = size();
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (nums[i] < bInt[i])
//             return flag;
//         else if (nums[i] > bInt[i])
//             return !flag;
//     }
//     return true;
// }

// bool BigInteger::operator==(const BigInteger& bInt) const
// {
//     if (length != bInt.length)
//         return false;
//     int n = size();
//     for (int i = 0; i < n; i++)
//         if (nums[i] != bInt[i])
//             return false;
//     return true;
// }

// BigInteger BigInteger::operator+(const BigInteger& bInt) const
// {
//     if (!bInt.isPositive)
//         return *this - (-bInt); // 加上负数 = 减去其绝对值
//     if (!isPositive)
//         return bInt - (-*this); // 负数+正数 = 整数-(-负数)
//     // 要么都正 要么都负
//     vector<int> ans;
//     int n = size(), m = bInt.size(), sum = 0, i = 0, j = 0;
//     while (i < n || j < m || sum)
//     {
//         if (i < n)
//             sum += nums[i++];
//         if (j < m)
//             sum += bInt[j++];
//         ans.push_back(sum % mod);
//         sum /= mod;
//     }
//     return move(BigInteger(ans, isPositive));
// }

// BigInteger BigInteger::operator-(const BigInteger& bInt) const
// {
//     if (!bInt.isPositive)
//         return *this + (-bInt); // 减去负数 = 加上其绝对值
//     if (!isPositive)
//         return -((-*this) + bInt); // 负数-正数 = -(-负数 + 正数)
//     if (*this < bInt)
//         return -(bInt - *this);
//     // 只计算大数减去小数
//     vector<int> ans;
//     int i = 0, j = 0, n = size(), m = bInt.size(), sum = 0;
//     while (i < n || j < m || sum)
//     {
//         if (i < n)
//             sum += nums[i++];
//         if (j < m)
//             sum -= bInt[j++];
//         int flag = 0;
//         if (sum < 0)
//         {
//             flag = -1;
//             sum += mod;
//         }
//         ans.push_back(sum);
//         sum = flag;
//     }
//     return move(BigInteger(ans));
// }

// BigInteger BigInteger::operator*(const BigInteger& bInt) const
// {
//     int n = size(), m = bInt.size();
//     vector<int> ans(n + m);
//     using ll = long long;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             ll tmp = ans[i + j] + nums[i] * 1ll * bInt[j];
//             ans[i + j] = tmp % mod;
//             ans[i + j + 1] += tmp / mod;
//         }
//     }
//     return move(BigInteger(ans, isPositive == bInt.isPositive));
// }

// pair<BigInteger, BigInteger> BigInteger::operator/(const BigInteger& bInt) const
// {
//     BigInteger a = absValue();
//     BigInteger b = bInt.absValue();
//     if (b.isZero())
//         return pair<BigInteger, BigInteger>(*this, move(b));
//     if (a < b)
//         return pair<BigInteger, BigInteger>(move(BigInteger(0)), *this);
//     int len = a.length - b.length + 1;
//     string ans;
//     if (isPositive != bInt.isPositive)
//         ans = "-";
//     for (int i = 0; i < len; i++)
//     {
//         BigInteger tmp = e(len - i - 1) * b;
//         int times = 0;
//         while (tmp <= a)
//         {
//             a = a - tmp;
//             ++times;
//         }
//         ans += times + '0';
//     }
//     a.isPositive = isPositive;
//     return pair<BigInteger, BigInteger>(move(BigInteger(ans)), move(a));
// }

// void BigInteger::cutLeadZero()
// {
//     while (nums.size() > 1 && nums.back() == 0)
//         nums.pop_back();
//     if (nums.empty())
//         length = 0;
//     else
//     {
//         length = (nums.size() - 1) * digit + to_string(nums.back()).size();
//     }
// }

// bool BigInteger::isZero() const
// {
//     return nums.size() == 1 && nums.back() == 0;
// }


// // 2023/04/25 14:25:23

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     BigInteger a(1), ans(1);
//     int n;
//     cin >> n;
//     for (int i = 2; i <= n; i++)
//     {
//         a = a * i;
//         ans = ans + a;
//     }
//     cout << ans << endl;

//     cout << flush;
//     return 0;
// }




// 2023/04/25 15:02:47
// void print(__int128 num)
// {
//     if (num)
//     {
//         print(num / 10);
//         cout.put(num % 10 + '0');
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n;
//     cin >> n;
//     __int128 a = 1;
//     __int128 ans = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         a *= i;
//         ans += a;
//     }
//     print(ans);

//     cout << flush;
//     return 0;
// }


// 2023/04/25 15:39:06

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cout << 54465 << endl;

    cout << flush;
    return 0;
}