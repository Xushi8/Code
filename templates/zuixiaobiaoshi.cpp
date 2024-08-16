#include <algorithm>
#include <vector>

using namespace std;

size_t zuixiaobiaoshi(vector<int> const& vec)
{
    auto tmp = vec;
    tmp.insert(tmp.end(), vec.begin(), vec.end());
    const size_t n = vec.size();
    size_t i, j;
    for (i = 0, j = 1; i < n && j < n;)
    {
        size_t k;
        for (k = 0; k < n && tmp[i + k] == tmp[j + k]; k++)
        {
        }
        if (tmp[i + k] > tmp[j + k])
            i = i + k + 1;
        else
            j = j + k + 1;
        if (i == j)
            j++;
    }
    return min(i, j);
}

void func(vector<int>& vec)
{
    size_t k = zuixiaobiaoshi(vec);
    rotate(vec.begin(), vec.begin() + k, vec.end());
}
