#include <algorithm>

template <class BidirectionalIter>
bool next_permutation(BidirectionalIter first, BidirectionalIter last)
{
    auto i = last;
    if (first == last || first == --i)
        return false;
    for (;;)
    {
        auto ii = i;
        if (*--i < *ii)
        { // 找到第一对小于关系的元素
            auto j = last;
            while (!(*i < *--j)) {}
            std::iter_swap(i, j);   // 交换 i，j 所指元素
            std::reverse(ii, last); // 将 ii 之后的所有元素反转
            return true;
        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}

template <class BidirectionalIter>
bool prev_permutation(BidirectionalIter first, BidirectionalIter last)
{
    auto i = last;
    if (first == last || first == --i)
        return false;
    for (;;)
    {
        auto ii = i;
        if (*ii < *--i)
        { // 找到第一对大于关系的元素
            auto j = last;
            while (!(*--j < *i)) {}
            std::iter_swap(i, j);   // 交换i，j
            std::reverse(ii, last); // 将 ii 之后的所有元素反转
            return true;
        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}