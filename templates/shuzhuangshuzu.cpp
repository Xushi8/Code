int bit[N];
void add(int x, int val)
{
    for (int i = x; i < N; i += i & -i)
    {
        bit[i] += val;
    }
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
    {
        res += bit[i];
    }
    return res;
}

// 二维也仅仅是加了个 j
// 注意第二维必须重新初始化, 就像上面的一样