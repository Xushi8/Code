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

	const_reference find(T const& x)
	{
		auto it = par.find(x);
		if (it == par.end())
			return par[x] = x;
		if (it->second == x)
			return x;
		else
			return it->second = find(it->second);
	}

	void unite(T const& x, T const& y)
	{
		auto& px = find(x);
		auto& py = find(y);
		par[px] = py;
	}

	bool same(T const& x, T const& y)
	{
		return find(x) == find(y);
    }

private:
	size_t m_size;
	std::map<T, T> par;
};