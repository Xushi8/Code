#include <algorithm>
#include <fmt/core.h>
#include <filesystem>
#include <execution>
#include <numeric>
using namespace std;
using fmt::print;
namespace fs = std::filesystem;

int main()
{
	const fs::path home("/usr");

	size_t siz = 0;
	// for (auto const& dir_entry : fs::recursive_directory_iterator(home))
	// {
	// 	// print("{}\n", dir_entry.path().string());
	// 	if (fs::is_regular_file(dir_entry))
	// 	{
	// 		// print("{} byte\n", dir_entry.file_size());
	// 		siz += dir_entry.file_size();
	// 	}
	// }

	// ranges::for_each(fs::recursive_directory_iterator(home), [&](auto const& dir_entry)
	// 	{
	// 		// print("{}\n", dir_entry.path().string());
	// 		if (fs::is_regular_file(dir_entry))
	// 		{
	// 			// print("{} byte\n", dir_entry.file_size());
	// 			siz += dir_entry.file_size();
	// 		}
	// 	});

	// ranges::for_each(std::execution::par, fs::recursive_directory_iterator(home), [&](auto const& dir_entry)
	// 	{
	// 		// print("{}\n", dir_entry.path().string());
	// 		if (fs::is_regular_file(dir_entry))
	// 		{
	// 			// print("{} byte\n", dir_entry.file_size());
	// 			siz += dir_entry.file_size();
	// 		}
	// 	});

	auto recursive_it = fs::recursive_directory_iterator(home);
	// for_each(std::execution::par, begin(recursive_it), end(recursive_it), [&](auto const& dir_entry)
	// 	{
	// 		// print("{}\n", dir_entry.path().string());
	// 		if (fs::is_regular_file(dir_entry))
	// 		{
	// 			// print("{} byte\n", dir_entry.file_size());
	// 			siz += dir_entry.file_size();
	// 		}
	// 	});

	vector<fs::path> paths;
	copy(begin(recursive_it), end(recursive_it), std::inserter(paths, paths.begin()));

	// for_each(std::execution::par, begin(paths), end(paths), [&](auto const& dir_entry)
	// 	{
	// 		siz += fs::is_regular_file(dir_entry) ? fs::file_size(dir_entry) : 0;
	// 	});

	siz = std::transform_reduce(std::execution::par_unseq, begin(paths), end(paths), siz, std::plus<>(), [&](auto const& dir_entry) -> size_t
		{
			return fs::is_regular_file(dir_entry) ? fs::file_size(dir_entry) : 0;
		});

	print("All size: {} bytes\n", siz);
	print("All size: {} kb\n", siz / 1024.L);
	print("All size: {} mb\n", siz / 1024.L / 1024);
	print("All size: {} gb\n", siz / 1024.L / 1024 / 1024);
}