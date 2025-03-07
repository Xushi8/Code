#include <vector>
#include <algorithm>
#include <iostream>

struct my_queue
{
    constexpr void push(int val)
    {
        m_data.emplace_back(val);
        size_t p = m_data.size() - 1;
        while (p != 0 && m_data[p] < m_data[far(p)])
        {
            std::swap(m_data[p], m_data[far(p)]);
            p = far(p);
        }
    }

    constexpr int top() noexcept
    {
        return m_data.front();
    }

    constexpr void pop() noexcept
    {
        std::swap(m_data.front(), m_data.back());
        m_data.pop_back();

        size_t p = 0;
        while (left(p) < m_data.size() && right(p) < m_data.size())
        {
            if (m_data[left(p)] < m_data[right(p)] && m_data[left(p)] < m_data[p])
            {
                std::swap(m_data[p], m_data[left(p)]);
                p = left(p);
            }
            else if (m_data[right(p)] < m_data[left(p)] && m_data[right(p)] < m_data[p])
            {
                std::swap(m_data[p], m_data[right(p)]);
                p = right(p);
            }
            else
            {
                break;
            }
        }

        while (left(p) < m_data.size())
        {
            if (m_data[p] > m_data[left(p)])
            {
                std::swap(m_data[p], m_data[left(p)]);
                p = left(p);
            }
            else
            {
                break;
            }
        }
    }

    constexpr size_t size() const noexcept
    {
        return m_data.size();
    }

    constexpr bool empty() const noexcept
    {
        return size() == 0;
    }

private:
    constexpr size_t far(size_t p)
    {
        return (p - 1) / 2;
    }

    constexpr size_t left(size_t p)
    {
        return (p * 2) + 1;
    }

    constexpr size_t right(size_t p)
    {
        return (p * 2) + 2;
    }

    std::vector<int> m_data;
};


int main()
{
    int n;
    std::cin >> n;
    my_queue que;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        que.push(x);
    }

    while (!que.empty())
    {
        int x = que.top();
        que.pop();
        std::cout << x << ' ';
    }
    std::cout << '\n';
}