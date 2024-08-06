#include <map>

template <typename T = int>
struct union_find
{
    using reference = T&;
    using const_reference = T const&;

    union_find() noexcept = default;
    union_find(size_t n) noexcept :
        m_size(n)
    {
    }

    void resize(size_t n) noexcept
    {
        m_size = n;
        m_par.clear();
    }

    const_reference find(T const& x)
    {
        auto it = m_par.find(x);
        if (it == m_par.end())
        {
            m_par.emplace(x, x);
            return x;
        }
        if (it->second == x)
            return x;
        else
            return it->second = find(it->second);
    }

    void unite(T const& x, T const& y)
    {
        const_reference px = find(x);
        const_reference py = find(y);
        m_par[px] = py;
    }

    bool same(T const& x, T const& y)
    {
        return find(x) == find(y);
    }

private:
    size_t m_size;
    std::map<T, T> m_par;
};