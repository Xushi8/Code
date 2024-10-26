#include <vector>
void func(int n, int m)
{
    std::vector<std::vector<int>> a(n, std::vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            a[i][j] = 1000;
        }
    }
}

int main()
{
}