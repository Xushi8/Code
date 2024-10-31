#include <vector>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int>& input, int k)
{
    // write code here

    // std::nth_element(input.begin(), input.begin() + k, input.end());
    // return vector<int>{input.begin(), input.begin() + k};

    if (k == input.size())
    {
        return input;
    }

    auto& a = input;

    auto my_nth_element = [&](auto&& self, int l, int k, int r) -> void
    {
        int pivot = a[l];
        int nl = l, nr = r - 1;
        while (1)
        {
            while (nl + 1 < r && a[nl] <= pivot)
            {
                nl++;
            }
            while (nr - 1 >= l && a[nr] >= pivot)
            {
                nr--;
            }
            if (nl < nr)
            {
                swap(a[nl], a[nr]);
                nl++;
                nr--;
            }
            else
            {
                break;
            }
        }

        swap(a[l], a[nr]);
        if (nl < k)
        {
            self(self, nl, k, r);
        }
        else if (nl > k)
        {
            self(self, l, k, nl);
        }
        else
        {
            return;
        }
    };

    my_nth_element(my_nth_element, 0, k, input.size());
    return std::vector<int>{a.begin(), a.begin() + k};
}

#include <fmt/ranges.h>
using fmt::print;

int main()
{
    vector<int> a{4, 5, 1, 6, 2, 7, 8, 3};
    vector<int> t = GetLeastNumbers_Solution(a, 8);

    print("{}\n", t);
}