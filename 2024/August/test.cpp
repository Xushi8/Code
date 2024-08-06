#include <iostream>
#include <vector>
#include <cstdint>

int MOD;

int qpow(int64_t a, size_t n)
{
    int64_t b = 1;
    while (n)
    {
        if (n & 1)
            b = b * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return b;
}

std::vector<int> fac, inv;

void init_inv(int n)
{
    n++;
    fac.resize(n);
    inv.resize(n);
    fac[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fac[i] = int64_t(fac[i - 1]) * i % MOD;
    }
    inv.back() = qpow(fac.back(), MOD - 2); // 使用费马小定理求逆元
    for (int i = n - 2; i > 0; i--)
    {
        inv[i] = int64_t(inv[i + 1]) * (i + 1) % MOD;
    }
    inv[0] = 1; // 特殊处理 inv[0]
}

int main()
{
    MOD = 1000000007; // 示例，MOD 必须是质数
    int n = 10;       // 示例，计算 0 到 n 的阶乘和逆元

    init_inv(n);

    // 打印结果进行验证
    std::cout << "Factorials: ";
    for (int i = 0; i <= n; ++i)
    {
        std::cout << fac[i] << " ";
    }
    std::cout << "\nInverses: ";
    for (int i = 0; i <= n; ++i)
    {
        std::cout << inv[i] << ' ' << int64_t(inv[i]) * i % MOD << '\n';
    }
    std::cout << std::endl;

    return 0;
}
