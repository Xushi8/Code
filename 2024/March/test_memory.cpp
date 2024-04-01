#include <cstring>
#include <iostream>
#include <memory>
#include <string>

struct S
{
	std::string m{"默认值"};
};

int main()
{
	constexpr int n{3};
	alignas(alignof(S)) unsigned char mem[n * sizeof(S)];

	try
	{
		auto first{reinterpret_cast<S*>(mem)};
		auto last{first + n};

		std::uninitialized_default_construct(first, last);

		for (auto it{first}; it != last; ++it)
			std::cout << it->m << '\n';

		std::destroy(first, last);
	}
	catch (...)
	{
		std::cout << "异常！\n";
	}

	// 注意 uninitialized_default_construct 对于“平凡类型”
	// 通常不会以零填充未初始化的内存区域。
	int v[]{1, 2, 3, 4};
	const int original[]{1, 2, 3, 4};
	std::uninitialized_default_construct(std::begin(v), std::end(v));

	// 可能是未定义行为，等待 CWG 1997。
	// for (const int i : v)
	//     std::cout << i << ' ';

	int aaa[5];
	std::uninitialized_value_construct(std::begin(aaa), std::end(aaa));

	for (auto x : aaa)
		std::cout << x << ' ';

	// 结果未指定。
	std::cout << (std::memcmp(v, original, sizeof(v)) == 0 ? "未修改\n" : "已修改\n");
}